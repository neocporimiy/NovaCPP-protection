#include "novacpp/packer.hpp"
#include "novacpp/common.hpp"

#include <array>
#include <cstring>
#include <random>

namespace novacpp {
namespace {

struct Entry {
    std::string path;
    std::vector<std::uint8_t> data;
};

std::uint64_t fnv1a(std::string_view s) {
    std::uint64_t h = 1469598103934665603ULL;
    for (unsigned char c : s) {
        h ^= c;
        h *= 1099511628211ULL;
    }
    return h;
}

std::uint64_t splitmix64(std::uint64_t& x) {
    std::uint64_t z = (x += 0x9e3779b97f4a7c15ULL);
    z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;
    z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;
    return z ^ (z >> 31);
}

std::vector<std::uint8_t> xorCrypt(const std::vector<std::uint8_t>& in, std::uint64_t key, std::uint64_t nonce) {
    std::vector<std::uint8_t> out(in.size());
    std::uint64_t s = key ^ (nonce * 0x9e3779b97f4a7c15ULL);
    std::uint64_t stream = 0;
    int remain = 0;
    for (std::size_t i = 0; i < in.size(); ++i) {
        if (remain == 0) {
            stream = splitmix64(s);
            remain = 8;
        }
        const auto b = static_cast<std::uint8_t>(stream & 0xFF);
        stream >>= 8;
        --remain;
        out[i] = static_cast<std::uint8_t>(in[i] ^ b);
    }
    return out;
}

template <typename T>
void appendLE(std::vector<std::uint8_t>& out, T v) {
    for (std::size_t i = 0; i < sizeof(T); ++i) out.push_back(static_cast<std::uint8_t>((v >> (8 * i)) & 0xFF));
}

template <typename T>
T readLE(const std::vector<std::uint8_t>& data, std::size_t& pos) {
    if (pos + sizeof(T) > data.size()) throw std::runtime_error("Corrupted package");
    T v = 0;
    for (std::size_t i = 0; i < sizeof(T); ++i) v |= static_cast<T>(data[pos++]) << (8 * i);
    return v;
}

std::vector<Entry> collectEntries(const fs::path& input) {
    std::vector<Entry> out;
    if (fs::is_regular_file(input)) {
        out.push_back({input.filename().string(), readBytes(input)});
        return out;
    }
    if (!fs::exists(input)) throw std::runtime_error("Pack input does not exist");
    for (const auto& e : fs::recursive_directory_iterator(input)) {
        if (!e.is_regular_file()) continue;
        auto rel = fs::relative(e.path(), input).generic_string();
        out.push_back({rel, readBytes(e.path())});
    }
    if (out.empty()) throw std::runtime_error("Nothing to pack");
    return out;
}

std::vector<std::uint8_t> serializeEntries(const std::vector<Entry>& entries) {
    std::vector<std::uint8_t> out;
    appendLE<std::uint32_t>(out, static_cast<std::uint32_t>(entries.size()));
    for (const auto& e : entries) {
        appendLE<std::uint32_t>(out, static_cast<std::uint32_t>(e.path.size()));
        out.insert(out.end(), e.path.begin(), e.path.end());
        appendLE<std::uint64_t>(out, static_cast<std::uint64_t>(e.data.size()));
        out.insert(out.end(), e.data.begin(), e.data.end());
    }
    return out;
}

std::vector<Entry> deserializeEntries(const std::vector<std::uint8_t>& data) {
    std::size_t pos = 0;
    const auto count = readLE<std::uint32_t>(data, pos);
    std::vector<Entry> out;
    out.reserve(count);
    for (std::uint32_t i = 0; i < count; ++i) {
        const auto pathLen = readLE<std::uint32_t>(data, pos);
        if (pos + pathLen > data.size()) throw std::runtime_error("Corrupted package");
        std::string path(reinterpret_cast<const char*>(data.data() + pos), pathLen);
        pos += pathLen;
        const auto size = readLE<std::uint64_t>(data, pos);
        if (pos + size > data.size()) throw std::runtime_error("Corrupted package");
        std::vector<std::uint8_t> bytes(data.begin() + static_cast<std::ptrdiff_t>(pos),
                                        data.begin() + static_cast<std::ptrdiff_t>(pos + size));
        pos += static_cast<std::size_t>(size);
        out.push_back({std::move(path), std::move(bytes)});
    }
    return out;
}

std::uint64_t computeMac(const std::vector<std::uint8_t>& data, std::uint64_t key, std::uint64_t nonce) {
    std::uint64_t h = key ^ (nonce * 0xD6E8FEB86659FD93ULL);
    for (std::uint8_t b : data) {
        h ^= b;
        h = (h << 5) | (h >> 59);
        h *= 0x9E3779B185EBCA87ULL;
    }
    return h;
}

}  // namespace

void packPath(const PackConfig& cfg) {
    if (cfg.password.empty()) throw std::runtime_error("Password is required for pack");
    const auto entries = collectEntries(cfg.inputPath);
    auto plain = serializeEntries(entries);
    const std::uint64_t nonce = std::random_device{}() ^ (static_cast<std::uint64_t>(std::random_device{}()) << 32);
    const std::uint64_t key = fnv1a(cfg.password) ^ 0xA5A5A5A5DEADBEEFULL;
    const auto cipher = xorCrypt(plain, key, nonce);
    const auto mac = computeMac(cipher, key, nonce);

    std::vector<std::uint8_t> file;
    const char magic[8] = {'N', 'V', 'P', 'K', 'G', '0', '1', '\0'};
    file.insert(file.end(), magic, magic + 8);
    appendLE<std::uint64_t>(file, nonce);
    appendLE<std::uint64_t>(file, mac);
    appendLE<std::uint64_t>(file, static_cast<std::uint64_t>(cipher.size()));
    file.insert(file.end(), cipher.begin(), cipher.end());
    writeBytes(cfg.outputFile, file);
}

void unpackFile(const UnpackConfig& cfg) {
    if (cfg.password.empty()) throw std::runtime_error("Password is required for unpack");
    auto data = readBytes(cfg.inputFile);
    std::size_t pos = 0;
    if (data.size() < 8 + 8 + 8 + 8) throw std::runtime_error("Invalid package");
    const std::array<char, 8> expect = {'N', 'V', 'P', 'K', 'G', '0', '1', '\0'};
    for (char c : expect) {
        if (data[pos++] != static_cast<std::uint8_t>(c)) throw std::runtime_error("Invalid package magic");
    }
    const auto nonce = readLE<std::uint64_t>(data, pos);
    const auto mac = readLE<std::uint64_t>(data, pos);
    const auto size = readLE<std::uint64_t>(data, pos);
    if (pos + size != data.size()) throw std::runtime_error("Invalid package payload size");
    std::vector<std::uint8_t> cipher(data.begin() + static_cast<std::ptrdiff_t>(pos), data.end());
    const std::uint64_t key = fnv1a(cfg.password) ^ 0xA5A5A5A5DEADBEEFULL;
    if (computeMac(cipher, key, nonce) != mac) throw std::runtime_error("Wrong password or corrupted package");
    const auto plain = xorCrypt(cipher, key, nonce);
    const auto entries = deserializeEntries(plain);
    fs::create_directories(cfg.outputDir);
    for (const auto& e : entries) {
        const auto out = cfg.outputDir / fs::path(e.path);
        writeBytes(out, e.data);
    }
}

}  // namespace novacpp
