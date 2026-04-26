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
- Password-encrypted archive format with integrity check (`.nvp`)

## Quick Start

### 1) Build

```bash
cmake -S . -B build
cmake --build build --config Release
```

### 2) Protect source (MAX profile)

```bash
./build/Release/novacpp.exe protect --in samples/demo.cpp --out out/demo.protected.cpp --max
```

### 3) Pack protected output

```bash
./build/Release/novacpp.exe pack --in out --out out/demo_protected.nvp --password "StrongPass2026!"
```

### 4) Unpack

```bash
./build/Release/novacpp.exe unpack --in out/demo_protected.nvp --out restored --password "StrongPass2026!"
```

## CLI

```bash
novacpp protect --in <file|dir> --out <file|dir> [--seed N] [--mutation-level N] [--no-int-obf] [--no-rename] [--max]
novacpp pack    --in <file|dir> --out <file.nvp> --password <pwd>
novacpp unpack  --in <file.nvp> --out <dir> --password <pwd>
```

## Project Layout

```text
NovaCPP protection/
  include/novacpp/
    common.hpp
    transformer.hpp
    packer.hpp
  src/
    main.cpp
    transformer.cpp
    packer.cpp
  samples/
    demo.cpp
  CMakeLists.txt
```

## Security Note

No software protection is mathematically unbreakable.  
NovaCPP is designed to significantly increase reverse-engineering and tampering cost with layered practical defenses.
