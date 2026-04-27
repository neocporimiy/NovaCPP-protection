#include "novacpp/packer.hpp"
#include "novacpp/common.hpp"

#include <algorithm>
#include <array>
#include <cctype>
#include <cstring>
#include <random>

namespace novacpp {
namespace {

struct Entry {
    std::string path;
    std::vector<std::uint8_t> data;
};

struct KeyMaterial {
    std::uint64_t enc = 0;
    std::uint64_t macA = 0;
    std::uint64_t macB = 0;
};

constexpr std::array<char, 8> kMagicV1 = {'N', 'V', 'P', 'K', 'G', '0', '1', '\0'};
constexpr std::array<char, 8> kMagicV2 = {'N', 'V', 'P', 'K', 'G', '0', '2', '\0'};
constexpr std::uint32_t kMinKdfRounds = 50000;

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

std::uint64_t rotl64(std::uint64_t v, int r) {
    return (v << r) | (v >> (64 - r));
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

bool matchesMagic(const std::vector<std::uint8_t>& data, const std::array<char, 8>& magic) {
    if (data.size() < magic.size()) return false;
    for (std::size_t i = 0; i < magic.size(); ++i) {
        if (data[i] != static_cast<std::uint8_t>(magic[i])) return false;
    }
    return true;
}

std::string normalizeArchivePath(const fs::path& path) {
    const auto normalized = path.lexically_normal();
    if (normalized.empty()) throw std::runtime_error("Empty entry path");
    if (normalized.is_absolute() || normalized.has_root_name() || normalized.has_root_directory()) {
        throw std::runtime_error("Absolute paths are not allowed in package entries");
    }
    std::string out;
    for (const auto& part : normalized) {
        const auto item = part.generic_string();
        if (item.empty() || item == ".") continue;
        if (item == "..") throw std::runtime_error("Parent traversal is not allowed in package entries");
        if (!out.empty()) out += '/';
        out += item;
    }
    if (out.empty()) throw std::runtime_error("Invalid entry path");
    return out;
}

bool pathPartEqual(const fs::path& a, const fs::path& b) {
#ifdef _WIN32
    return toLower(a.generic_string()) == toLower(b.generic_string());
#else
    return a.generic_string() == b.generic_string();
#endif
}

bool isSubPath(const fs::path& base, const fs::path& target) {
    const auto b = base.lexically_normal();
    const auto t = target.lexically_normal();
    auto bi = b.begin();
    auto ti = t.begin();
    for (; bi != b.end(); ++bi, ++ti) {
        if (ti == t.end()) return false;
        if (!pathPartEqual(*bi, *ti)) return false;
    }
    return true;
}

fs::path secureOutputPath(const fs::path& baseAbs, const std::string& entryPath) {
    const auto rel = fs::path(normalizeArchivePath(entryPath));
    const auto out = (baseAbs / rel).lexically_normal();
    if (!isSubPath(baseAbs, out)) throw std::runtime_error("Blocked unsafe unpack path: " + rel.generic_string());
    return out;
}

std::vector<Entry> collectEntries(const fs::path& input) {
    std::vector<Entry> out;
    if (fs::is_regular_file(input)) {
        out.push_back({normalizeArchivePath(input.filename()), readBytes(input)});
        return out;
    }
    if (!fs::exists(input)) throw std::runtime_error("Pack input does not exist");
    for (const auto& e : fs::recursive_directory_iterator(input)) {
        if (!e.is_regular_file()) continue;
        auto rel = fs::relative(e.path(), input);
        out.push_back({normalizeArchivePath(rel), readBytes(e.path())});
    }
    if (out.empty()) throw std::runtime_error("Nothing to pack");
    std::sort(out.begin(), out.end(), [](const Entry& a, const Entry& b) { return a.path < b.path; });
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
        const auto pathLen = static_cast<std::size_t>(readLE<std::uint32_t>(data, pos));
        if (pos + pathLen > data.size()) throw std::runtime_error("Corrupted package");
        std::string path(reinterpret_cast<const char*>(data.data() + pos), pathLen);
        pos += pathLen;

        const auto size64 = readLE<std::uint64_t>(data, pos);
        if (size64 > static_cast<std::uint64_t>(data.size() - pos)) throw std::runtime_error("Corrupted package");
        const auto size = static_cast<std::size_t>(size64);
        std::vector<std::uint8_t> bytes(data.begin() + static_cast<std::ptrdiff_t>(pos),
                                        data.begin() + static_cast<std::ptrdiff_t>(pos + size));
        pos += size;
        out.push_back({normalizeArchivePath(path), std::move(bytes)});
    }
    if (pos != data.size()) throw std::runtime_error("Corrupted package trailing data");
    return out;
}

KeyMaterial deriveKeysV2(const std::string& password, std::uint64_t salt, std::uint32_t rounds) {
    if (password.empty()) throw std::runtime_error("Password is required");
    if (rounds < kMinKdfRounds) throw std::runtime_error("KDF rounds must be >= 50000");

    std::uint64_t state = fnv1a(password) ^ 0x243F6A8885A308D3ULL ^ salt;
    for (unsigned char c : password) {
        state ^= static_cast<std::uint64_t>(c) + 0x9E3779B97F4A7C15ULL + (state << 6) + (state >> 2);
        state = splitmix64(state);
    }
    for (std::uint32_t i = 0; i < rounds; ++i) {
        state ^= salt + (0x9E3779B185EBCA87ULL * static_cast<std::uint64_t>(i + 1));
        state = splitmix64(state);
        state ^= rotl64(state, static_cast<int>((i % 23U) + 3U));
    }

    KeyMaterial km;
    km.enc = splitmix64(state) ^ 0xA5A5A5A5DEADBEEFULL;
    km.macA = splitmix64(state) ^ 0xD6E8FEB86659FD93ULL;
    km.macB = splitmix64(state) ^ 0x9E3779B185EBCA87ULL;
    return km;
}

std::uint64_t computeMacV1(const std::vector<std::uint8_t>& data, std::uint64_t key, std::uint64_t nonce) {
    std::uint64_t h = key ^ (nonce * 0xD6E8FEB86659FD93ULL);
    for (std::uint8_t b : data) {
        h ^= b;
        h = (h << 5) | (h >> 59);
        h *= 0x9E3779B185EBCA87ULL;
    }
    return h;
}

std::array<std::uint64_t, 2> computeMacV2(const std::vector<std::uint8_t>& data,
                                          std::uint64_t macA,
                                          std::uint64_t macB,
                                          std::uint64_t nonce) {
    std::uint64_t h1 = macA ^ (nonce * 0xD6E8FEB86659FD93ULL);
    std::uint64_t h2 = macB ^ rotl64(nonce ^ 0x9E3779B185EBCA87ULL, 17);
    for (std::uint8_t b : data) {
        h1 ^= b;
        h1 = rotl64(h1, 7);
        h1 *= 0x9E3779B185EBCA87ULL;

        h2 += static_cast<std::uint64_t>(b) + 0x9DU;
        h2 ^= h1;
        h2 = rotl64(h2, 11);
        h2 *= 0xC2B2AE3D27D4EB4FULL;
    }
    h1 ^= splitmix64(h2);
    h2 ^= splitmix64(h1);
    return {h1, h2};
}

}  // namespace

void packPath(const PackConfig& cfg) {
    if (cfg.password.empty()) throw std::runtime_error("Password is required for pack");
    if (cfg.password.size() < 10) throw std::runtime_error("Password must be at least 10 chars for hardened mode");

    const auto entries = collectEntries(cfg.inputPath);
    const auto plain = serializeEntries(entries);

    const std::uint64_t salt = (static_cast<std::uint64_t>(std::random_device{}()) << 32) ^
                               static_cast<std::uint64_t>(std::random_device{}());
    const std::uint64_t nonce = (static_cast<std::uint64_t>(std::random_device{}()) << 32) ^
                                static_cast<std::uint64_t>(std::random_device{}());
    const auto keys = deriveKeysV2(cfg.password, salt, cfg.kdfRounds);

    const auto cipher = xorCrypt(plain, keys.enc, nonce);
    const auto mac = computeMacV2(cipher, keys.macA, keys.macB, nonce);

    std::vector<std::uint8_t> file;
    file.insert(file.end(), kMagicV2.begin(), kMagicV2.end());
    appendLE<std::uint64_t>(file, salt);
    appendLE<std::uint64_t>(file, nonce);
    appendLE<std::uint32_t>(file, cfg.kdfRounds);
    appendLE<std::uint32_t>(file, 0U);
    appendLE<std::uint64_t>(file, mac[0]);
    appendLE<std::uint64_t>(file, mac[1]);
    appendLE<std::uint64_t>(file, static_cast<std::uint64_t>(cipher.size()));
    file.insert(file.end(), cipher.begin(), cipher.end());

    writeBytes(cfg.outputFile, file);
}

void unpackFile(const UnpackConfig& cfg) {
    if (cfg.password.empty()) throw std::runtime_error("Password is required for unpack");

    const auto data = readBytes(cfg.inputFile);
    if (data.size() < 8 + 8 + 8 + 8) throw std::runtime_error("Invalid package");

    std::size_t pos = 0;
    std::vector<std::uint8_t> cipher;
    std::uint64_t nonce = 0;
    std::uint64_t macV1 = 0;
    std::array<std::uint64_t, 2> macV2 = {0, 0};
    KeyMaterial keys{};

    if (matchesMagic(data, kMagicV2)) {
        pos = kMagicV2.size();
        if (data.size() < pos + 8 + 8 + 4 + 4 + 8 + 8 + 8) throw std::runtime_error("Invalid package header");

        const auto salt = readLE<std::uint64_t>(data, pos);
        nonce = readLE<std::uint64_t>(data, pos);
        const auto rounds = readLE<std::uint32_t>(data, pos);
        (void)readLE<std::uint32_t>(data, pos);
        macV2[0] = readLE<std::uint64_t>(data, pos);
        macV2[1] = readLE<std::uint64_t>(data, pos);
        const auto size = readLE<std::uint64_t>(data, pos);
        if (size > static_cast<std::uint64_t>(data.size() - pos)) throw std::runtime_error("Invalid package payload size");
        if (pos + static_cast<std::size_t>(size) != data.size()) throw std::runtime_error("Invalid package payload size");

        keys = deriveKeysV2(cfg.password, salt, rounds);
        cipher.assign(data.begin() + static_cast<std::ptrdiff_t>(pos), data.end());
        if (computeMacV2(cipher, keys.macA, keys.macB, nonce) != macV2) {
            throw std::runtime_error("Wrong password or corrupted package");
        }
    } else if (matchesMagic(data, kMagicV1)) {
        // Legacy package support.
        pos = kMagicV1.size();
        nonce = readLE<std::uint64_t>(data, pos);
        macV1 = readLE<std::uint64_t>(data, pos);
        const auto size = readLE<std::uint64_t>(data, pos);
        if (size > static_cast<std::uint64_t>(data.size() - pos)) throw std::runtime_error("Invalid package payload size");
        if (pos + static_cast<std::size_t>(size) != data.size()) throw std::runtime_error("Invalid package payload size");

        keys.enc = fnv1a(cfg.password) ^ 0xA5A5A5A5DEADBEEFULL;
        cipher.assign(data.begin() + static_cast<std::ptrdiff_t>(pos), data.end());
        if (computeMacV1(cipher, keys.enc, nonce) != macV1) {
            throw std::runtime_error("Wrong password or corrupted package");
        }
    } else {
        throw std::runtime_error("Invalid package magic");
    }

    const auto plain = xorCrypt(cipher, keys.enc, nonce);
    const auto entries = deserializeEntries(plain);

    fs::create_directories(cfg.outputDir);
    const auto baseAbs = fs::weakly_canonical(cfg.outputDir);
    for (const auto& e : entries) {
        const auto out = secureOutputPath(baseAbs, e.path);
        writeBytes(out, e.data);
    }
}

}  // namespace novacpp
