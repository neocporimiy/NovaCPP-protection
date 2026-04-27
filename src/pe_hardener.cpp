#include "novacpp/pe_hardener.hpp"
#include "novacpp/common.hpp"

#include <array>
#include <random>
#include <stdexcept>

namespace novacpp {
namespace {

constexpr std::uint16_t kMzSignature = 0x5A4D;
constexpr std::uint32_t kPeSignature = 0x00004550;
constexpr std::size_t kDosLfaNewOffset = 0x3C;
constexpr std::size_t kCoffHeaderSize = 20;
constexpr std::size_t kSectionHeaderSize = 40;

std::uint16_t readU16(const std::vector<std::uint8_t>& data, std::size_t off) {
    if (off + 2 > data.size()) throw std::runtime_error("PE parse out of range");
    return static_cast<std::uint16_t>(data[off]) |
           (static_cast<std::uint16_t>(data[off + 1]) << 8);
}

std::uint32_t readU32(const std::vector<std::uint8_t>& data, std::size_t off) {
    if (off + 4 > data.size()) throw std::runtime_error("PE parse out of range");
    return static_cast<std::uint32_t>(data[off]) |
           (static_cast<std::uint32_t>(data[off + 1]) << 8) |
           (static_cast<std::uint32_t>(data[off + 2]) << 16) |
           (static_cast<std::uint32_t>(data[off + 3]) << 24);
}

void requireRange(std::size_t off, std::size_t len, std::size_t total, const char* message) {
    if (off > total || len > total - off) throw std::runtime_error(message);
}

std::array<std::uint8_t, 8> makeSectionName(std::mt19937_64& rng, bool zeroNames) {
    std::array<std::uint8_t, 8> out{};
    if (zeroNames) return out;
    static constexpr char kAlphabet[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    std::uniform_int_distribution<std::size_t> dist(0, sizeof(kAlphabet) - 2);
    for (auto& b : out) b = static_cast<std::uint8_t>(kAlphabet[dist(rng)]);
    return out;
}

}  // namespace

PeSectionScrubStats scrubPeSectionNames(const PeSectionScrubConfig& cfg) {
    if (cfg.inputFile.empty()) throw std::runtime_error("pe-scrub requires input file");

    auto data = readBytes(cfg.inputFile);
    if (data.size() < 64) throw std::runtime_error("Input is too small to be a PE file");
    if (readU16(data, 0) != kMzSignature) throw std::runtime_error("Not a PE file: missing MZ header");

    const auto peOff = static_cast<std::size_t>(readU32(data, kDosLfaNewOffset));
    requireRange(peOff, 4 + kCoffHeaderSize, data.size(), "Invalid PE header offset");
    if (readU32(data, peOff) != kPeSignature) throw std::runtime_error("Not a PE file: missing PE signature");

    const auto coffOff = peOff + 4;
    const auto numberOfSections = static_cast<std::size_t>(readU16(data, coffOff + 2));
    const auto sizeOfOptionalHeader = static_cast<std::size_t>(readU16(data, coffOff + 16));
    if (numberOfSections == 0) throw std::runtime_error("PE has zero sections");

    const auto sectionTableOff = coffOff + kCoffHeaderSize + sizeOfOptionalHeader;
    requireRange(sectionTableOff, numberOfSections * kSectionHeaderSize, data.size(), "Invalid section table");

    std::mt19937_64 rng(cfg.seed ? cfg.seed : (static_cast<std::uint64_t>(std::random_device{}()) << 32) ^
                                           static_cast<std::uint64_t>(std::random_device{}()));
    for (std::size_t i = 0; i < numberOfSections; ++i) {
        const auto sectionOff = sectionTableOff + (i * kSectionHeaderSize);
        const auto name = makeSectionName(rng, cfg.zeroNames);
        for (std::size_t b = 0; b < name.size(); ++b) data[sectionOff + b] = name[b];
    }

    const auto outputFile = cfg.outputFile.empty() ? cfg.inputFile : cfg.outputFile;
    writeBytes(outputFile, data);
    return PeSectionScrubStats{numberOfSections};
}

}  // namespace novacpp
