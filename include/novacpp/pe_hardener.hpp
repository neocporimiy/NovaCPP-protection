#pragma once

#include <cstddef>
#include <cstdint>
#include <filesystem>

namespace novacpp {

struct PeSectionScrubConfig {
    std::filesystem::path inputFile;
    std::filesystem::path outputFile;
    std::uint64_t seed = 0;
    bool zeroNames = false;
};

struct PeSectionScrubStats {
    std::size_t sections = 0;
};

PeSectionScrubStats scrubPeSectionNames(const PeSectionScrubConfig& cfg);

}  // namespace novacpp
