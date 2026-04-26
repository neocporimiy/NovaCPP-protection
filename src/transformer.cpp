#include "novacpp/transformer.hpp"
#include "novacpp/common.hpp"

#include <regex>
#include <sstream>
#include <unordered_set>

namespace novacpp {

namespace {

constexpr std::string_view kRuntime = R"(// ===== NovaCPP Runtime (auto) =====
#include <string>
#include <cstdint>
#include <cstddef>
#include <cstdlib>
namespace novacpp_rt {
inline std::string dec(const unsigned char* data, std::size_t n, unsigned char key) {
    if (n == 0) return std::string();
    std::string out;
    out.resize(n - 1);
    for (std::size_t i = 0; i + 1 < n; ++i) out[i] = static_cast<char>(data[i] ^ key);
    return out;
}
inline std::uint64_t mix(std::uint64_t x) {
    x ^= x >> 30;
    x *= 0xbf58476d1ce4e5b9ULL;
    x ^= x >> 27;
    x *= 0x94d049bb133111ebULL;
    x ^= x >> 31;
    return x;
}
}
// ===== /NovaCPP Runtime =====
)";

std::string insertRuntime(const std::string& code) {
    if (code.find("namespace novacpp_rt") != std::string::npos) return code;
    std::size_t lastEnd = 0;
    std::size_t start = 0;
    while (start < code.size()) {
        std::size_t end = code.find('\n', start);
        if (end == std::string::npos) end = code.size();
        const auto line = code.substr(start, end - start);
        std::size_t p = 0;
        while (p < line.size() && std::isspace(static_cast<unsigned char>(line[p]))) ++p;
        if (p < line.size() && line[p] == '#') {
            ++p;
            while (p < line.size() && std::isspace(static_cast<unsigned char>(line[p]))) ++p;
            if (line.compare(p, 7, "include") == 0) lastEnd = end;
        }
        if (end == code.size()) break;
        start = end + 1;
    }
    if (lastEnd == 0) return std::string(kRuntime) + "\n" + code;
    std::string out = code;
    out.insert(lastEnd, "\n" + std::string(kRuntime) + "\n");
    return out;
}

std::string obfuscateStrings(const std::string& code, std::mt19937_64& rng, ProtectStats& st) {
    std::string out;
    out.reserve(code.size() * 2);
    std::uniform_int_distribution<int> keyDist(1, 255);
    std::size_t i = 0, idx = 0;
    while (i < code.size()) {
        if (code[i] != '"') {
            out.push_back(code[i++]);
            continue;
        }
        std::size_t j = i + 1;
        bool esc = false;
        while (j < code.size()) {
            if (!esc && code[j] == '"') {
                ++j;
                break;
            }
            if (!esc && code[j] == '\\') esc = true;
            else esc = false;
            ++j;
        }
        if (j <= i + 1) {
            out += "\"\"";
            i = j;
            continue;
        }
        const auto token = code.substr(i + 1, j - i - 2);
        if (token.empty()) {
            out += "\"\"";
            i = j;
            continue;
        }
        const int key = keyDist(rng);
        std::ostringstream arr;
        for (std::size_t k = 0; k < token.size(); ++k) {
            if (k) arr << ", ";
            arr << hexByte(static_cast<std::uint8_t>(static_cast<unsigned char>(token[k]) ^ key));
        }
        arr << ", " << hexByte(static_cast<std::uint8_t>(key));
        std::ostringstream rep;
        rep << "([](){ static const unsigned char __nv_s_" << idx << "[]={" << arr.str() << "}; "
            << "static std::string __nv_s_" << idx << "_d = novacpp_rt::dec(__nv_s_" << idx
            << ", sizeof(__nv_s_" << idx << "), " << hexByte(static_cast<std::uint8_t>(key))
            << "); return __nv_s_" << idx << "_d.c_str(); }())";
        out += rep.str();
        st.strings++;
        idx++;
        i = j;
    }
    return out;
}

std::string obfuscateInts(const std::string& code, std::mt19937_64& rng, ProtectStats& st) {
    std::string out;
    out.reserve(code.size() + code.size() / 4);
    std::uniform_int_distribution<std::uint32_t> dkey(1, 0x3fffffffU);
    auto isWord = [](char c) {
        return std::isalnum(static_cast<unsigned char>(c)) || c == '_' || c == '.';
    };
    std::size_t i = 0;
    while (i < code.size()) {
        if (!std::isdigit(static_cast<unsigned char>(code[i]))) {
            out.push_back(code[i++]);
            continue;
        }
        const char prev = (i == 0) ? '\0' : code[i - 1];
        if (isWord(prev)) {
            out.push_back(code[i++]);
            continue;
        }
        std::size_t j = i;
        while (j < code.size() && std::isdigit(static_cast<unsigned char>(code[j]))) ++j;
        const char next = (j < code.size()) ? code[j] : '\0';
        if (isWord(next)) {
            out.append(code, i, j - i);
            i = j;
            continue;
        }
        std::uint64_t value = 0;
        try {
            value = std::stoull(code.substr(i, j - i));
        } catch (...) {
            value = 0;
        }
        if (value >= 3 && value <= 0x7fffffffULL) {
            const auto key = dkey(rng);
            const auto enc = static_cast<std::uint32_t>(value) ^ key;
            out += "((" + std::to_string(enc) + " ^ " + std::to_string(key) + "))";
            st.ints++;
        } else {
            out.append(code, i, j - i);
        }
        i = j;
    }
    return out;
}

std::string mutateFunctions(const std::string& code, std::mt19937_64& rng, int level, ProtectStats& st) {
    std::vector<std::size_t> inserts;
    for (std::size_t i = 1; i + 1 < code.size(); ++i) {
        if (code[i] != '{') continue;
        std::size_t p = i;
        while (p > 0 && std::isspace(static_cast<unsigned char>(code[p - 1]))) --p;
        if (p > 0 && code[p - 1] == ')') inserts.push_back(i);
    }
    std::string out = code;
    std::sort(inserts.begin(), inserts.end(), std::greater<std::size_t>());
    for (auto pos : inserts) {
        std::ostringstream blk;
        for (int i = 0; i < level; ++i) {
            const auto seed = rng();
            blk << "\n    volatile std::uint64_t __nv_state_" << i
                << " = novacpp_rt::mix(0x" << std::hex << std::uppercase << seed << std::dec
                << "ULL ^ (std::uint64_t)__LINE__);\n"
                << "    if (((__nv_state_" << i << " & 7ULL) == 9ULL)) { std::abort(); }\n";
            st.mutations++;
        }
        out.insert(pos + 1, blk.str());
    }
    return out;
}

std::string renameLocals(const std::string& code, std::mt19937_64& rng, ProtectStats& st) {
    static const std::regex declRe(
        R"(\b(int|long|short|float|double|char|bool|std::string|std::uint64_t|std::int64_t)\s+([A-Za-z_][A-Za-z0-9_]*))");
    std::unordered_set<std::string> names;
    for (auto it = std::sregex_iterator(code.begin(), code.end(), declRe); it != std::sregex_iterator(); ++it) {
        names.insert((*it).str(2));
    }
    std::vector<std::string> sorted(names.begin(), names.end());
    std::sort(sorted.begin(), sorted.end(), [](const auto& a, const auto& b) { return a.size() > b.size(); });
    std::string out = code;
    for (const auto& oldName : sorted) {
        std::ostringstream nn;
        nn << "__nv_" << std::hex << (rng() & 0xffffffffULL);
        const std::regex idRe("\\b" + oldName + "\\b");
        const auto replaced = std::regex_replace(out, idRe, nn.str());
        if (replaced != out) st.renames++;
        out = replaced;
    }
    return out;
}

}  // namespace

