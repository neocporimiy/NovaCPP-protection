cmake_minimum_required(VERSION 3.20)
project(NovaCPP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(novacpp
    src/main.cpp
    src/transformer.cpp
    src/packer.cpp
    src/pe_hardener.cpp
)

target_include_directories(novacpp PRIVATE include)

if(MSVC)
    target_compile_options(novacpp PRIVATE /W4 /O2 /GL /Gy /Gw)
    target_link_options(novacpp PRIVATE /LTCG /OPT:REF /OPT:ICF /INCREMENTAL:NO /DEBUG:NONE)
else()
    target_compile_options(novacpp PRIVATE -Wall -Wextra -Wpedantic -O3 -fvisibility=hidden -ffunction-sections -fdata-sections)
    target_link_options(novacpp PRIVATE -Wl,--gc-sections -s)
endif()
