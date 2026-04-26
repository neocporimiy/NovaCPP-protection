#pragma once

#include <filesystem>
#include <string>

namespace novacpp {

struct PackConfig {
    std::filesystem::path inputPath;
    std::filesystem::path outputFile;
    std::string password;
};

struct UnpackConfig {
    std::filesystem::path inputFile;
    std::filesystem::path outputDir;
    std::string password;
};

void packPath(const PackConfig& cfg);
void unpackFile(const UnpackConfig& cfg);

}  // namespace novacpp