std::string protectSource(const std::string& input, std::mt19937_64& rng, const ProtectConfig& cfg, ProtectStats& stats) {
    auto out = obfuscateStrings(input, rng, stats);
    if (cfg.enableIntObf) out = obfuscateInts(out, rng, stats);
    out = mutateFunctions(out, rng, cfg.mutationLevel, stats);
    if (cfg.enableRename) out = renameLocals(out, rng, stats);
    if (stats.strings || stats.mutations) out = insertRuntime(out);
    return out;
}

ProtectStats protectPath(const ProtectConfig& cfg) {
    ProtectStats total{};
    std::mt19937_64 rng(cfg.seed ? cfg.seed : std::random_device{}());
    if (fs::is_regular_file(cfg.inputPath)) {
        if (!hasCppExt(cfg.inputPath)) throw std::runtime_error("Input file is not C/C++ source/header");
        auto src = readText(cfg.inputPath);
        ProtectStats one{};
        const auto out = protectSource(src, rng, cfg, one);
        writeText(cfg.outputPath, out);
        one.files = 1;
        return one;
    }
    if (!fs::exists(cfg.inputPath)) throw std::runtime_error("Input path does not exist");
    fs::create_directories(cfg.outputPath);
    for (const auto& e : fs::recursive_directory_iterator(cfg.inputPath)) {
        if (!e.is_regular_file()) continue;
        const auto rel = fs::relative(e.path(), cfg.inputPath);
        const auto outPath = cfg.outputPath / rel;
        if (hasCppExt(e.path())) {
            auto src = readText(e.path());
            ProtectStats one{};
            auto out = protectSource(src, rng, cfg, one);
            writeText(outPath, out);
            total.files++;
            total.strings += one.strings;
            total.ints += one.ints;
            total.mutations += one.mutations;
            total.renames += one.renames;
        } else {
            fs::create_directories(outPath.parent_path());
            fs::copy_file(e.path(), outPath, fs::copy_options::overwrite_existing);
        }
    }
    if (!total.files) throw std::runtime_error("No C/C++ files found in input directory");
    return total;
}

}  // namespace novacpp
