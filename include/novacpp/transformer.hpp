#pragma once

#include <cstdint>
#include <filesystem>
#include <random>
#include <string>

namespace novacpp {

struct ProtectConfig {
    std::filesystem::path inputPath;
    std::filesystem::path outputPath;
    std::uint64_t seed = 0;
    int mutationLevel = 6;
    bool enableIntObf = true;
    bool enableRename = true;
    bool ultraMode = false;
};

struct ProtectStats {
    std::size_t files = 0;
    std::size_t strings = 0;
    std::size_t ints = 0;
    std::size_t mutations = 0;
    std::size_t renames = 0;
};

std::string protectSource(const std::string& input, std::mt19937_64& rng, const ProtectConfig& cfg, ProtectStats& stats);
ProtectStats protectPath(const ProtectConfig& cfg);

}  // namespace novacpp
