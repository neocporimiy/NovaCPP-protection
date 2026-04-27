# NovaCPP Protection

![C++](https://img.shields.io/badge/C%2B%2B-20-00599C?logo=cplusplus&logoColor=white)
![Build](https://img.shields.io/badge/Build-CMake-064F8C?logo=cmake&logoColor=white)
![Profile](https://img.shields.io/badge/Security-MAX-critical)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-2EA043)
![CLI](https://img.shields.io/badge/CLI-Easy%20Workflow-8A2BE2)

Maximum-hardening C/C++ source protection toolkit with one simple CLI:

- `protect` -> deep obfuscation, mutation, encryption-oriented source transformation
- `pack` -> password-encrypted package (`.nvp`)
- `unpack` -> integrity-checked restore
- `pe-scrub` -> section-name scrubbing for PE binaries (`.exe/.dll`)
- `armor` -> one-command `protect + pack` pipeline for easiest workflow

## Why NovaCPP

- Aggressive source hardening in a single command
- Practical workflow for real projects (file or whole directory)
- Built with CMake, easy to integrate into build pipelines
- Security-first packaging for protected deliverables

## Features

- String literal encryption with runtime decoder
- Integer literal masking/obfuscation
- Control-flow mutation (anti-analysis junk blocks)
- Local identifier renaming
- Automatic runtime injection for protected code paths
- Hardened archive format (`NVPKG02`) with stronger password derivation and integrity check (`.nvp`)
- Safe unpack path validation (blocks `../` traversal and absolute-path extraction)
- PE section-name scrubbing (randomized or zeroed section names)

## Quick Start

### 1) Build

```bash
cmake -S . -B build
cmake --build build --config Release
```

### 2) Protect source (MAX / ULTRA profile)

```bash
./build/Release/novacpp.exe protect --in samples/demo.cpp --out out/demo.protected.cpp --max
```

Ultra mode:

```bash
./build/Release/novacpp.exe protect --in samples/demo.cpp --out out/demo.protected.cpp --max --ultra
```

### 3) Pack protected output

```bash
./build/Release/novacpp.exe pack --in out --out out/demo_protected.nvp --password "StrongPass2026!" --kdf-rounds 220000
```

### 3.5) One-command hardening (recommended)

```bash
./build/Release/novacpp.exe armor --in samples/demo.cpp --out out/demo_protected.nvp --password "StrongPass2026!" --ultra
```

### 4) Unpack

```bash
./build/Release/novacpp.exe unpack --in out/demo_protected.nvp --out restored --password "StrongPass2026!"
```

### 5) Scrub PE section names

Randomize section names:

```bash
./build/Release/novacpp.exe pe-scrub --in out/build/Release/demo_protected.exe --out out/build/Release/demo_protected.scrub.exe
```

Zero section names:

```bash
./build/Release/novacpp.exe pe-scrub --in out/build/Release/demo_protected.exe --zero-names
```

## CLI

```bash
novacpp protect --in <file|dir> --out <file|dir> [--seed N] [--mutation-level N] [--no-int-obf] [--no-rename] [--max] [--ultra]
novacpp pack    --in <file|dir> --out <file.nvp> --password <pwd> [--kdf-rounds N]
novacpp unpack  --in <file.nvp> --out <dir> --password <pwd>
novacpp pe-scrub --in <file.exe|file.dll> [--out <file>] [--seed N] [--zero-names]
novacpp armor   --in <file|dir> --out <file.nvp> --password <pwd> [--tmp <dir>] [--kdf-rounds N] [protect options]
```

## Project Layout

```text
NovaCPP protection/
  include/novacpp/
    common.hpp
    transformer.hpp
    packer.hpp
    pe_hardener.hpp
  src/
    main.cpp
    transformer.cpp
    packer.cpp
    pe_hardener.cpp
  samples/
    demo.cpp
  CMakeLists.txt
```

## Security Note

No software protection is mathematically unbreakable.  
NovaCPP is designed to significantly increase reverse-engineering and tampering cost with layered practical defenses.
