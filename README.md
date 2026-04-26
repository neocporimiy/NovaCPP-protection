# NovaCPP Protection

Max-hardening C/C++ source protection toolkit with one binary:
- `protect`: obfuscation + mutation + string encryption (MAX profile ready)
- `pack`: password-encrypted package (`.nvp`)
- `unpack`: restore package

## Build (CMake)

```bash
cmake -S . -B build
cmake --build build --config Release
```

Binary:
- Windows MSVC: `build/Release/novacpp.exe`
- MinGW/clang: `build/novacpp`

## Quick Start

Protect a single file (MAX):

```bash
novacpp protect --in samples/demo.cpp --out out/demo.protected.cpp --max
```

Protect entire project:

```bash
novacpp protect --in path/to/cpp_project --out path/to/protected_project --max
```

Pack protected output:

```bash
novacpp pack --in path/to/protected_project --out protected.nvp --password "StrongPass#2026"
```

Unpack:

```bash
novacpp unpack --in protected.nvp --out restored_project --password "StrongPass#2026"
```

## Options

`protect`:
- `--seed <N>`
- `--mutation-level <N>`
- `--no-int-obf`
- `--no-rename`
- `--max` (recommended, strongest preset)

`pack` / `unpack`:
- `--password <pwd>`

## Notes

This is a strong practical hardening layer, but no software protection is mathematically unbreakable.
