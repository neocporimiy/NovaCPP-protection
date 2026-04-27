#include "novacpp/packer.hpp"
#include "novacpp/pe_hardener.hpp"
#include "novacpp/transformer.hpp"

#include <algorithm>
#include <chrono>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <string>

namespace {

namespace fs = std::filesystem;

void printHelp() {
    std::cout
        << "NovaCPP usage:\n"
        << "  novacpp protect --in <file|dir> --out <file|dir> [--seed N] [--mutation-level N]\n"
        << "                  [--no-int-obf] [--no-rename] [--max] [--ultra]\n"
        << "  novacpp pack    --in <file|dir> --out <file.nvp> --password <pwd> [--kdf-rounds N]\n"
        << "  novacpp unpack  --in <file.nvp> --out <dir> --password <pwd>\n"
        << "  novacpp pe-scrub --in <file.exe|file.dll> [--out <file>] [--seed N] [--zero-names]\n"
        << "  novacpp armor   --in <file|dir> --out <file.nvp> --password <pwd> [--tmp <dir>]\n"
        << "                  [--kdf-rounds N] [protect-options]\n"
        << "\n"
        << "Example one-shot hardening:\n"
        << "  novacpp armor --in samples/demo.cpp --out out/demo.nvp --password \"StrongPass2026!\" --ultra\n";
}

std::string needValue(int& i, int argc, char** argv, const char* name) {
    if (i + 1 >= argc) throw std::runtime_error(std::string("Missing value for ") + name);
    return argv[++i];
}

void applyProtectPreset(novacpp::ProtectConfig& cfg, bool forceMax, bool ultra) {
    if (forceMax) {
        cfg.mutationLevel = 8;
        cfg.enableIntObf = true;
        cfg.enableRename = true;
    }
    if (ultra) {
        cfg.ultraMode = true;
        cfg.mutationLevel = std::max(cfg.mutationLevel, 14);
        cfg.enableIntObf = true;
        cfg.enableRename = true;
    }
}

bool parseProtectTuningArg(const std::string& a,
                           int& i,
                           int argc,
                           char** argv,
                           novacpp::ProtectConfig& cfg,
                           bool& forceMax,
                           bool& ultra) {
    if (a == "--seed") {
        cfg.seed = std::stoull(needValue(i, argc, argv, "--seed"));
        return true;
    }
    if (a == "--mutation-level") {
        cfg.mutationLevel = std::stoi(needValue(i, argc, argv, "--mutation-level"));
        return true;
    }
    if (a == "--no-int-obf") {
        cfg.enableIntObf = false;
        return true;
    }
    if (a == "--no-rename") {
        cfg.enableRename = false;
        return true;
    }
    if (a == "--max") {
        forceMax = true;
        return true;
    }
    if (a == "--ultra") {
        ultra = true;
        return true;
    }
    return false;
}

int cmdProtect(int argc, char** argv) {
    novacpp::ProtectConfig cfg{};
    bool hasIn = false;
    bool hasOut = false;
    bool forceMax = false;
    bool ultra = false;

    for (int i = 2; i < argc; ++i) {
        const std::string a = argv[i];
        if (a == "--in") {
            cfg.inputPath = needValue(i, argc, argv, "--in");
            hasIn = true;
            continue;
        }
        if (a == "--out") {
            cfg.outputPath = needValue(i, argc, argv, "--out");
            hasOut = true;
            continue;
        }
        if (a == "--help" || a == "-h") {
            printHelp();
            return 0;
        }
        if (!parseProtectTuningArg(a, i, argc, argv, cfg, forceMax, ultra)) {
            throw std::runtime_error("Unknown option: " + a);
        }
    }

    if (!hasIn || !hasOut) throw std::runtime_error("protect requires --in and --out");
    applyProtectPreset(cfg, forceMax, ultra);
    if (cfg.mutationLevel < 1) throw std::runtime_error("--mutation-level must be >= 1");

    const auto stats = novacpp::protectPath(cfg);
    std::cout << "[OK] protected files: " << stats.files << "\n";
    std::cout << "[STATS] strings=" << stats.strings
              << " ints=" << stats.ints
              << " mutations=" << stats.mutations
              << " renames=" << stats.renames << "\n";
    return 0;
}

int cmdPack(int argc, char** argv) {
    novacpp::PackConfig cfg{};
    bool hasIn = false;
    bool hasOut = false;
    bool hasPass = false;

    for (int i = 2; i < argc; ++i) {
        const std::string a = argv[i];
        if (a == "--in") {
            cfg.inputPath = needValue(i, argc, argv, "--in");
            hasIn = true;
        } else if (a == "--out") {
            cfg.outputFile = needValue(i, argc, argv, "--out");
            hasOut = true;
        } else if (a == "--password") {
            cfg.password = needValue(i, argc, argv, "--password");
            hasPass = true;
        } else if (a == "--kdf-rounds") {
            cfg.kdfRounds = static_cast<std::uint32_t>(std::stoul(needValue(i, argc, argv, "--kdf-rounds")));
        } else if (a == "--help" || a == "-h") {
            printHelp();
            return 0;
        } else {
            throw std::runtime_error("Unknown option: " + a);
        }
    }

    if (!hasIn || !hasOut || !hasPass) throw std::runtime_error("pack requires --in --out --password");
    novacpp::packPath(cfg);
    std::cout << "[OK] packed -> " << cfg.outputFile << "\n";
    std::cout << "[KDF] rounds=" << cfg.kdfRounds << "\n";
    return 0;
}

int cmdUnpack(int argc, char** argv) {
    novacpp::UnpackConfig cfg{};
    bool hasIn = false;
    bool hasOut = false;
    bool hasPass = false;

    for (int i = 2; i < argc; ++i) {
        const std::string a = argv[i];
        if (a == "--in") {
            cfg.inputFile = needValue(i, argc, argv, "--in");
            hasIn = true;
        } else if (a == "--out") {
            cfg.outputDir = needValue(i, argc, argv, "--out");
            hasOut = true;
        } else if (a == "--password") {
            cfg.password = needValue(i, argc, argv, "--password");
            hasPass = true;
        } else if (a == "--help" || a == "-h") {
            printHelp();
            return 0;
        } else {
            throw std::runtime_error("Unknown option: " + a);
        }
    }

    if (!hasIn || !hasOut || !hasPass) throw std::runtime_error("unpack requires --in --out --password");
    novacpp::unpackFile(cfg);
    std::cout << "[OK] unpacked -> " << cfg.outputDir << "\n";
    return 0;
}

int cmdPeScrub(int argc, char** argv) {
    novacpp::PeSectionScrubConfig cfg{};
    bool hasIn = false;
    for (int i = 2; i < argc; ++i) {
        const std::string a = argv[i];
        if (a == "--in") {
            cfg.inputFile = needValue(i, argc, argv, "--in");
            hasIn = true;
        } else if (a == "--out") {
            cfg.outputFile = needValue(i, argc, argv, "--out");
        } else if (a == "--seed") {
            cfg.seed = std::stoull(needValue(i, argc, argv, "--seed"));
        } else if (a == "--zero-names") {
            cfg.zeroNames = true;
        } else if (a == "--help" || a == "-h") {
            printHelp();
            return 0;
        } else {
            throw std::runtime_error("Unknown option: " + a);
        }
    }
    if (!hasIn) throw std::runtime_error("pe-scrub requires --in");
    if (cfg.outputFile.empty()) cfg.outputFile = cfg.inputFile;
    const auto stats = novacpp::scrubPeSectionNames(cfg);
    std::cout << "[OK] PE section names scrubbed: " << stats.sections
              << (cfg.zeroNames ? " (zeroed)" : " (randomized)") << "\n";
    std::cout << "[OUT] " << cfg.outputFile << "\n";
    return 0;
}

int cmdArmor(int argc, char** argv) {
    novacpp::ProtectConfig protectCfg{};
    novacpp::PackConfig packCfg{};

    bool hasIn = false;
    bool hasOut = false;
    bool hasPass = false;
    bool forceMax = false;
    bool ultra = false;
    fs::path tempRoot;

    for (int i = 2; i < argc; ++i) {
        const std::string a = argv[i];
        if (a == "--in") {
            protectCfg.inputPath = needValue(i, argc, argv, "--in");
            hasIn = true;
        } else if (a == "--out") {
            packCfg.outputFile = needValue(i, argc, argv, "--out");
            hasOut = true;
        } else if (a == "--password") {
            packCfg.password = needValue(i, argc, argv, "--password");
            hasPass = true;
        } else if (a == "--tmp") {
            tempRoot = needValue(i, argc, argv, "--tmp");
        } else if (a == "--kdf-rounds") {
            packCfg.kdfRounds = static_cast<std::uint32_t>(std::stoul(needValue(i, argc, argv, "--kdf-rounds")));
        } else if (a == "--help" || a == "-h") {
            printHelp();
            return 0;
        } else if (!parseProtectTuningArg(a, i, argc, argv, protectCfg, forceMax, ultra)) {
            throw std::runtime_error("Unknown option: " + a);
        }
    }

    if (!hasIn || !hasOut || !hasPass) throw std::runtime_error("armor requires --in --out --password");
    if (!fs::exists(protectCfg.inputPath)) throw std::runtime_error("armor input does not exist");

    applyProtectPreset(protectCfg, forceMax, ultra);
    if (protectCfg.mutationLevel < 1) throw std::runtime_error("--mutation-level must be >= 1");

    if (tempRoot.empty()) {
        const auto stamp = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        const auto parent = packCfg.outputFile.parent_path();
        tempRoot = (parent.empty() ? fs::current_path() : parent) /
                   (".novacpp-armor-" + std::to_string(stamp));
    }
    if (fs::exists(tempRoot)) {
        throw std::runtime_error("Temporary armor folder already exists: " + tempRoot.string());
    }

    const bool inputIsFile = fs::is_regular_file(protectCfg.inputPath);
    if (!inputIsFile && !fs::is_directory(protectCfg.inputPath)) {
        throw std::runtime_error("armor --in must be a file or directory");
    }

    protectCfg.outputPath = inputIsFile ? (tempRoot / protectCfg.inputPath.filename()) : tempRoot;
    const auto stats = novacpp::protectPath(protectCfg);

    packCfg.inputPath = protectCfg.outputPath;
    novacpp::packPath(packCfg);

    std::cout << "[OK] armor completed\n";
    std::cout << "[OUT] package=" << packCfg.outputFile << "\n";
    std::cout << "[TMP] protected artifacts=" << protectCfg.outputPath << "\n";
    std::cout << "[STATS] files=" << stats.files
              << " strings=" << stats.strings
              << " ints=" << stats.ints
              << " mutations=" << stats.mutations
              << " renames=" << stats.renames << "\n";
    return 0;
}

}  // namespace

int main(int argc, char** argv) {
    try {
        if (argc < 2) {
            printHelp();
            return 0;
        }
        const std::string cmd = argv[1];
        if (cmd == "protect") return cmdProtect(argc, argv);
        if (cmd == "pack") return cmdPack(argc, argv);
        if (cmd == "unpack") return cmdUnpack(argc, argv);
        if (cmd == "pe-scrub") return cmdPeScrub(argc, argv);
        if (cmd == "armor") return cmdArmor(argc, argv);
        if (cmd == "--help" || cmd == "-h" || cmd == "help") {
            printHelp();
            return 0;
        }
        throw std::runtime_error("Unknown command: " + cmd);
    } catch (const std::exception& e) {
        std::cerr << "[ERR] " << e.what() << "\n";
        return 1;
    }
}
