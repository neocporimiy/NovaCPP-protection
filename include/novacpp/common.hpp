#pragma once

#include <algorithm>
#include <cctype>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

namespace novacpp {
namespace fs = std::filesystem;

inline std::string readText(const fs::path& p) {
    std::ifstream in(p, std::ios::binary);
    if (!in) throw std::runtime_error("Cannot open file: " + p.string());
    std::ostringstream ss;
    ss << in.rdbuf();
    return ss.str();
}

inline std::vector<std::uint8_t> readBytes(const fs::path& p) {
    std::ifstream in(p, std::ios::binary);
    if (!in) throw std::runtime_error("Cannot open file: " + p.string());
    in.seekg(0, std::ios::end);
    const auto size = static_cast<std::size_t>(in.tellg());
    in.seekg(0, std::ios::beg);
    std::vector<std::uint8_t> data(size);
    if (size) in.read(reinterpret_cast<char*>(data.data()), static_cast<std::streamsize>(size));
    return data;
}

inline void writeText(const fs::path& p, const std::string& s) {
    fs::create_directories(p.parent_path());
    std::ofstream out(p, std::ios::binary);
    if (!out) throw std::runtime_error("Cannot write file: " + p.string());
    out << s;
}

inline void writeBytes(const fs::path& p, const std::vector<std::uint8_t>& data) {
    fs::create_directories(p.parent_path());
    std::ofstream out(p, std::ios::binary);
    if (!out) throw std::runtime_error("Cannot write file: " + p.string());
    if (!data.empty()) out.write(reinterpret_cast<const char*>(data.data()), static_cast<std::streamsize>(data.size()));
}

inline std::string toLower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return s;
}

inline bool hasCppExt(const fs::path& p) {
    const static std::vector<std::string> exts = {".cpp", ".cc", ".cxx", ".hpp", ".hh", ".hxx", ".h"};
    const auto e = toLower(p.extension().string());
    return std::find(exts.begin(), exts.end(), e) != exts.end();
}

inline std::string hexByte(std::uint8_t v) {
    static const char* h = "0123456789ABCDEF";
    std::string s = "0x00";
    s[2] = h[(v >> 4) & 0xF];
    s[3] = h[v & 0xF];
    return s;
}

}  // namespace novacpp
