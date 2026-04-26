#include "novacpp/packer.hpp"
#include "novacpp/transformer.hpp"

#include <iostream>
#include <stdexcept>
#include <string>

namespace {

void printHelp() {
    std::cout
        << "NovaCPP usage:\n"
        << "  novacpp protect --in <file|dir> --out <file|dir> [--seed N] [--mutation-level N]\n"
        << "                  [--no-int-obf] [--no-rename] [--max]\n"
        << "  novacpp pack    --in <file|dir> --out <file.nvp> --password <pwd>\n"
        << "  novacpp unpack  --in <file.nvp> --out <dir> --password <pwd>\n";
}

std::string needValue(int& i, int argc, char** argv, const char* name) {
    if (i + 1 >= argc) throw std::runtime_error(std::string("Missing value for ") + name);
    return argv[++i];
}

int cmdProtect(int argc, char** argv) {
    novacpp::ProtectConfig cfg{};
    bool hasIn = false, hasOut = false;
    bool forceMax = false;
    for (int i = 2; i < argc; ++i) {
        const std::string a = argv[i];
        if (a == "--in") {
            cfg.inputPath = needValue(i, argc, argv, "--in");
            hasIn = true;
        } else if (a == "--out") {
            cfg.outputPath = needValue(i, argc, argv, "--out");
            hasOut = true;
        } else if (a == "--seed") {
            cfg.seed = std::stoull(needValue(i, argc, argv, "--seed"));
        } else if (a == "--mutation-level") {
            cfg.mutationLevel = std::stoi(needValue(i, argc, argv, "--mutation-level"));
        } else if (a == "--no-int-obf") {
            cfg.enableIntObf = false;
        } else if (a == "--no-rename") {
            cfg.enableRename = false;
        } else if (a == "--max") {
            forceMax = true;
        } else if (a == "--help" || a == "-h") {
            printHelp();
            return 0;
        } else {
            throw std::runtime_error("Unknown option: " + a);
        }
    }
    if (!hasIn || !hasOut) throw std::runtime_error("protect requires --in and --out");
    if (forceMax) {
        cfg.mutationLevel = 8;
        cfg.enableIntObf = true;
        cfg.enableRename = true;
    }
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
    bool hasIn = false, hasOut = false, hasPass = false;
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
    return 0;
}

int cmdUnpack(int argc, char** argv) {
    novacpp::UnpackConfig cfg{};
    bool hasIn = false, hasOut = false, hasPass = false;
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
