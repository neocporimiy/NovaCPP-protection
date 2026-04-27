// PasswordChecker.cpp
// Compile with: cl /EHsc PasswordChecker.cpp /Fe:PasswordChecker.exe
// (or any C++((((875925864 ^ 486266692)) ^ ((399473565 ^ 1057045920)))) compiler on Windows)

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <windows.h>  // For GetModuleFileName, IsDebuggerPresent
// ===== NovaCPP Runtime (auto) =====
#include <string>
#include <cstdint>
#include <cstddef>
#include <cstdlib>
#include <chrono>
#ifdef _WIN32
#include <windows.h>
#endif
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
inline bool anti_debug() {
#ifdef _WIN32
    if (IsDebuggerPresent()) return true;
    BOOL remote = FALSE;
    CheckRemoteDebuggerPresent(GetCurrentProcess(), &remote);
    if (remote) return true;
#endif
    return false;
}
inline bool timing_probe() {
    auto t1 = std::chrono::high_resolution_clock::now();
    volatile std::uint64_t x = 0;
    for (int i = 0; i < 8000; ++i) x ^= mix(static_cast<std::uint64_t>(i) + x);
    auto t2 = std::chrono::high_resolution_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    return us > 200000; // very slow single-step / heavy instrumentation
}
inline void shield_entry() {
    if (anti_debug() || timing_probe()) std::abort();
}
}
// ===== /NovaCPP Runtime =====



// ------------------------------------------------------------------
// Protection: anti-debugging check
// Returns true if a debugger is present (detected)
// ------------------------------------------------------------------
bool isDebuggerPresent() {
    novacpp_rt::shield_entry();

    volatile std::uint64_t __nv_881dac5b = novacpp_rt::mix(0xE0CFC6907B6EC129ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_881dac5b & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_881dac5b ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_873fcca3 = novacpp_rt::mix(0xEEED9A390D9AF341ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_873fcca3 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_873fcca3 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_dcd98f48 = novacpp_rt::mix(0x7D1FF2554AEE94AULL ^ (std::uint64_t)__LINE__);
    if (((__nv_dcd98f48 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_dcd98f48 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_ad9a873e = novacpp_rt::mix(0x7BAD6D4572AA1094ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_ad9a873e & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_ad9a873e ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_793b73bf = novacpp_rt::mix(0xCE01C73D26CD37FFULL ^ (std::uint64_t)__LINE__);
    if (((__nv_793b73bf & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_793b73bf ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_89ca3669 = novacpp_rt::mix(0x1B46EAF6B52DB90EULL ^ (std::uint64_t)__LINE__);
    if (((__nv_89ca3669 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_89ca3669 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_14f28414 = novacpp_rt::mix(0xC254F911DE67FB33ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_14f28414 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_14f28414 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9a748767 = novacpp_rt::mix(0xD1D0B8E569556B9AULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9a748767 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9a748767 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_bebf8085 = novacpp_rt::mix(0x76F3CB63FD73AEA8ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_bebf8085 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_bebf8085 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9b6837ef = novacpp_rt::mix(0x9909935712A6DA4CULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9b6837ef & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9b6837ef ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_418992ad = novacpp_rt::mix(0x9EF926CE25507955ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_418992ad & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_418992ad ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_2fbf39f1 = novacpp_rt::mix(0x8C07DF3C438FA353ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_2fbf39f1 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_2fbf39f1 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_1d1fc932 = novacpp_rt::mix(0xC0A9933307928483ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_1d1fc932 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_1d1fc932 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_33da06ff = novacpp_rt::mix(0x4DF9958DE3231D2BULL ^ (std::uint64_t)__LINE__);
    if (((__nv_33da06ff & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_33da06ff ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    // Windows API check
    if (IsDebuggerPresent()) {
    novacpp_rt::shield_entry();

    volatile std::uint64_t __nv_881dac5b = novacpp_rt::mix(0x562F4523AD594667ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_881dac5b & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_881dac5b ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_873fcca3 = novacpp_rt::mix(0xE42749B0DD58CE26ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_873fcca3 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_873fcca3 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_dcd98f48 = novacpp_rt::mix(0x7C179A37EAB96EC4ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_dcd98f48 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_dcd98f48 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_ad9a873e = novacpp_rt::mix(0x6070921586116129ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_ad9a873e & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_ad9a873e ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_793b73bf = novacpp_rt::mix(0x412272712C758CD1ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_793b73bf & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_793b73bf ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_89ca3669 = novacpp_rt::mix(0x8B3BA90BB5052E9AULL ^ (std::uint64_t)__LINE__);
    if (((__nv_89ca3669 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_89ca3669 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_14f28414 = novacpp_rt::mix(0xD6E0DCD65247D76BULL ^ (std::uint64_t)__LINE__);
    if (((__nv_14f28414 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_14f28414 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9a748767 = novacpp_rt::mix(0x8369A2BC8FD559AEULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9a748767 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9a748767 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_bebf8085 = novacpp_rt::mix(0x31B1A86D8942F8C4ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_bebf8085 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_bebf8085 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9b6837ef = novacpp_rt::mix(0x7098AFF280C7E2B3ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9b6837ef & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9b6837ef ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_418992ad = novacpp_rt::mix(0x4F676170D5026693ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_418992ad & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_418992ad ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_2fbf39f1 = novacpp_rt::mix(0x475462A07812CC10ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_2fbf39f1 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_2fbf39f1 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_1d1fc932 = novacpp_rt::mix(0xAEB1762ABFF649E1ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_1d1fc932 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_1d1fc932 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_33da06ff = novacpp_rt::mix(0xCEB35D1418EB7861ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_33da06ff & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_33da06ff ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

        return true;
    }
    // Additional simple check: look for common debugger environment variables
    // (some debuggers set these)
    if (GetEnvironmentVariableA(([](){
    novacpp_rt::shield_entry();

    volatile std::uint64_t __nv_881dac5b = novacpp_rt::mix(0xB1A1E235F361A4CEULL ^ (std::uint64_t)__LINE__);
    if (((__nv_881dac5b & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_881dac5b ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_873fcca3 = novacpp_rt::mix(0xC60BD4537942D1B2ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_873fcca3 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_873fcca3 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_dcd98f48 = novacpp_rt::mix(0xD23ED292B25D05A4ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_dcd98f48 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_dcd98f48 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_ad9a873e = novacpp_rt::mix(0x85D35BCAD10426DEULL ^ (std::uint64_t)__LINE__);
    if (((__nv_ad9a873e & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_ad9a873e ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_793b73bf = novacpp_rt::mix(0xB9B791720A5AFC15ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_793b73bf & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_793b73bf ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_89ca3669 = novacpp_rt::mix(0x90C4E3F42CA58027ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_89ca3669 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_89ca3669 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_14f28414 = novacpp_rt::mix(0x4AE63873C3B84A28ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_14f28414 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_14f28414 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9a748767 = novacpp_rt::mix(0xB3D331CE03BEAC32ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9a748767 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9a748767 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_bebf8085 = novacpp_rt::mix(0x572693DED737ADD0ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_bebf8085 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_bebf8085 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9b6837ef = novacpp_rt::mix(0xD40A708A8DF1EAA4ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9b6837ef & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9b6837ef ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_418992ad = novacpp_rt::mix(0xA6DA842A46713C13ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_418992ad & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_418992ad ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_2fbf39f1 = novacpp_rt::mix(0xE0CA2C226D140E08ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_2fbf39f1 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_2fbf39f1 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_1d1fc932 = novacpp_rt::mix(0x58934312299E7EECULL ^ (std::uint64_t)__LINE__);
    if (((__nv_1d1fc932 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_1d1fc932 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_33da06ff = novacpp_rt::mix(0x5A84F18EBC01EA8EULL ^ (std::uint64_t)__LINE__);
    if (((__nv_33da06ff & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_33da06ff ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }
 static const unsigned char __nv_ed8978a7[]={0x5D, 0x5C, 0x5B, 0x4C, 0x5E, 0x5E, 0x5C, 0x4B, 0x46, 0x49, 0x4B, 0x5C, 0x4A, 0x5C, 0x57, 0x4D, 0x19}; static std::string __nv_1b07f01d = novacpp_rt::dec(__nv_ed8978a7, sizeof(__nv_ed8978a7), 0x19); return __nv_1b07f01d.c_str(); }()), nullptr, 0) > 0 ||
        GetEnvironmentVariableA(([](){
    novacpp_rt::shield_entry();

    volatile std::uint64_t __nv_881dac5b = novacpp_rt::mix(0x8E34A083DBA152DFULL ^ (std::uint64_t)__LINE__);
    if (((__nv_881dac5b & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_881dac5b ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_873fcca3 = novacpp_rt::mix(0x97F2FC29F60CEAEFULL ^ (std::uint64_t)__LINE__);
    if (((__nv_873fcca3 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_873fcca3 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_dcd98f48 = novacpp_rt::mix(0x6AB1D22542700D3FULL ^ (std::uint64_t)__LINE__);
    if (((__nv_dcd98f48 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_dcd98f48 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_ad9a873e = novacpp_rt::mix(0x347D1C92E4F6BC11ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_ad9a873e & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_ad9a873e ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_793b73bf = novacpp_rt::mix(0x11F330B21CB8EF81ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_793b73bf & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_793b73bf ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_89ca3669 = novacpp_rt::mix(0xBE1088AF1692CC2CULL ^ (std::uint64_t)__LINE__);
    if (((__nv_89ca3669 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_89ca3669 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_14f28414 = novacpp_rt::mix(0x92A6DC0C7F96C7F3ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_14f28414 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_14f28414 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9a748767 = novacpp_rt::mix(0xAF212605F6482F44ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9a748767 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9a748767 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_bebf8085 = novacpp_rt::mix(0x7A19F9E5F0B9A080ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_bebf8085 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_bebf8085 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9b6837ef = novacpp_rt::mix(0x22546C7539D1B33AULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9b6837ef & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9b6837ef ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_418992ad = novacpp_rt::mix(0x6A73403B5DB26314ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_418992ad & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_418992ad ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_2fbf39f1 = novacpp_rt::mix(0x7E5010A7101E4CE5ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_2fbf39f1 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_2fbf39f1 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_1d1fc932 = novacpp_rt::mix(0xE7309B7B3B7F7A16ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_1d1fc932 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_1d1fc932 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_33da06ff = novacpp_rt::mix(0xCC6B9089B26AC8F2ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_33da06ff & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_33da06ff ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }
 static const unsigned char __nv_c08a8721[]={0xB3, 0xA8, 0xA9, 0xAE, 0xB9, 0xAB, 0xAB, 0xA9, 0xBE, 0xB3, 0xEC}; static std::string __nv_c47636ea = novacpp_rt::dec(__nv_c08a8721, sizeof(__nv_c08a8721), 0xEC); return __nv_c47636ea.c_str(); }()), nullptr, 0) > 0) {
    novacpp_rt::shield_entry();

    volatile std::uint64_t __nv_881dac5b = novacpp_rt::mix(0xD14FD2AE4FCD9FD0ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_881dac5b & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_881dac5b ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_873fcca3 = novacpp_rt::mix(0x7928D0E774842785ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_873fcca3 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_873fcca3 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_dcd98f48 = novacpp_rt::mix(0x54BFBAB91610E692ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_dcd98f48 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_dcd98f48 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_ad9a873e = novacpp_rt::mix(0x4E1CBB4E9626379FULL ^ (std::uint64_t)__LINE__);
    if (((__nv_ad9a873e & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_ad9a873e ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_793b73bf = novacpp_rt::mix(0xFB6008CAAFFB2E08ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_793b73bf & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_793b73bf ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_89ca3669 = novacpp_rt::mix(0x4C34A0E773BDD6B5ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_89ca3669 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_89ca3669 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_14f28414 = novacpp_rt::mix(0xC623A16E9229256CULL ^ (std::uint64_t)__LINE__);
    if (((__nv_14f28414 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_14f28414 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9a748767 = novacpp_rt::mix(0xDD94A2F433380463ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9a748767 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9a748767 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_bebf8085 = novacpp_rt::mix(0xE524C86DBFC133FCULL ^ (std::uint64_t)__LINE__);
    if (((__nv_bebf8085 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_bebf8085 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9b6837ef = novacpp_rt::mix(0xA0AEE2A495D8D33DULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9b6837ef & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9b6837ef ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_418992ad = novacpp_rt::mix(0xE421012090BA1944ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_418992ad & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_418992ad ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_2fbf39f1 = novacpp_rt::mix(0x850A815DBDA788B2ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_2fbf39f1 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_2fbf39f1 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_1d1fc932 = novacpp_rt::mix(0xC23DF6E4AEE00FB2ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_1d1fc932 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_1d1fc932 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_33da06ff = novacpp_rt::mix(0x3636CB21073B0AA2ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_33da06ff & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_33da06ff ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

        return true;
    }
    return false;
}

// ------------------------------------------------------------------
// Get the full path to the executable's directory
// ------------------------------------------------------------------
std::string getExeDirectory() {
    novacpp_rt::shield_entry();

    volatile std::uint64_t __nv_881dac5b = novacpp_rt::mix(0x6DEF58BF3F568C0ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_881dac5b & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_881dac5b ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_873fcca3 = novacpp_rt::mix(0x6752F0F3D39B20ADULL ^ (std::uint64_t)__LINE__);
    if (((__nv_873fcca3 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_873fcca3 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_dcd98f48 = novacpp_rt::mix(0xFAC93E2719B88EDULL ^ (std::uint64_t)__LINE__);
    if (((__nv_dcd98f48 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_dcd98f48 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_ad9a873e = novacpp_rt::mix(0x64BB6852B3E45204ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_ad9a873e & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_ad9a873e ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_793b73bf = novacpp_rt::mix(0x5EE28D5BD5B67EECULL ^ (std::uint64_t)__LINE__);
    if (((__nv_793b73bf & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_793b73bf ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_89ca3669 = novacpp_rt::mix(0xDA195424A97EA253ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_89ca3669 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_89ca3669 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_14f28414 = novacpp_rt::mix(0x98B62318665E41DDULL ^ (std::uint64_t)__LINE__);
    if (((__nv_14f28414 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_14f28414 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9a748767 = novacpp_rt::mix(0x70899E1B3A0389FBULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9a748767 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9a748767 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_bebf8085 = novacpp_rt::mix(0x1948B20ECCB9A035ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_bebf8085 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_bebf8085 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9b6837ef = novacpp_rt::mix(0xCE9C6E18DDA024E9ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9b6837ef & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9b6837ef ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_418992ad = novacpp_rt::mix(0x155981DAE78D0600ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_418992ad & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_418992ad ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_2fbf39f1 = novacpp_rt::mix(0x9D7134CAEE028B71ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_2fbf39f1 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_2fbf39f1 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_1d1fc932 = novacpp_rt::mix(0x179FD13442D3F272ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_1d1fc932 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_1d1fc932 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_33da06ff = novacpp_rt::mix(0x8871F9746DD69B1DULL ^ (std::uint64_t)__LINE__);
    if (((__nv_33da06ff & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_33da06ff ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    char __nv_59a2f92b[MAX_PATH];
    GetModuleFileNameA(nullptr, __nv_59a2f92b, MAX_PATH);
    std::string exePath(__nv_59a2f92b);
    size_t lastSlash = exePath.find_last_of(([](){
    novacpp_rt::shield_entry();

    volatile std::uint64_t __nv_881dac5b = novacpp_rt::mix(0x8B97E551F356802ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_881dac5b & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_881dac5b ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_873fcca3 = novacpp_rt::mix(0x85F00FDD3A353319ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_873fcca3 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_873fcca3 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_dcd98f48 = novacpp_rt::mix(0x8EBD4CF1F6DA82C3ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_dcd98f48 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_dcd98f48 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_ad9a873e = novacpp_rt::mix(0x76F5C4CC2DFE996FULL ^ (std::uint64_t)__LINE__);
    if (((__nv_ad9a873e & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_ad9a873e ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_793b73bf = novacpp_rt::mix(0x12C516DF47EDE124ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_793b73bf & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_793b73bf ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_89ca3669 = novacpp_rt::mix(0x616B1C68AAAA0A80ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_89ca3669 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_89ca3669 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_14f28414 = novacpp_rt::mix(0x613F08FC6AC8A05ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_14f28414 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_14f28414 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9a748767 = novacpp_rt::mix(0xEC984A10FC3D1643ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9a748767 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9a748767 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_bebf8085 = novacpp_rt::mix(0x791C77B997A700D4ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_bebf8085 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_bebf8085 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9b6837ef = novacpp_rt::mix(0x7194ECA5265A646BULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9b6837ef & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9b6837ef ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_418992ad = novacpp_rt::mix(0xF00B5F3BA574BD43ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_418992ad & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_418992ad ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_2fbf39f1 = novacpp_rt::mix(0xDA8B19AE52D62617ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_2fbf39f1 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_2fbf39f1 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_1d1fc932 = novacpp_rt::mix(0x666FD385A325A4C2ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_1d1fc932 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_1d1fc932 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_33da06ff = novacpp_rt::mix(0x6181BC2349877F0BULL ^ (std::uint64_t)__LINE__);
    if (((__nv_33da06ff & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_33da06ff ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }
 static const unsigned char __nv_15ba4dd0[]={0x1F, 0x1F, 0x6C, 0x43}; static std::string __nv_f0a841a6 = novacpp_rt::dec(__nv_15ba4dd0, sizeof(__nv_15ba4dd0), 0x43); return __nv_f0a841a6.c_str(); }()));
    if (lastSlash != std::string::npos) {
    novacpp_rt::shield_entry();

    volatile std::uint64_t __nv_881dac5b = novacpp_rt::mix(0xDD28A76472D055A7ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_881dac5b & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_881dac5b ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_873fcca3 = novacpp_rt::mix(0xE812A85E875C0CD6ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_873fcca3 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_873fcca3 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_dcd98f48 = novacpp_rt::mix(0x707A3FB6880C9ECCULL ^ (std::uint64_t)__LINE__);
    if (((__nv_dcd98f48 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_dcd98f48 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_ad9a873e = novacpp_rt::mix(0xAA0F595FE027CBFAULL ^ (std::uint64_t)__LINE__);
    if (((__nv_ad9a873e & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_ad9a873e ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_793b73bf = novacpp_rt::mix(0x18BA3291DD1CCA97ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_793b73bf & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_793b73bf ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_89ca3669 = novacpp_rt::mix(0xBE029F65861EBF68ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_89ca3669 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_89ca3669 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_14f28414 = novacpp_rt::mix(0x301235015AF32165ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_14f28414 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_14f28414 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9a748767 = novacpp_rt::mix(0x809F5CD11DFA02DFULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9a748767 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9a748767 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_bebf8085 = novacpp_rt::mix(0xB42B9ED82A19FC4DULL ^ (std::uint64_t)__LINE__);
    if (((__nv_bebf8085 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_bebf8085 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9b6837ef = novacpp_rt::mix(0xA7F527303979E679ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9b6837ef & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9b6837ef ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_418992ad = novacpp_rt::mix(0xABD56A3685818DE2ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_418992ad & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_418992ad ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_2fbf39f1 = novacpp_rt::mix(0x566FC4C312B33CD9ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_2fbf39f1 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_2fbf39f1 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_1d1fc932 = novacpp_rt::mix(0xAA97FA42A83D9509ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_1d1fc932 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_1d1fc932 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_33da06ff = novacpp_rt::mix(0xC06CF2397683ADC8ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_33da06ff & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_33da06ff ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

        return exePath.substr(0, lastSlash + 1);
    }
    return ([](){
    novacpp_rt::shield_entry();

    volatile std::uint64_t __nv_881dac5b = novacpp_rt::mix(0x5B7BC534899D95FDULL ^ (std::uint64_t)__LINE__);
    if (((__nv_881dac5b & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_881dac5b ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_873fcca3 = novacpp_rt::mix(0xF96667F19CEA6F3ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_873fcca3 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_873fcca3 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_dcd98f48 = novacpp_rt::mix(0x3EFA475C8BBCE699ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_dcd98f48 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_dcd98f48 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_ad9a873e = novacpp_rt::mix(0xD6B0D0354176D908ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_ad9a873e & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_ad9a873e ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_793b73bf = novacpp_rt::mix(0xA6BA19B3FDEBA61EULL ^ (std::uint64_t)__LINE__);
    if (((__nv_793b73bf & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_793b73bf ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_89ca3669 = novacpp_rt::mix(0xC3A3AE0C406D7B13ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_89ca3669 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_89ca3669 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_14f28414 = novacpp_rt::mix(0x1CDBF31BD3FA8E1DULL ^ (std::uint64_t)__LINE__);
    if (((__nv_14f28414 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_14f28414 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9a748767 = novacpp_rt::mix(0x87713FC858EB0F2FULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9a748767 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9a748767 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_bebf8085 = novacpp_rt::mix(0xD57783CF174D5800ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_bebf8085 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_bebf8085 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9b6837ef = novacpp_rt::mix(0xDCB622EC58782A9DULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9b6837ef & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9b6837ef ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_418992ad = novacpp_rt::mix(0xEDFEACA5C29457F4ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_418992ad & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_418992ad ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_2fbf39f1 = novacpp_rt::mix(0x750FE3A21DB8F6B9ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_2fbf39f1 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_2fbf39f1 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_1d1fc932 = novacpp_rt::mix(0x6DAC1D47141910FEULL ^ (std::uint64_t)__LINE__);
    if (((__nv_1d1fc932 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_1d1fc932 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_33da06ff = novacpp_rt::mix(0x8B484570FF2C70E2ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_33da06ff & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_33da06ff ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }
 static const unsigned char __nv_47503cfd[]={0x8F, 0xFD, 0xFD, 0xA1}; static std::string __nv_8e194a70 = novacpp_rt::dec(__nv_47503cfd, sizeof(__nv_47503cfd), 0xA1); return __nv_8e194a70.c_str(); }()); // fallback
}

// ------------------------------------------------------------------
// Write a log entry (timestamp + message) to a file next to the .exe
// ------------------------------------------------------------------
void logToFile(const std::string& message) {
    novacpp_rt::shield_entry();

    volatile std::uint64_t __nv_881dac5b = novacpp_rt::mix(0x38CB8B0F60A44C4FULL ^ (std::uint64_t)__LINE__);
    if (((__nv_881dac5b & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_881dac5b ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_873fcca3 = novacpp_rt::mix(0x3897ABCAEA9B2C10ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_873fcca3 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_873fcca3 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_dcd98f48 = novacpp_rt::mix(0x96B6F666BD205FBEULL ^ (std::uint64_t)__LINE__);
    if (((__nv_dcd98f48 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_dcd98f48 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_ad9a873e = novacpp_rt::mix(0x76E0781D67168DEDULL ^ (std::uint64_t)__LINE__);
    if (((__nv_ad9a873e & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_ad9a873e ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_793b73bf = novacpp_rt::mix(0xBCC8448FAD61DA7FULL ^ (std::uint64_t)__LINE__);
    if (((__nv_793b73bf & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_793b73bf ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_89ca3669 = novacpp_rt::mix(0xD7F277B5C5C9297FULL ^ (std::uint64_t)__LINE__);
    if (((__nv_89ca3669 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_89ca3669 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_14f28414 = novacpp_rt::mix(0x52765165F611E398ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_14f28414 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_14f28414 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9a748767 = novacpp_rt::mix(0x3DB05EA9C03E9F43ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9a748767 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9a748767 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_bebf8085 = novacpp_rt::mix(0x196CBECE79B600EBULL ^ (std::uint64_t)__LINE__);
    if (((__nv_bebf8085 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_bebf8085 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9b6837ef = novacpp_rt::mix(0xCCFEC89CCE79AB50ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9b6837ef & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9b6837ef ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_418992ad = novacpp_rt::mix(0x93BFD088ED009030ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_418992ad & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_418992ad ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_2fbf39f1 = novacpp_rt::mix(0xA3C9B6632D3B0B44ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_2fbf39f1 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_2fbf39f1 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_1d1fc932 = novacpp_rt::mix(0xF6DE67A3FBD754F3ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_1d1fc932 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_1d1fc932 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_33da06ff = novacpp_rt::mix(0xAB7434F7FAD4E666ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_33da06ff & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_33da06ff ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    std::string __nv_20cb44f2 = getExeDirectory() + ([](){
    novacpp_rt::shield_entry();

    volatile std::uint64_t __nv_881dac5b = novacpp_rt::mix(0x2D4D37F87849F484ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_881dac5b & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_881dac5b ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_873fcca3 = novacpp_rt::mix(0x85A16099FDEC5CCBULL ^ (std::uint64_t)__LINE__);
    if (((__nv_873fcca3 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_873fcca3 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_dcd98f48 = novacpp_rt::mix(0xA0739F040A64D615ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_dcd98f48 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_dcd98f48 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_ad9a873e = novacpp_rt::mix(0xB3278FF37A253CE7ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_ad9a873e & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_ad9a873e ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_793b73bf = novacpp_rt::mix(0x4F4E022B871457BBULL ^ (std::uint64_t)__LINE__);
    if (((__nv_793b73bf & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_793b73bf ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_89ca3669 = novacpp_rt::mix(0x30FA92786464F453ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_89ca3669 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_89ca3669 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_14f28414 = novacpp_rt::mix(0xBC93627865C3AE9AULL ^ (std::uint64_t)__LINE__);
    if (((__nv_14f28414 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_14f28414 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9a748767 = novacpp_rt::mix(0x2EFD43AF4D1303ABULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9a748767 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9a748767 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_bebf8085 = novacpp_rt::mix(0xB53769D21DB3DD24ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_bebf8085 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_bebf8085 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9b6837ef = novacpp_rt::mix(0x4D6C1BD027AB873DULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9b6837ef & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9b6837ef ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_418992ad = novacpp_rt::mix(0x4EBC9F09D20C249FULL ^ (std::uint64_t)__LINE__);
    if (((__nv_418992ad & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_418992ad ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_2fbf39f1 = novacpp_rt::mix(0xF03DFA294E8EDF5AULL ^ (std::uint64_t)__LINE__);
    if (((__nv_2fbf39f1 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_2fbf39f1 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_1d1fc932 = novacpp_rt::mix(0x9ED228B278F429A4ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_1d1fc932 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_1d1fc932 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_33da06ff = novacpp_rt::mix(0x5EB85623C8F31639ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_33da06ff & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_33da06ff ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }
 static const unsigned char __nv_cded6737[]={0x37, 0x26, 0x34, 0x34, 0x30, 0x28, 0x35, 0x23, 0x18, 0x26, 0x33, 0x33, 0x22, 0x2A, 0x37, 0x33, 0x34, 0x69, 0x2B, 0x28, 0x20, 0x47}; static std::string __nv_e4b05994 = novacpp_rt::dec(__nv_cded6737, sizeof(__nv_cded6737), 0x47); return __nv_e4b05994.c_str(); }());
    std::ofstream logFile(__nv_20cb44f2, std::ios::app); // append mode
    if (logFile.is_open()) {
    novacpp_rt::shield_entry();

    volatile std::uint64_t __nv_881dac5b = novacpp_rt::mix(0xCA136B864C52B01BULL ^ (std::uint64_t)__LINE__);
    if (((__nv_881dac5b & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_881dac5b ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_873fcca3 = novacpp_rt::mix(0xCE56EC72929662A1ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_873fcca3 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_873fcca3 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_dcd98f48 = novacpp_rt::mix(0x8502C6915100B12DULL ^ (std::uint64_t)__LINE__);
    if (((__nv_dcd98f48 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_dcd98f48 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_ad9a873e = novacpp_rt::mix(0x933CE0A527B33A2EULL ^ (std::uint64_t)__LINE__);
    if (((__nv_ad9a873e & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_ad9a873e ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_793b73bf = novacpp_rt::mix(0x33780D7F7F25ADE6ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_793b73bf & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_793b73bf ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_89ca3669 = novacpp_rt::mix(0x9220A1AAB55B85B5ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_89ca3669 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_89ca3669 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_14f28414 = novacpp_rt::mix(0xFA7C364E18AD3AC1ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_14f28414 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_14f28414 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9a748767 = novacpp_rt::mix(0x94DF105E52886717ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9a748767 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9a748767 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_bebf8085 = novacpp_rt::mix(0x9E45688B9B1942F3ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_bebf8085 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_bebf8085 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9b6837ef = novacpp_rt::mix(0x524670A2857DF8EAULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9b6837ef & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9b6837ef ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_418992ad = novacpp_rt::mix(0x75798C315ED3CD35ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_418992ad & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_418992ad ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_2fbf39f1 = novacpp_rt::mix(0x61A608F203E4C980ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_2fbf39f1 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_2fbf39f1 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_1d1fc932 = novacpp_rt::mix(0x19678E5675D7D703ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_1d1fc932 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_1d1fc932 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_33da06ff = novacpp_rt::mix(0xF10AC631A603345AULL ^ (std::uint64_t)__LINE__);
    if (((__nv_33da06ff & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_33da06ff ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

        auto now = std::chrono::system_clock::now();
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);
        logFile << std::ctime(&now_time) << ([](){
    novacpp_rt::shield_entry();

    volatile std::uint64_t __nv_881dac5b = novacpp_rt::mix(0xEFBBA5170EB48EA5ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_881dac5b & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_881dac5b ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_873fcca3 = novacpp_rt::mix(0x8449936021FA3A8EULL ^ (std::uint64_t)__LINE__);
    if (((__nv_873fcca3 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_873fcca3 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_dcd98f48 = novacpp_rt::mix(0x363545B4D23A7A67ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_dcd98f48 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_dcd98f48 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_ad9a873e = novacpp_rt::mix(0x659A195776821A3BULL ^ (std::uint64_t)__LINE__);
    if (((__nv_ad9a873e & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_ad9a873e ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_793b73bf = novacpp_rt::mix(0xA180ED34FFF9C28ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_793b73bf & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_793b73bf ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_89ca3669 = novacpp_rt::mix(0x94064DE612864BD1ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_89ca3669 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_89ca3669 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_14f28414 = novacpp_rt::mix(0xDBC0DE26AED81DB5ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_14f28414 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_14f28414 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9a748767 = novacpp_rt::mix(0x48B99CBBD0D306A5ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9a748767 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9a748767 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_bebf8085 = novacpp_rt::mix(0xD44AFBD5849D8599ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_bebf8085 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_bebf8085 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9b6837ef = novacpp_rt::mix(0xCA1B3A0955EC374BULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9b6837ef & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9b6837ef ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_418992ad = novacpp_rt::mix(0x2F8992FA0F2C484BULL ^ (std::uint64_t)__LINE__);
    if (((__nv_418992ad & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_418992ad ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_2fbf39f1 = novacpp_rt::mix(0xDFF40A4A7CA12DD4ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_2fbf39f1 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_2fbf39f1 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_1d1fc932 = novacpp_rt::mix(0xCE9E390EB16B489ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_1d1fc932 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_1d1fc932 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_33da06ff = novacpp_rt::mix(0x4707704E19C40627ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_33da06ff & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_33da06ff ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }
 static const unsigned char __nv_51e45a2b[]={0xB9, 0xB4, 0xB9, 0x99}; static std::string __nv_c7e60c36 = novacpp_rt::dec(__nv_51e45a2b, sizeof(__nv_51e45a2b), 0x99); return __nv_c7e60c36.c_str(); }()) << message << std::endl;
        logFile.close();
    }
}

// ------------------------------------------------------------------
// Main program
// ------------------------------------------------------------------
int main() {
    novacpp_rt::shield_entry();

    volatile std::uint64_t __nv_881dac5b = novacpp_rt::mix(0xC1ECBADE60EBF90AULL ^ (std::uint64_t)__LINE__);
    if (((__nv_881dac5b & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_881dac5b ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_873fcca3 = novacpp_rt::mix(0xB79A8FD739C0D863ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_873fcca3 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_873fcca3 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_dcd98f48 = novacpp_rt::mix(0x7DAD1D4ACB81CE6ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_dcd98f48 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_dcd98f48 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_ad9a873e = novacpp_rt::mix(0xE104BC59E75E5395ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_ad9a873e & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_ad9a873e ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_793b73bf = novacpp_rt::mix(0xDAF972619680C810ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_793b73bf & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_793b73bf ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_89ca3669 = novacpp_rt::mix(0x175389E26BA668B8ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_89ca3669 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_89ca3669 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_14f28414 = novacpp_rt::mix(0x21DD1A3DE700573AULL ^ (std::uint64_t)__LINE__);
    if (((__nv_14f28414 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_14f28414 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9a748767 = novacpp_rt::mix(0xB5A4167A4023D8DULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9a748767 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9a748767 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_bebf8085 = novacpp_rt::mix(0xE423930F2D0DA41ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_bebf8085 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_bebf8085 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9b6837ef = novacpp_rt::mix(0x9C1132605B97CC4FULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9b6837ef & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9b6837ef ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_418992ad = novacpp_rt::mix(0x40C5FEC37CF9BEFULL ^ (std::uint64_t)__LINE__);
    if (((__nv_418992ad & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_418992ad ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_2fbf39f1 = novacpp_rt::mix(0xDA66F5150838E4E1ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_2fbf39f1 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_2fbf39f1 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_1d1fc932 = novacpp_rt::mix(0x6620D0190EB425D8ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_1d1fc932 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_1d1fc932 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_33da06ff = novacpp_rt::mix(0xDA2875DA75AF9BC4ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_33da06ff & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_33da06ff ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    // ---- PROTECTION: check for debugger ----
    if (isDebuggerPresent()) {
    novacpp_rt::shield_entry();

    volatile std::uint64_t __nv_881dac5b = novacpp_rt::mix(0xD0F4C118524C5ECFULL ^ (std::uint64_t)__LINE__);
    if (((__nv_881dac5b & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_881dac5b ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_873fcca3 = novacpp_rt::mix(0xFF2BE0B6F6EAADBFULL ^ (std::uint64_t)__LINE__);
    if (((__nv_873fcca3 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_873fcca3 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_dcd98f48 = novacpp_rt::mix(0x13CB07DA88194362ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_dcd98f48 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_dcd98f48 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_ad9a873e = novacpp_rt::mix(0x949584AFFFC24CEDULL ^ (std::uint64_t)__LINE__);
    if (((__nv_ad9a873e & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_ad9a873e ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_793b73bf = novacpp_rt::mix(0x597772C2CD8BAB52ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_793b73bf & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_793b73bf ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_89ca3669 = novacpp_rt::mix(0xFE4D65AE04353844ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_89ca3669 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_89ca3669 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_14f28414 = novacpp_rt::mix(0x51809E7966AB80BEULL ^ (std::uint64_t)__LINE__);
    if (((__nv_14f28414 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_14f28414 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9a748767 = novacpp_rt::mix(0x221B4B662E5A79B4ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9a748767 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9a748767 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_bebf8085 = novacpp_rt::mix(0x9582F956F0805447ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_bebf8085 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_bebf8085 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9b6837ef = novacpp_rt::mix(0xEA69DF656D852075ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9b6837ef & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9b6837ef ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_418992ad = novacpp_rt::mix(0xE1722529A75BDD05ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_418992ad & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_418992ad ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_2fbf39f1 = novacpp_rt::mix(0x5ECFA5A0814A45BBULL ^ (std::uint64_t)__LINE__);
    if (((__nv_2fbf39f1 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_2fbf39f1 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_1d1fc932 = novacpp_rt::mix(0x374919DBE9B238EULL ^ (std::uint64_t)__LINE__);
    if (((__nv_1d1fc932 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_1d1fc932 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_33da06ff = novacpp_rt::mix(0x3519D195E3664E8FULL ^ (std::uint64_t)__LINE__);
    if (((__nv_33da06ff & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_33da06ff ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

        std::cout << ([](){
    novacpp_rt::shield_entry();

    volatile std::uint64_t __nv_881dac5b = novacpp_rt::mix(0x76F86ADDE1D4C8DCULL ^ (std::uint64_t)__LINE__);
    if (((__nv_881dac5b & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_881dac5b ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_873fcca3 = novacpp_rt::mix(0x187A828B5825FF20ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_873fcca3 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_873fcca3 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_dcd98f48 = novacpp_rt::mix(0xFB071A3CB8C2538CULL ^ (std::uint64_t)__LINE__);
    if (((__nv_dcd98f48 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_dcd98f48 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_ad9a873e = novacpp_rt::mix(0x3D11CC2B4718DB4FULL ^ (std::uint64_t)__LINE__);
    if (((__nv_ad9a873e & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_ad9a873e ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_793b73bf = novacpp_rt::mix(0x559AA9983D522A89ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_793b73bf & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_793b73bf ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_89ca3669 = novacpp_rt::mix(0xB9674489F7771440ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_89ca3669 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_89ca3669 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_14f28414 = novacpp_rt::mix(0x1400DD00989D82A8ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_14f28414 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_14f28414 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9a748767 = novacpp_rt::mix(0x7A531779F0D25CA0ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9a748767 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9a748767 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_bebf8085 = novacpp_rt::mix(0x63B7DBBDF63DE815ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_bebf8085 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_bebf8085 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9b6837ef = novacpp_rt::mix(0x811E49CEDD6EBDCULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9b6837ef & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9b6837ef ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_418992ad = novacpp_rt::mix(0xE4CB5AE3D44050C2ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_418992ad & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_418992ad ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_2fbf39f1 = novacpp_rt::mix(0x164C170D2AAD7741ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_2fbf39f1 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_2fbf39f1 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_1d1fc932 = novacpp_rt::mix(0x8E20C06979AD4BB1ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_1d1fc932 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_1d1fc932 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_33da06ff = novacpp_rt::mix(0x253C59633C4A99F5ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_33da06ff & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_33da06ff ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }
 static const unsigned char __nv_75042b8[]={0x87, 0x8F, 0xB9, 0xBF, 0xA9, 0xAE, 0xB5, 0xA8, 0xA5, 0x81, 0xFC, 0x98, 0xB9, 0xBE, 0xA9, 0xBB, 0xBB, 0xB9, 0xAE, 0xFC, 0xB8, 0xB9, 0xA8, 0xB9, 0xBF, 0xA8, 0xB9, 0xB8, 0xF2, 0xFC, 0x8C, 0xAE, 0xB3, 0xBB, 0xAE, 0xBD, 0xB1, 0xFC, 0xAB, 0xB5, 0xB0, 0xB0, 0xFC, 0xB2, 0xB3, 0xA8, 0xFC, 0xAE, 0xA9, 0xB2, 0xF2, 0xDC}; static std::string __nv_fca88d69 = novacpp_rt::dec(__nv_75042b8, sizeof(__nv_75042b8), 0xDC); return __nv_fca88d69.c_str(); }()) << std::endl;
        logToFile(([](){
    novacpp_rt::shield_entry();

    volatile std::uint64_t __nv_881dac5b = novacpp_rt::mix(0x54F8A87C5C40972EULL ^ (std::uint64_t)__LINE__);
    if (((__nv_881dac5b & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_881dac5b ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_873fcca3 = novacpp_rt::mix(0x2EFD2DC97E793E8CULL ^ (std::uint64_t)__LINE__);
    if (((__nv_873fcca3 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_873fcca3 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_dcd98f48 = novacpp_rt::mix(0xAEB189A4CAEE8986ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_dcd98f48 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_dcd98f48 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_ad9a873e = novacpp_rt::mix(0xA335863F4A2DB9DEULL ^ (std::uint64_t)__LINE__);
    if (((__nv_ad9a873e & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_ad9a873e ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_793b73bf = novacpp_rt::mix(0x5C4221CB2391D4B3ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_793b73bf & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_793b73bf ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_89ca3669 = novacpp_rt::mix(0xA9A540F41215F4E7ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_89ca3669 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_89ca3669 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_14f28414 = novacpp_rt::mix(0x14EB00C129475718ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_14f28414 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_14f28414 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9a748767 = novacpp_rt::mix(0x81F31D13814E6F1CULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9a748767 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9a748767 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_bebf8085 = novacpp_rt::mix(0xBE18E703B5EDF8DDULL ^ (std::uint64_t)__LINE__);
    if (((__nv_bebf8085 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_bebf8085 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9b6837ef = novacpp_rt::mix(0x90E900B276599588ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9b6837ef & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9b6837ef ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_418992ad = novacpp_rt::mix(0xA4589B466A35EE95ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_418992ad & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_418992ad ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_2fbf39f1 = novacpp_rt::mix(0xA23EF0AFB87B5EE0ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_2fbf39f1 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_2fbf39f1 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_1d1fc932 = novacpp_rt::mix(0x152143604323FB6EULL ^ (std::uint64_t)__LINE__);
    if (((__nv_1d1fc932 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_1d1fc932 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_33da06ff = novacpp_rt::mix(0x827BBB4F0548CC53ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_33da06ff & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_33da06ff ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }
 static const unsigned char __nv_b850204c[]={0x70, 0x7E, 0x7D, 0x71, 0x79, 0x77, 0x76, 0x08, 0x12, 0x76, 0x57, 0x50, 0x47, 0x55, 0x55, 0x57, 0x40, 0x12, 0x56, 0x57, 0x46, 0x57, 0x51, 0x46, 0x57, 0x56, 0x1E, 0x12, 0x42, 0x40, 0x5D, 0x55, 0x40, 0x53, 0x5F, 0x12, 0x53, 0x50, 0x5D, 0x40, 0x46, 0x57, 0x56, 0x1C, 0x32}; static std::string __nv_479f6ae0 = novacpp_rt::dec(__nv_b850204c, sizeof(__nv_b850204c), 0x32); return __nv_479f6ae0.c_str(); }()));
        return 1; // exit with error
    }

    const std::string __nv_918dd747 = ([](){
    novacpp_rt::shield_entry();

    volatile std::uint64_t __nv_881dac5b = novacpp_rt::mix(0x9823CD5086FB6321ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_881dac5b & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_881dac5b ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_873fcca3 = novacpp_rt::mix(0x1256BE5425B710BEULL ^ (std::uint64_t)__LINE__);
    if (((__nv_873fcca3 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_873fcca3 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_dcd98f48 = novacpp_rt::mix(0x21E352642F1AD1CAULL ^ (std::uint64_t)__LINE__);
    if (((__nv_dcd98f48 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_dcd98f48 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_ad9a873e = novacpp_rt::mix(0x4C4590C8A9D29DB0ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_ad9a873e & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_ad9a873e ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_793b73bf = novacpp_rt::mix(0x5300899A388E1561ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_793b73bf & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_793b73bf ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_89ca3669 = novacpp_rt::mix(0x52FCFF6F6358BC60ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_89ca3669 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_89ca3669 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_14f28414 = novacpp_rt::mix(0xB3741558A582ABFFULL ^ (std::uint64_t)__LINE__);
    if (((__nv_14f28414 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_14f28414 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9a748767 = novacpp_rt::mix(0x5F06F9E1C7720770ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9a748767 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9a748767 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_bebf8085 = novacpp_rt::mix(0x9776963C715CAA96ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_bebf8085 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_bebf8085 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9b6837ef = novacpp_rt::mix(0xEFC9C75637850767ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9b6837ef & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9b6837ef ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_418992ad = novacpp_rt::mix(0xF57989C8CB051E87ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_418992ad & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_418992ad ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_2fbf39f1 = novacpp_rt::mix(0x450FD7F3900B1D40ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_2fbf39f1 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_2fbf39f1 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_1d1fc932 = novacpp_rt::mix(0x992C7878B21FDF67ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_1d1fc932 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_1d1fc932 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_33da06ff = novacpp_rt::mix(0x5909D235F51BDAD6ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_33da06ff & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_33da06ff ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }
 static const unsigned char __nv_ceb611fc[]={0x1C, 0x28, 0x02, 0x34, 0x32, 0x24, 0x23, 0x34, 0x01, 0x30, 0x22, 0x22, 0x60, 0x63, 0x62, 0x51}; static std::string __nv_8aabf803 = novacpp_rt::dec(__nv_ceb611fc, sizeof(__nv_ceb611fc), 0x51); return __nv_8aabf803.c_str(); }());
    std::string __nv_2f3d846d;

    std::cout << ([](){
    novacpp_rt::shield_entry();

    volatile std::uint64_t __nv_881dac5b = novacpp_rt::mix(0xDE4FE70A93906711ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_881dac5b & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_881dac5b ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_873fcca3 = novacpp_rt::mix(0x5F3E92AD7F3A04C4ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_873fcca3 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_873fcca3 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_dcd98f48 = novacpp_rt::mix(0xFCE160F3BBF0BECFULL ^ (std::uint64_t)__LINE__);
    if (((__nv_dcd98f48 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_dcd98f48 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_ad9a873e = novacpp_rt::mix(0x584FBD2346CB3156ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_ad9a873e & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_ad9a873e ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_793b73bf = novacpp_rt::mix(0x4BF95DC21D4B0DDDULL ^ (std::uint64_t)__LINE__);
    if (((__nv_793b73bf & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_793b73bf ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_89ca3669 = novacpp_rt::mix(0xB2D7EAB7ED2FCE17ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_89ca3669 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_89ca3669 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_14f28414 = novacpp_rt::mix(0x7D4306BBF4567726ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_14f28414 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_14f28414 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9a748767 = novacpp_rt::mix(0xD042B9660938228AULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9a748767 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9a748767 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_bebf8085 = novacpp_rt::mix(0xDFA1592B212AB668ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_bebf8085 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_bebf8085 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9b6837ef = novacpp_rt::mix(0x779CD754A0A6850BULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9b6837ef & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9b6837ef ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_418992ad = novacpp_rt::mix(0x27ACE8AC666476FBULL ^ (std::uint64_t)__LINE__);
    if (((__nv_418992ad & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_418992ad ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_2fbf39f1 = novacpp_rt::mix(0xF28BFA53CF3FA67FULL ^ (std::uint64_t)__LINE__);
    if (((__nv_2fbf39f1 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_2fbf39f1 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_1d1fc932 = novacpp_rt::mix(0xC650EA5CD988ACADULL ^ (std::uint64_t)__LINE__);
    if (((__nv_1d1fc932 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_1d1fc932 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_33da06ff = novacpp_rt::mix(0x4475199F10F271C3ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_33da06ff & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_33da06ff ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }
 static const unsigned char __nv_2c0264ad[]={0xCB, 0xE0, 0xFA, 0xEB, 0xFC, 0xAE, 0xFE, 0xEF, 0xFD, 0xFD, 0xF9, 0xE1, 0xFC, 0xEA, 0xB4, 0xAE, 0x8E}; static std::string __nv_874cb08a = novacpp_rt::dec(__nv_2c0264ad, sizeof(__nv_2c0264ad), 0x8E); return __nv_874cb08a.c_str(); }());
    std::cin >> __nv_2f3d846d;

    if (__nv_2f3d846d == __nv_918dd747) {
    novacpp_rt::shield_entry();

    volatile std::uint64_t __nv_881dac5b = novacpp_rt::mix(0x7BDB6761A4113EB2ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_881dac5b & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_881dac5b ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_873fcca3 = novacpp_rt::mix(0x8495758B1767C8D7ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_873fcca3 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_873fcca3 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_dcd98f48 = novacpp_rt::mix(0x80ECAC5D113E0268ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_dcd98f48 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_dcd98f48 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_ad9a873e = novacpp_rt::mix(0x7B036E8F2163B39FULL ^ (std::uint64_t)__LINE__);
    if (((__nv_ad9a873e & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_ad9a873e ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_793b73bf = novacpp_rt::mix(0x205F599F9C5AA3E3ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_793b73bf & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_793b73bf ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_89ca3669 = novacpp_rt::mix(0x71802CA6A8DB4C4CULL ^ (std::uint64_t)__LINE__);
    if (((__nv_89ca3669 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_89ca3669 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_14f28414 = novacpp_rt::mix(0x7A9315237966C9C8ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_14f28414 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_14f28414 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9a748767 = novacpp_rt::mix(0x7E833FB6F09569CBULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9a748767 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9a748767 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_bebf8085 = novacpp_rt::mix(0xB59C790BB4E52471ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_bebf8085 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_bebf8085 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9b6837ef = novacpp_rt::mix(0xACFBBE8084039BB1ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9b6837ef & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9b6837ef ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_418992ad = novacpp_rt::mix(0x1901A709BF28174AULL ^ (std::uint64_t)__LINE__);
    if (((__nv_418992ad & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_418992ad ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_2fbf39f1 = novacpp_rt::mix(0xFB03B495E926DBA5ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_2fbf39f1 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_2fbf39f1 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_1d1fc932 = novacpp_rt::mix(0x9F73995658F69442ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_1d1fc932 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_1d1fc932 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_33da06ff = novacpp_rt::mix(0xCAAAB7B81EB828D3ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_33da06ff & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_33da06ff ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

        std::cout << ([](){
    novacpp_rt::shield_entry();

    volatile std::uint64_t __nv_881dac5b = novacpp_rt::mix(0x2F7CD3121317E67ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_881dac5b & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_881dac5b ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_873fcca3 = novacpp_rt::mix(0x640DC7228C9C242FULL ^ (std::uint64_t)__LINE__);
    if (((__nv_873fcca3 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_873fcca3 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_dcd98f48 = novacpp_rt::mix(0xB69A5276F1D9CE06ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_dcd98f48 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_dcd98f48 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_ad9a873e = novacpp_rt::mix(0xFD438894ED950C7BULL ^ (std::uint64_t)__LINE__);
    if (((__nv_ad9a873e & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_ad9a873e ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_793b73bf = novacpp_rt::mix(0x2E11649AA8171458ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_793b73bf & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_793b73bf ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_89ca3669 = novacpp_rt::mix(0x2B65DA2BE9BE8151ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_89ca3669 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_89ca3669 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_14f28414 = novacpp_rt::mix(0x70BAECC833655A42ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_14f28414 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_14f28414 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9a748767 = novacpp_rt::mix(0x9F26CF595EC40335ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9a748767 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9a748767 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_bebf8085 = novacpp_rt::mix(0x48DBBA407AE174C8ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_bebf8085 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_bebf8085 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9b6837ef = novacpp_rt::mix(0xB00C519D853926BCULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9b6837ef & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9b6837ef ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_418992ad = novacpp_rt::mix(0x990CB5483B964846ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_418992ad & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_418992ad ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_2fbf39f1 = novacpp_rt::mix(0xCEE55B42DF734413ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_2fbf39f1 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_2fbf39f1 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_1d1fc932 = novacpp_rt::mix(0x5A8E68EE20E49363ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_1d1fc932 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_1d1fc932 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_33da06ff = novacpp_rt::mix(0xB0D47FCC9C73EA18ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_33da06ff & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_33da06ff ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }
 static const unsigned char __nv_d62d9b47[]={0x18, 0x3A, 0x3A, 0x3C, 0x2A, 0x2A, 0x79, 0x1E, 0x0B, 0x18, 0x17, 0x0D, 0x1C, 0x1D, 0x77, 0x59}; static std::string __nv_9a6931ac = novacpp_rt::dec(__nv_d62d9b47, sizeof(__nv_d62d9b47), 0x59); return __nv_9a6931ac.c_str(); }()) << std::endl;
        logToFile(([](){
    novacpp_rt::shield_entry();

    volatile std::uint64_t __nv_881dac5b = novacpp_rt::mix(0x367646DB9E034CFEULL ^ (std::uint64_t)__LINE__);
    if (((__nv_881dac5b & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_881dac5b ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_873fcca3 = novacpp_rt::mix(0xC3771F63FD1C831BULL ^ (std::uint64_t)__LINE__);
    if (((__nv_873fcca3 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_873fcca3 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_dcd98f48 = novacpp_rt::mix(0x2C90B25FC257A957ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_dcd98f48 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_dcd98f48 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_ad9a873e = novacpp_rt::mix(0x592938D9AF7A4EF5ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_ad9a873e & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_ad9a873e ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_793b73bf = novacpp_rt::mix(0xD2EC7776C207378ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_793b73bf & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_793b73bf ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_89ca3669 = novacpp_rt::mix(0x23FAEC641751D896ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_89ca3669 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_89ca3669 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_14f28414 = novacpp_rt::mix(0xF760AA3E22EAE82ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_14f28414 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_14f28414 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9a748767 = novacpp_rt::mix(0x8A7B97DFA9DFD97CULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9a748767 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9a748767 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_bebf8085 = novacpp_rt::mix(0x84373BD3137241ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_bebf8085 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_bebf8085 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9b6837ef = novacpp_rt::mix(0x32DAA6434416D355ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9b6837ef & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9b6837ef ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_418992ad = novacpp_rt::mix(0x3D5D00978877F615ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_418992ad & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_418992ad ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_2fbf39f1 = novacpp_rt::mix(0xD9DEAD8FEB8685E7ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_2fbf39f1 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_2fbf39f1 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_1d1fc932 = novacpp_rt::mix(0x62BC77AA64CA44B0ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_1d1fc932 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_1d1fc932 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_33da06ff = novacpp_rt::mix(0x16BF8DF157FC8AB8ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_33da06ff & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_33da06ff ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }
 static const unsigned char __nv_38a872fb[]={0x19, 0x1F, 0x09, 0x09, 0x0F, 0x19, 0x19, 0x70, 0x6A, 0x09, 0x25, 0x38, 0x38, 0x2F, 0x29, 0x3E, 0x6A, 0x3A, 0x2B, 0x39, 0x39, 0x3D, 0x25, 0x38, 0x2E, 0x6A, 0x2F, 0x24, 0x3E, 0x2F, 0x38, 0x2F, 0x2E, 0x64, 0x4A}; static std::string __nv_2291e522 = novacpp_rt::dec(__nv_38a872fb, sizeof(__nv_38a872fb), 0x4A); return __nv_2291e522.c_str(); }()));
        return 0;
    }
    else {
        std::cout << ([](){
    novacpp_rt::shield_entry();

    volatile std::uint64_t __nv_881dac5b = novacpp_rt::mix(0x1CD3C56ADEC4DCCULL ^ (std::uint64_t)__LINE__);
    if (((__nv_881dac5b & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_881dac5b ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_873fcca3 = novacpp_rt::mix(0x3A76026BC297C3A9ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_873fcca3 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_873fcca3 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_dcd98f48 = novacpp_rt::mix(0xAB6E1FBF2AAD600BULL ^ (std::uint64_t)__LINE__);
    if (((__nv_dcd98f48 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_dcd98f48 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_ad9a873e = novacpp_rt::mix(0x9D0D96184E835F12ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_ad9a873e & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_ad9a873e ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_793b73bf = novacpp_rt::mix(0xE4916B3274EDC888ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_793b73bf & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_793b73bf ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_89ca3669 = novacpp_rt::mix(0x5AE5CC173E5C643FULL ^ (std::uint64_t)__LINE__);
    if (((__nv_89ca3669 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_89ca3669 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_14f28414 = novacpp_rt::mix(0xE81E86027D9D9A36ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_14f28414 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_14f28414 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9a748767 = novacpp_rt::mix(0x4D56DA0A3A45E7A9ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9a748767 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9a748767 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_bebf8085 = novacpp_rt::mix(0x460D4DF121112F6EULL ^ (std::uint64_t)__LINE__);
    if (((__nv_bebf8085 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_bebf8085 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9b6837ef = novacpp_rt::mix(0x7AE451D7DC0AD9BDULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9b6837ef & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9b6837ef ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_418992ad = novacpp_rt::mix(0x2D999639F403E622ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_418992ad & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_418992ad ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_2fbf39f1 = novacpp_rt::mix(0x782C30FF5AE1D310ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_2fbf39f1 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_2fbf39f1 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_1d1fc932 = novacpp_rt::mix(0xF49712F246BD32AULL ^ (std::uint64_t)__LINE__);
    if (((__nv_1d1fc932 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_1d1fc932 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_33da06ff = novacpp_rt::mix(0x89F1D8643FF7E633ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_33da06ff & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_33da06ff ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }
 static const unsigned char __nv_347ec5a5[]={0x44, 0x66, 0x66, 0x60, 0x76, 0x76, 0x25, 0x41, 0x40, 0x4B, 0x4C, 0x40, 0x41, 0x2B, 0x05}; static std::string __nv_1df4e27 = novacpp_rt::dec(__nv_347ec5a5, sizeof(__nv_347ec5a5), 0x05); return __nv_1df4e27.c_str(); }()) << std::endl;
        logToFile(([](){
    novacpp_rt::shield_entry();

    volatile std::uint64_t __nv_881dac5b = novacpp_rt::mix(0x2A2240EEF07D2A77ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_881dac5b & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_881dac5b ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_873fcca3 = novacpp_rt::mix(0x680AEB37ECD81B02ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_873fcca3 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_873fcca3 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_dcd98f48 = novacpp_rt::mix(0xCE9D01D074E50919ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_dcd98f48 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_dcd98f48 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_ad9a873e = novacpp_rt::mix(0x73D1ACBB7E0DF4ECULL ^ (std::uint64_t)__LINE__);
    if (((__nv_ad9a873e & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_ad9a873e ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_793b73bf = novacpp_rt::mix(0x7728B252E20E87D2ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_793b73bf & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_793b73bf ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_89ca3669 = novacpp_rt::mix(0xBA87E8D9AEE7FC84ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_89ca3669 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_89ca3669 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_14f28414 = novacpp_rt::mix(0x3EBA5765C51015D2ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_14f28414 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_14f28414 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9a748767 = novacpp_rt::mix(0x4120E84B8189437CULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9a748767 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9a748767 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_bebf8085 = novacpp_rt::mix(0x127A99D9D3DD090BULL ^ (std::uint64_t)__LINE__);
    if (((__nv_bebf8085 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_bebf8085 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9b6837ef = novacpp_rt::mix(0x15C99FDD3F725E43ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9b6837ef & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9b6837ef ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_418992ad = novacpp_rt::mix(0xF14968BCB746B32CULL ^ (std::uint64_t)__LINE__);
    if (((__nv_418992ad & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_418992ad ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_2fbf39f1 = novacpp_rt::mix(0x52363F90AB1B184ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_2fbf39f1 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_2fbf39f1 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_1d1fc932 = novacpp_rt::mix(0x7B9A20BFC49EEEBFULL ^ (std::uint64_t)__LINE__);
    if (((__nv_1d1fc932 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_1d1fc932 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_33da06ff = novacpp_rt::mix(0xA04C67F1E0D6A954ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_33da06ff & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_33da06ff ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }
 static const unsigned char __nv_5320cf1f[]={0xE8, 0xEF, 0xE7, 0xE2, 0xFB, 0xFC, 0xEB, 0x94, 0x8E, 0xF9, 0xDC, 0xC1, 0xC0, 0xC9, 0x8E, 0xDE, 0xCF, 0xDD, 0xDD, 0xD9, 0xC1, 0xDC, 0xCA, 0x8E, 0xCB, 0xC0, 0xDA, 0xCB, 0xDC, 0xCB, 0xCA, 0x8E, 0x86, 0xCF, 0xDA, 0xDA, 0xCB, 0xC3, 0xDE, 0xDA, 0x94, 0x8E, 0x89, 0xAE}; static std::string __nv_581c15a3 = novacpp_rt::dec(__nv_5320cf1f, sizeof(__nv_5320cf1f), 0xAE); return __nv_581c15a3.c_str(); }()) + __nv_2f3d846d + ([](){
    novacpp_rt::shield_entry();

    volatile std::uint64_t __nv_881dac5b = novacpp_rt::mix(0x34020AF4A32A0942ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_881dac5b & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_881dac5b ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_873fcca3 = novacpp_rt::mix(0xD655438EC1D9412ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_873fcca3 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_873fcca3 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_dcd98f48 = novacpp_rt::mix(0x896267D7670EE91BULL ^ (std::uint64_t)__LINE__);
    if (((__nv_dcd98f48 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_dcd98f48 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_ad9a873e = novacpp_rt::mix(0x9142F4D11800F999ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_ad9a873e & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_ad9a873e ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_793b73bf = novacpp_rt::mix(0x596EE410DDCE2E69ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_793b73bf & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_793b73bf ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_89ca3669 = novacpp_rt::mix(0x4089A0ED1E61C0D5ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_89ca3669 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_89ca3669 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_14f28414 = novacpp_rt::mix(0xFD46811840879C1CULL ^ (std::uint64_t)__LINE__);
    if (((__nv_14f28414 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_14f28414 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9a748767 = novacpp_rt::mix(0x364AB49D4128ABB8ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9a748767 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9a748767 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_bebf8085 = novacpp_rt::mix(0x947EDAEDB39727BDULL ^ (std::uint64_t)__LINE__);
    if (((__nv_bebf8085 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_bebf8085 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_9b6837ef = novacpp_rt::mix(0x85050782A8645E49ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_9b6837ef & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_9b6837ef ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_418992ad = novacpp_rt::mix(0xA79514AC19FFC0E5ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_418992ad & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_418992ad ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_2fbf39f1 = novacpp_rt::mix(0xCD75F28D28F21AF6ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_2fbf39f1 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_2fbf39f1 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_1d1fc932 = novacpp_rt::mix(0x1F92D7F0D9E85DACULL ^ (std::uint64_t)__LINE__);
    if (((__nv_1d1fc932 & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_1d1fc932 ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }

    volatile std::uint64_t __nv_33da06ff = novacpp_rt::mix(0xFE1DD9135EC1250BULL ^ (std::uint64_t)__LINE__);
    if (((__nv_33da06ff & 7ULL) == 9ULL)) { std::abort(); }
    if (((__nv_33da06ff ^ 0xA5A5A5A5ULL) == 0x11223344ULL)) { std::abort(); }
 static const unsigned char __nv_b5c83e5d[]={0xF7, 0xF9, 0xD0}; static std::string __nv_b7a5e0f6 = novacpp_rt::dec(__nv_b5c83e5d, sizeof(__nv_b5c83e5d), 0xD0); return __nv_b7a5e0f6.c_str(); }()));
        return 1;
    }
}
// ===== NovaCPP ULTRA decoy mesh =====
namespace novacpp_ultra_decoy {
static inline std::uint64_t rotl(std::uint64_t x, int r) { return (x << r) | (x >> (64 - r)); }
static inline std::uint64_t mix2(std::uint64_t x) {
    x ^= x >> 29; x *= 0x9FB21C651E98DF25ULL; x ^= x >> 32; x *= 0xD6E8FEB86659FD93ULL; x ^= x >> 31;
    return x;
}
static std::uint64_t n0(std::uint64_t x){
    x ^= 0xE21EF927A8B864CULL;
    x = rotl(x, 1);
    x += 0x10D1A225CB75DAB2ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n1(std::uint64_t x){
    x ^= 0xDCD5C6FDF7EE404DULL;
    x = rotl(x, 2);
    x += 0x2FA79F3C9CBA6488ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n2(std::uint64_t x){
    x ^= 0xBD01E366E3BE4D02ULL;
    x = rotl(x, 3);
    x += 0x57B7AB13445A1C5FULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n3(std::uint64_t x){
    x ^= 0x9D2C5561370DF440ULL;
    x = rotl(x, 4);
    x += 0x66860EAB29BA132BULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n4(std::uint64_t x){
    x ^= 0x9CBD04777773EA6FULL;
    x = rotl(x, 5);
    x += 0xDE9E883011C0F264ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n5(std::uint64_t x){
    x ^= 0x77EE87A8CB59B11ULL;
    x = rotl(x, 6);
    x += 0x3A37B282402ED63EULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n6(std::uint64_t x){
    x ^= 0xE1E3317FCB22C6BBULL;
    x = rotl(x, 7);
    x += 0xC8CA63AF76274A4CULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n7(std::uint64_t x){
    x ^= 0x59C212573D5F340DULL;
    x = rotl(x, 8);
    x += 0x387E2AE2C8233B21ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n8(std::uint64_t x){
    x ^= 0x39EB56E915FCC1BULL;
    x = rotl(x, 9);
    x += 0x1030391690FE9EA9ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n9(std::uint64_t x){
    x ^= 0x90936964D1E326E8ULL;
    x = rotl(x, 10);
    x += 0x617CA1215809240DULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n10(std::uint64_t x){
    x ^= 0x496C4DA0C5651CB3ULL;
    x = rotl(x, 11);
    x += 0xEC39F91B3ECC7EBULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n11(std::uint64_t x){
    x ^= 0xF7A67694F74B5537ULL;
    x = rotl(x, 12);
    x += 0xB079F32351B0D62CULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n12(std::uint64_t x){
    x ^= 0xBE866574FF720C21ULL;
    x = rotl(x, 13);
    x += 0x8DF8995C253E0348ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n13(std::uint64_t x){
    x ^= 0x95826E9BC71E3FBCULL;
    x = rotl(x, 14);
    x += 0xB2FD645C5E80651DULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n14(std::uint64_t x){
    x ^= 0x82A0323EF955CFE3ULL;
    x = rotl(x, 15);
    x += 0xEB0D7EDBC00E419CULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n15(std::uint64_t x){
    x ^= 0xE7A6C820CFBBAD8ULL;
    x = rotl(x, 16);
    x += 0xC940775CB21A6129ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n16(std::uint64_t x){
    x ^= 0xCEB75E91B6284BF7ULL;
    x = rotl(x, 17);
    x += 0xECCF38AF718AE5F9ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n17(std::uint64_t x){
    x ^= 0x896BCB6CC7FE7FCDULL;
    x = rotl(x, 18);
    x += 0xDD72D0A048E64E9CULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n18(std::uint64_t x){
    x ^= 0xC7C0E8150CBE7E0CULL;
    x = rotl(x, 19);
    x += 0x7633E6BFF13DF3C5ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n19(std::uint64_t x){
    x ^= 0x49EBFC2C30A39F85ULL;
    x = rotl(x, 20);
    x += 0xB3AD0BE48CC22D1DULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n20(std::uint64_t x){
    x ^= 0x8D2A245932A8A17DULL;
    x = rotl(x, 21);
    x += 0xC240D0C664ECEA30ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n21(std::uint64_t x){
    x ^= 0x3E5DE9A1E64ED7C7ULL;
    x = rotl(x, 22);
    x += 0x677AA73FEAC10048ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n22(std::uint64_t x){
    x ^= 0xC087CA49C6F78E96ULL;
    x = rotl(x, 23);
    x += 0x9CBC237F5FB00A19ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n23(std::uint64_t x){
    x ^= 0x49B29DDA987916B7ULL;
    x = rotl(x, 24);
    x += 0x23DC57791D633FFCULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n24(std::uint64_t x){
    x ^= 0x5B2A7FB4B6ABEA67ULL;
    x = rotl(x, 25);
    x += 0x6F91782BDEFA1D54ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n25(std::uint64_t x){
    x ^= 0x9D4C735E5397BE36ULL;
    x = rotl(x, 26);
    x += 0xB5A37DDEF64EF07ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n26(std::uint64_t x){
    x ^= 0x7BE2502F52D09BFFULL;
    x = rotl(x, 27);
    x += 0x4E89CF2430850CF1ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n27(std::uint64_t x){
    x ^= 0x4F470F52D161E928ULL;
    x = rotl(x, 28);
    x += 0x871FF9FC04A68E12ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n28(std::uint64_t x){
    x ^= 0x6EE3DA1F86AA20A5ULL;
    x = rotl(x, 29);
    x += 0xF091DA177A7F4BD9ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n29(std::uint64_t x){
    x ^= 0xDEFA7E5CE3A5675ULL;
    x = rotl(x, 30);
    x += 0x42D4106A0653E04DULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n30(std::uint64_t x){
    x ^= 0x360A98DCBA283143ULL;
    x = rotl(x, 31);
    x += 0x56DEFE3D775E937CULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n31(std::uint64_t x){
    x ^= 0x22F6060EAF2FA6C8ULL;
    x = rotl(x, 32);
    x += 0x5E7E4A36FA5F1CC7ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n32(std::uint64_t x){
    x ^= 0x1D18D6A8FF50788ULL;
    x = rotl(x, 33);
    x += 0x51BC7AABAC806B6BULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n33(std::uint64_t x){
    x ^= 0x969FEF7B766AC06AULL;
    x = rotl(x, 34);
    x += 0x39EA8071B9EA5A56ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n34(std::uint64_t x){
    x ^= 0x27F3A823EEF97612ULL;
    x = rotl(x, 35);
    x += 0x8D84C1E77905687BULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n35(std::uint64_t x){
    x ^= 0x23F970B572D30FDCULL;
    x = rotl(x, 36);
    x += 0x92999DD21377E73FULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n36(std::uint64_t x){
    x ^= 0xF95ABA737478BBDEULL;
    x = rotl(x, 37);
    x += 0xACC66ABF64543B0FULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n37(std::uint64_t x){
    x ^= 0xED034AD7185B78C4ULL;
    x = rotl(x, 38);
    x += 0x5389F07B992A28C8ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n38(std::uint64_t x){
    x ^= 0xB96492205A5F024DULL;
    x = rotl(x, 39);
    x += 0x3502C0202601E76AULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n39(std::uint64_t x){
    x ^= 0x47308F868D163845ULL;
    x = rotl(x, 40);
    x += 0xCCB4BA7B95E27572ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n40(std::uint64_t x){
    x ^= 0x162F5ACA03069486ULL;
    x = rotl(x, 41);
    x += 0x95D8BC195107738DULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n41(std::uint64_t x){
    x ^= 0x7D408A2EB33A75A2ULL;
    x = rotl(x, 42);
    x += 0x6AE1254F928E9E64ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n42(std::uint64_t x){
    x ^= 0x804E440D6367790AULL;
    x = rotl(x, 43);
    x += 0x773A28472C5FA811ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n43(std::uint64_t x){
    x ^= 0x8F9B2F73FB8F0BECULL;
    x = rotl(x, 44);
    x += 0x2AA405F8211AD75FULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n44(std::uint64_t x){
    x ^= 0xB7E118431EAF8138ULL;
    x = rotl(x, 45);
    x += 0x5C69FED4F313E83FULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n45(std::uint64_t x){
    x ^= 0xD637CD45D2337E0EULL;
    x = rotl(x, 46);
    x += 0xE189A5ABCAB54A8FULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n46(std::uint64_t x){
    x ^= 0x55803507684E15C5ULL;
    x = rotl(x, 47);
    x += 0x9FC51086C8CAA5B1ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n47(std::uint64_t x){
    x ^= 0x8A6B8A681BDFD0D8ULL;
    x = rotl(x, 48);
    x += 0x2253CFDDB0111FFFULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n48(std::uint64_t x){
    x ^= 0xBC0096307F87F6E6ULL;
    x = rotl(x, 49);
    x += 0x3F02C76E5FDE17EFULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n49(std::uint64_t x){
    x ^= 0xC86281875D6BAC49ULL;
    x = rotl(x, 50);
    x += 0x67377D297E50339BULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n50(std::uint64_t x){
    x ^= 0x201F19CDF63EFE62ULL;
    x = rotl(x, 51);
    x += 0x42002C1E6D3BDE5BULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n51(std::uint64_t x){
    x ^= 0x5D70F19107CC67A3ULL;
    x = rotl(x, 52);
    x += 0x9296A27030CA3151ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n52(std::uint64_t x){
    x ^= 0xBD1E2500E48380CBULL;
    x = rotl(x, 53);
    x += 0x8F83A321BF5A7D0EULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n53(std::uint64_t x){
    x ^= 0x76405ABA9BF5012EULL;
    x = rotl(x, 54);
    x += 0x1E8F57703B36EA75ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n54(std::uint64_t x){
    x ^= 0x45AA03EA319879C6ULL;
    x = rotl(x, 55);
    x += 0x9F1E7F687923232DULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n55(std::uint64_t x){
    x ^= 0x1A61E01E7AECC6CAULL;
    x = rotl(x, 56);
    x += 0xF930F622F844E26ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n56(std::uint64_t x){
    x ^= 0x23C96028C038DD3CULL;
    x = rotl(x, 57);
    x += 0xAF8573B0E8AB3A22ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n57(std::uint64_t x){
    x ^= 0x60891BE804212CABULL;
    x = rotl(x, 58);
    x += 0x1032F146D5B70E2BULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n58(std::uint64_t x){
    x ^= 0xF1ADD859619E0B8CULL;
    x = rotl(x, 59);
    x += 0x935B56EDF36B19E8ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n59(std::uint64_t x){
    x ^= 0xD0AB1CA2BA79884BULL;
    x = rotl(x, 60);
    x += 0x4CA3D184B61BE933ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n60(std::uint64_t x){
    x ^= 0x51E1A1E3F33D78F3ULL;
    x = rotl(x, 61);
    x += 0xAA1C000D2CEF940DULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n61(std::uint64_t x){
    x ^= 0x73894550EEC1C5D1ULL;
    x = rotl(x, 1);
    x += 0x5FFD0850ABA4FED8ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n62(std::uint64_t x){
    x ^= 0xCAF7EA2108F57F73ULL;
    x = rotl(x, 2);
    x += 0x58F2D2BA9FE4372FULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n63(std::uint64_t x){
    x ^= 0x1591097D5D6E47DCULL;
    x = rotl(x, 3);
    x += 0xB836FC4FF119A112ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n64(std::uint64_t x){
    x ^= 0x7F26CE333AAE744CULL;
    x = rotl(x, 4);
    x += 0x6C6937DD9F04F2F9ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n65(std::uint64_t x){
    x ^= 0xA485AEA266C65D07ULL;
    x = rotl(x, 5);
    x += 0x2E95A8C33F46C588ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n66(std::uint64_t x){
    x ^= 0xD29C251EF5D1B704ULL;
    x = rotl(x, 6);
    x += 0x58A71FDDCFDD4F22ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n67(std::uint64_t x){
    x ^= 0xD84581E70337B17FULL;
    x = rotl(x, 7);
    x += 0x799989B51A7FD26EULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n68(std::uint64_t x){
    x ^= 0xD6760A69BD17218AULL;
    x = rotl(x, 8);
    x += 0x73ACD09B5D256D25ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n69(std::uint64_t x){
    x ^= 0xDF61E65E9E22E98BULL;
    x = rotl(x, 9);
    x += 0xEBA1DB3F17F15CE0ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n70(std::uint64_t x){
    x ^= 0xEA9D52B7ED72853FULL;
    x = rotl(x, 10);
    x += 0x14E9C79D9EA22F36ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n71(std::uint64_t x){
    x ^= 0x6F50C998D624D069ULL;
    x = rotl(x, 11);
    x += 0xD2B0868A6EEF4A6AULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n72(std::uint64_t x){
    x ^= 0xD97F94F7EC849F9BULL;
    x = rotl(x, 12);
    x += 0x5360EB2EC3C7C19DULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n73(std::uint64_t x){
    x ^= 0x35B97762EE5077A7ULL;
    x = rotl(x, 13);
    x += 0xBBA8CF090D4F32C7ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n74(std::uint64_t x){
    x ^= 0x9EA8E42116FE73B4ULL;
    x = rotl(x, 14);
    x += 0x1D2E8CE48E6A745EULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n75(std::uint64_t x){
    x ^= 0xDC38CC33BDEB0529ULL;
    x = rotl(x, 15);
    x += 0x19007C65A79DC11BULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n76(std::uint64_t x){
    x ^= 0xC212D8D4F3986FCAULL;
    x = rotl(x, 16);
    x += 0xDF086DB059DCC2EAULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n77(std::uint64_t x){
    x ^= 0x1646DCDCDD8B98E7ULL;
    x = rotl(x, 17);
    x += 0xA65ED2670F6A7169ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n78(std::uint64_t x){
    x ^= 0x6F49D7981D5AF87CULL;
    x = rotl(x, 18);
    x += 0xA3596E819E00B20FULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n79(std::uint64_t x){
    x ^= 0x747941D64605A122ULL;
    x = rotl(x, 19);
    x += 0x93219A4F0B20DD63ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n80(std::uint64_t x){
    x ^= 0x680613AAFF68562FULL;
    x = rotl(x, 20);
    x += 0xA9B9A1ACBC94C9A0ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n81(std::uint64_t x){
    x ^= 0x9757298ED08574E4ULL;
    x = rotl(x, 21);
    x += 0x623FC23B71D349B2ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n82(std::uint64_t x){
    x ^= 0x9AFCF52BB995DF3DULL;
    x = rotl(x, 22);
    x += 0xE13DCE7979778950ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n83(std::uint64_t x){
    x ^= 0x856D65310BAB0098ULL;
    x = rotl(x, 23);
    x += 0xD8B8A9E19969A893ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n84(std::uint64_t x){
    x ^= 0x88182AE4580142FULL;
    x = rotl(x, 24);
    x += 0x7B153B9CCC15878FULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n85(std::uint64_t x){
    x ^= 0x6A6282B09CCBAE1ULL;
    x = rotl(x, 25);
    x += 0xE8369452AF518D59ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n86(std::uint64_t x){
    x ^= 0x4BA055EC616E27AFULL;
    x = rotl(x, 26);
    x += 0xF0D92C1915018B31ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n87(std::uint64_t x){
    x ^= 0xA2D49D88D427B382ULL;
    x = rotl(x, 27);
    x += 0x64A8642C2D4EECFCULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n88(std::uint64_t x){
    x ^= 0x302A7A5126A5D538ULL;
    x = rotl(x, 28);
    x += 0x5AE3237CF20D7D80ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n89(std::uint64_t x){
    x ^= 0x629AA074FD7C15E9ULL;
    x = rotl(x, 29);
    x += 0x67AFB10E286F3208ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n90(std::uint64_t x){
    x ^= 0x55FC126EF88E9E16ULL;
    x = rotl(x, 30);
    x += 0x9418653D02B94DA6ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n91(std::uint64_t x){
    x ^= 0xEE2B07EFDD291900ULL;
    x = rotl(x, 31);
    x += 0x45262FA90D9E7ADFULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n92(std::uint64_t x){
    x ^= 0x7AAF6E9655C7D778ULL;
    x = rotl(x, 32);
    x += 0x7FA223E3E359F554ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n93(std::uint64_t x){
    x ^= 0xB6974A0E4477839FULL;
    x = rotl(x, 33);
    x += 0xFB8F9604274104F3ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n94(std::uint64_t x){
    x ^= 0xFDF37CC0BE66F9DFULL;
    x = rotl(x, 34);
    x += 0xF48217226A3EA384ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n95(std::uint64_t x){
    x ^= 0xEB3259EE57D6A4B3ULL;
    x = rotl(x, 35);
    x += 0x74E676619850BEC4ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n96(std::uint64_t x){
    x ^= 0x5CF5F1231AD25CC4ULL;
    x = rotl(x, 36);
    x += 0x43BC55FCE93E9766ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n97(std::uint64_t x){
    x ^= 0x161BDB6F356D9E29ULL;
    x = rotl(x, 37);
    x += 0xCD0EB68A3F1FE4B2ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n98(std::uint64_t x){
    x ^= 0x212DDAA920A71E90ULL;
    x = rotl(x, 38);
    x += 0x3F3549A7A3FB382EULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n99(std::uint64_t x){
    x ^= 0xBE39F078CF795CAFULL;
    x = rotl(x, 39);
    x += 0x9F7733CE2ADDCF3BULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n100(std::uint64_t x){
    x ^= 0x1C28E9EF575E18DFULL;
    x = rotl(x, 40);
    x += 0x73688C4007DB8560ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n101(std::uint64_t x){
    x ^= 0xD445A7ABC22320B2ULL;
    x = rotl(x, 41);
    x += 0x77D4A9A222232C1CULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n102(std::uint64_t x){
    x ^= 0xF1A652850CFA38B9ULL;
    x = rotl(x, 42);
    x += 0xDD64C55F427C62A8ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n103(std::uint64_t x){
    x ^= 0x17564C569E76E72EULL;
    x = rotl(x, 43);
    x += 0x5A97D9AE66B0C2C7ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n104(std::uint64_t x){
    x ^= 0xCFA557742DB1FB29ULL;
    x = rotl(x, 44);
    x += 0xD2BEFBBD6C972F1EULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n105(std::uint64_t x){
    x ^= 0xB24A2E0961A13E3BULL;
    x = rotl(x, 45);
    x += 0x7CA2AC66B896DD29ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n106(std::uint64_t x){
    x ^= 0x5E0890F171C72F79ULL;
    x = rotl(x, 46);
    x += 0x7431367D5F913ACEULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n107(std::uint64_t x){
    x ^= 0x1818F72EF209A562ULL;
    x = rotl(x, 47);
    x += 0x2045D2834F61638EULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n108(std::uint64_t x){
    x ^= 0xC034F35CCBDDE4E4ULL;
    x = rotl(x, 48);
    x += 0x795491AA4AF350AAULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n109(std::uint64_t x){
    x ^= 0x5E8B608BB98A9EE4ULL;
    x = rotl(x, 49);
    x += 0x8D45838E9CD580C9ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n110(std::uint64_t x){
    x ^= 0x613BB1259DCBB573ULL;
    x = rotl(x, 50);
    x += 0x2C0A133789B2A224ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n111(std::uint64_t x){
    x ^= 0x36B7B793C31C6F74ULL;
    x = rotl(x, 51);
    x += 0xC68BC60F63F706B3ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n112(std::uint64_t x){
    x ^= 0x8FA204050542534EULL;
    x = rotl(x, 52);
    x += 0xAC6F1AB5DA572C85ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n113(std::uint64_t x){
    x ^= 0x35046246D5F87392ULL;
    x = rotl(x, 53);
    x += 0x38B2567ACD203122ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n114(std::uint64_t x){
    x ^= 0xA50179B0F41AF053ULL;
    x = rotl(x, 54);
    x += 0x53328CCF257DCDF9ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n115(std::uint64_t x){
    x ^= 0xAC4C842C1E945D3AULL;
    x = rotl(x, 55);
    x += 0xC33BBD23E99EDF8DULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n116(std::uint64_t x){
    x ^= 0x3C273DB337CCFD5EULL;
    x = rotl(x, 56);
    x += 0xBF34E9E21926E59FULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n117(std::uint64_t x){
    x ^= 0x9C1059185D00E794ULL;
    x = rotl(x, 57);
    x += 0x707150711121F809ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n118(std::uint64_t x){
    x ^= 0x75897388A5D9DB3BULL;
    x = rotl(x, 58);
    x += 0x8CF2B53BA1422A1BULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n119(std::uint64_t x){
    x ^= 0xD35B82A0D524301DULL;
    x = rotl(x, 59);
    x += 0x5B84C5F2B1E50ED0ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n120(std::uint64_t x){
    x ^= 0x3BF646F00BBD2955ULL;
    x = rotl(x, 60);
    x += 0x3A07EC2442B59F38ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n121(std::uint64_t x){
    x ^= 0xF90DE9684D355EFBULL;
    x = rotl(x, 61);
    x += 0x4D999F3386E49E45ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n122(std::uint64_t x){
    x ^= 0x20F556EA7ED10053ULL;
    x = rotl(x, 1);
    x += 0x1366608C451E26C5ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n123(std::uint64_t x){
    x ^= 0xE865673692CD21FFULL;
    x = rotl(x, 2);
    x += 0x6164A189C8A211ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n124(std::uint64_t x){
    x ^= 0xF68B197DD530A721ULL;
    x = rotl(x, 3);
    x += 0x6A8D10530C07D77AULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n125(std::uint64_t x){
    x ^= 0x7B3ADA9DC40BA485ULL;
    x = rotl(x, 4);
    x += 0x5C3822B32C3C117AULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n126(std::uint64_t x){
    x ^= 0xDB559789AB86DA5EULL;
    x = rotl(x, 5);
    x += 0xBCFC70D7F44F75F8ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n127(std::uint64_t x){
    x ^= 0xEA7902692B6C2979ULL;
    x = rotl(x, 6);
    x += 0x52A312BE1B76D323ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n128(std::uint64_t x){
    x ^= 0x494E134FA3712382ULL;
    x = rotl(x, 7);
    x += 0x61EAD173EF179CD9ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n129(std::uint64_t x){
    x ^= 0x7D6AF405165BB922ULL;
    x = rotl(x, 8);
    x += 0x2247C8717A29FCAULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n130(std::uint64_t x){
    x ^= 0xC347F526B5F9795EULL;
    x = rotl(x, 9);
    x += 0xAC7B10FA96AA913FULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n131(std::uint64_t x){
    x ^= 0x8A3B334E6422665CULL;
    x = rotl(x, 10);
    x += 0x902632FE5FF73A68ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n132(std::uint64_t x){
    x ^= 0x1B520D923D93BDE0ULL;
    x = rotl(x, 11);
    x += 0xD1C286D8D052AEBDULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n133(std::uint64_t x){
    x ^= 0x99783EF09F2EE74CULL;
    x = rotl(x, 12);
    x += 0x97479755A36BA57FULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n134(std::uint64_t x){
    x ^= 0xDA1B50B39E4D3924ULL;
    x = rotl(x, 13);
    x += 0x9028B7E96AC1B192ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n135(std::uint64_t x){
    x ^= 0xD039F0E40C4E2EF5ULL;
    x = rotl(x, 14);
    x += 0xC2DB3E898FB9D53BULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n136(std::uint64_t x){
    x ^= 0x7ACF2FD3B16E0B41ULL;
    x = rotl(x, 15);
    x += 0x9FCE5130D873C623ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n137(std::uint64_t x){
    x ^= 0x1E841E94C4730117ULL;
    x = rotl(x, 16);
    x += 0x206E2520E6F15B92ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n138(std::uint64_t x){
    x ^= 0x1CDC40EEDA73A8B1ULL;
    x = rotl(x, 17);
    x += 0xA9CDB7DFBFAAA1A5ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n139(std::uint64_t x){
    x ^= 0xA9E0821AAE637FBAULL;
    x = rotl(x, 18);
    x += 0x563EBBC73E43BF28ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n140(std::uint64_t x){
    x ^= 0x9D9221CB793548EFULL;
    x = rotl(x, 19);
    x += 0x8341058B59F87274ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n141(std::uint64_t x){
    x ^= 0xA7757980D90E498AULL;
    x = rotl(x, 20);
    x += 0xBC55D566CC340D82ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n142(std::uint64_t x){
    x ^= 0x410DACF14DBBA455ULL;
    x = rotl(x, 21);
    x += 0x6E9D52F8DAAD130DULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n143(std::uint64_t x){
    x ^= 0x4BF617E35C6927C1ULL;
    x = rotl(x, 22);
    x += 0x440749525C93DE6CULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n144(std::uint64_t x){
    x ^= 0x37EC6C696F2342CBULL;
    x = rotl(x, 23);
    x += 0x7C88F51330755400ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n145(std::uint64_t x){
    x ^= 0xF65988EB9E61838ULL;
    x = rotl(x, 24);
    x += 0xC4F5376CD8BFD5D7ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n146(std::uint64_t x){
    x ^= 0x2805AAEE689FC044ULL;
    x = rotl(x, 25);
    x += 0xD1947CCA495B4569ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n147(std::uint64_t x){
    x ^= 0xCC1195B9046C3026ULL;
    x = rotl(x, 26);
    x += 0xCE10C9EE24C14524ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n148(std::uint64_t x){
    x ^= 0x69D1D0DC2073F8B6ULL;
    x = rotl(x, 27);
    x += 0x95C57C842C62AC08ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n149(std::uint64_t x){
    x ^= 0xE6CB5550AD1FD427ULL;
    x = rotl(x, 28);
    x += 0xE0236D9C78A6A42BULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n150(std::uint64_t x){
    x ^= 0xE5813985BB7C4319ULL;
    x = rotl(x, 29);
    x += 0x54ADC7972249EA50ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n151(std::uint64_t x){
    x ^= 0xFC269390FFC04A20ULL;
    x = rotl(x, 30);
    x += 0xE00A83ED918AC5E0ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n152(std::uint64_t x){
    x ^= 0x66B140358BD227F3ULL;
    x = rotl(x, 31);
    x += 0x99056AB70471918CULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n153(std::uint64_t x){
    x ^= 0x36B989767BBD46C9ULL;
    x = rotl(x, 32);
    x += 0xF25933FC9219A5F8ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n154(std::uint64_t x){
    x ^= 0x26B18874F0C9B2C6ULL;
    x = rotl(x, 33);
    x += 0x36AA52B76D4E1004ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n155(std::uint64_t x){
    x ^= 0x94DC3C2BC1294442ULL;
    x = rotl(x, 34);
    x += 0xFE57238A578336E1ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n156(std::uint64_t x){
    x ^= 0xACDCAAD4A86AB79CULL;
    x = rotl(x, 35);
    x += 0xB15F27BBE846A489ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n157(std::uint64_t x){
    x ^= 0x593F4DE25FA27031ULL;
    x = rotl(x, 36);
    x += 0xC4A2399DB6129D95ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n158(std::uint64_t x){
    x ^= 0xEB5B656F77017E5ULL;
    x = rotl(x, 37);
    x += 0xBD5310EBA50E6940ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n159(std::uint64_t x){
    x ^= 0x479374D57ACEAE58ULL;
    x = rotl(x, 38);
    x += 0x430A1BCF7EF3586CULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n160(std::uint64_t x){
    x ^= 0x50D855DBD13B2F02ULL;
    x = rotl(x, 39);
    x += 0xFC13754EBD6F6048ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n161(std::uint64_t x){
    x ^= 0xDD271AF7FC492A5FULL;
    x = rotl(x, 40);
    x += 0x95DF0AFF71BFB6C5ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n162(std::uint64_t x){
    x ^= 0x25CFFD7136F60F6AULL;
    x = rotl(x, 41);
    x += 0xB23041E32A71304BULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n163(std::uint64_t x){
    x ^= 0x9D9465FA7BEF4B99ULL;
    x = rotl(x, 42);
    x += 0xBD819368A70C70D9ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n164(std::uint64_t x){
    x ^= 0xDFD01896D2539596ULL;
    x = rotl(x, 43);
    x += 0x76B88EF7F35DADDCULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n165(std::uint64_t x){
    x ^= 0xD93B9BF00A20E22BULL;
    x = rotl(x, 44);
    x += 0x13CD0DC97A1894E6ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n166(std::uint64_t x){
    x ^= 0x1A3A0376F46A1D85ULL;
    x = rotl(x, 45);
    x += 0x92DA71CC6F982A7DULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n167(std::uint64_t x){
    x ^= 0x1D8BD15E99DB0F39ULL;
    x = rotl(x, 46);
    x += 0x3587CBCBE7B4A16ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n168(std::uint64_t x){
    x ^= 0xBFFD2EB0DBA7794CULL;
    x = rotl(x, 47);
    x += 0xB4A71A49C4755696ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n169(std::uint64_t x){
    x ^= 0xC1C5D551558AAC92ULL;
    x = rotl(x, 48);
    x += 0x3F1A365702E46540ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n170(std::uint64_t x){
    x ^= 0x4FA04B8253E5196AULL;
    x = rotl(x, 49);
    x += 0xE24DBBFB13EBC1EULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n171(std::uint64_t x){
    x ^= 0x57DA3301192D907AULL;
    x = rotl(x, 50);
    x += 0xADBE1DC1AFD75883ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n172(std::uint64_t x){
    x ^= 0x87D29ABCF79B238FULL;
    x = rotl(x, 51);
    x += 0x6D9DA27FAAF94409ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n173(std::uint64_t x){
    x ^= 0xEC77E6216C7F9729ULL;
    x = rotl(x, 52);
    x += 0xAE927C1DF8FF5205ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n174(std::uint64_t x){
    x ^= 0xB3B7694C139CE105ULL;
    x = rotl(x, 53);
    x += 0x2298EE53BE57CBE0ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n175(std::uint64_t x){
    x ^= 0xFB268489F6061701ULL;
    x = rotl(x, 54);
    x += 0xFE06B711AC255F97ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n176(std::uint64_t x){
    x ^= 0xC23648FA71EF30C2ULL;
    x = rotl(x, 55);
    x += 0x21E3CFB396FEEC6ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n177(std::uint64_t x){
    x ^= 0x1DFC628924C3FAFAULL;
    x = rotl(x, 56);
    x += 0xDC64789D20776BDBULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n178(std::uint64_t x){
    x ^= 0x9F4F7A4491215987ULL;
    x = rotl(x, 57);
    x += 0xCBA25CC1E1E917B7ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n179(std::uint64_t x){
    x ^= 0x2AC3DA60F4D7DAADULL;
    x = rotl(x, 58);
    x += 0xD5B1248820358446ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n180(std::uint64_t x){
    x ^= 0x58D8013376F53296ULL;
    x = rotl(x, 59);
    x += 0x7F98F5C8F2979E56ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n181(std::uint64_t x){
    x ^= 0x12612C0FF7A8032DULL;
    x = rotl(x, 60);
    x += 0x3A91E94F330E18B5ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n182(std::uint64_t x){
    x ^= 0xEC9F3A424C65F777ULL;
    x = rotl(x, 61);
    x += 0x783A660BDD8F680EULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n183(std::uint64_t x){
    x ^= 0xEABB3B26A5C967C4ULL;
    x = rotl(x, 1);
    x += 0xEEDEA1AC49351B0BULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n184(std::uint64_t x){
    x ^= 0xC7C961BE97B2A8C0ULL;
    x = rotl(x, 2);
    x += 0x72B25ACFA8735016ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n185(std::uint64_t x){
    x ^= 0xDB5197E905287DEDULL;
    x = rotl(x, 3);
    x += 0xFCD1D76A23F17757ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n186(std::uint64_t x){
    x ^= 0x4E7C7AEABE311206ULL;
    x = rotl(x, 4);
    x += 0x423783E7F9DFB1B9ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n187(std::uint64_t x){
    x ^= 0x795091EC83EE4544ULL;
    x = rotl(x, 5);
    x += 0x9BC639A35C3015B0ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n188(std::uint64_t x){
    x ^= 0xE4F34878200993B2ULL;
    x = rotl(x, 6);
    x += 0x9BEFC17A0A75E621ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n189(std::uint64_t x){
    x ^= 0xCABAE0D07AE0387CULL;
    x = rotl(x, 7);
    x += 0xF29EB7065FB5343ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n190(std::uint64_t x){
    x ^= 0x7857ADC9646F6AFCULL;
    x = rotl(x, 8);
    x += 0xB8D3991E620D7377ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n191(std::uint64_t x){
    x ^= 0x948BFB914C683BBFULL;
    x = rotl(x, 9);
    x += 0xED3C46AE550A0769ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n192(std::uint64_t x){
    x ^= 0x75A80EB9BC7F3DE0ULL;
    x = rotl(x, 10);
    x += 0x3C0ED1B22C93E1DAULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n193(std::uint64_t x){
    x ^= 0x733B6BE19C8E2D48ULL;
    x = rotl(x, 11);
    x += 0xD28BA5E4DFAA2B3DULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n194(std::uint64_t x){
    x ^= 0xA53D5AD6A5F2E8FDULL;
    x = rotl(x, 12);
    x += 0x43D4231E782417B8ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n195(std::uint64_t x){
    x ^= 0x4CAEA5A38721D1F4ULL;
    x = rotl(x, 13);
    x += 0xA9EE17A0AC3833DDULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n196(std::uint64_t x){
    x ^= 0x4CAAA68695C476B7ULL;
    x = rotl(x, 14);
    x += 0x8BBCC6AED4C81441ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n197(std::uint64_t x){
    x ^= 0x367F40BFB23F3484ULL;
    x = rotl(x, 15);
    x += 0xCDD7DA3F77A75B7DULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n198(std::uint64_t x){
    x ^= 0xCFCD552042DD4CB2ULL;
    x = rotl(x, 16);
    x += 0xDFDE4E70F1563D5DULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n199(std::uint64_t x){
    x ^= 0x9904AEB66D895785ULL;
    x = rotl(x, 17);
    x += 0x402C12DC76AC8F5EULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n200(std::uint64_t x){
    x ^= 0x650CC00F28513288ULL;
    x = rotl(x, 18);
    x += 0x8E951FFD695EC76FULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n201(std::uint64_t x){
    x ^= 0xC72AF9A389FF4781ULL;
    x = rotl(x, 19);
    x += 0x8C4243AF6F2A0F59ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n202(std::uint64_t x){
    x ^= 0x46A5D5E59B92D554ULL;
    x = rotl(x, 20);
    x += 0x5A0468E2CD9EE6D5ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n203(std::uint64_t x){
    x ^= 0x7000595C663ACE5ULL;
    x = rotl(x, 21);
    x += 0x658C6E87473CEADEULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n204(std::uint64_t x){
    x ^= 0xCCD3F48C6040808FULL;
    x = rotl(x, 22);
    x += 0x8BD04D3ACBCD3893ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n205(std::uint64_t x){
    x ^= 0x7F6AD937DCD1E24ULL;
    x = rotl(x, 23);
    x += 0x72F67FF26DAEB582ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n206(std::uint64_t x){
    x ^= 0x6A531AD0B1F819C9ULL;
    x = rotl(x, 24);
    x += 0xDB20725374625715ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n207(std::uint64_t x){
    x ^= 0x15C40C1FBDC47CEDULL;
    x = rotl(x, 25);
    x += 0x4BED92F4078AB073ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n208(std::uint64_t x){
    x ^= 0x1CD84E6BF48C9E16ULL;
    x = rotl(x, 26);
    x += 0xCC3B80BFC91216F6ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n209(std::uint64_t x){
    x ^= 0x6DA8D9B2E64367DEULL;
    x = rotl(x, 27);
    x += 0xB1244844207EB986ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n210(std::uint64_t x){
    x ^= 0xDEDEF51CDF556DB4ULL;
    x = rotl(x, 28);
    x += 0x54573F44324B3B5ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n211(std::uint64_t x){
    x ^= 0xF459D791C078B7EEULL;
    x = rotl(x, 29);
    x += 0xE7C53BBD1B556B20ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n212(std::uint64_t x){
    x ^= 0xD7831DCE7B9D46B3ULL;
    x = rotl(x, 30);
    x += 0x9E9F5E075D38339EULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n213(std::uint64_t x){
    x ^= 0xECBFB4AF931C75CCULL;
    x = rotl(x, 31);
    x += 0x51EAEBD2748CB236ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n214(std::uint64_t x){
    x ^= 0x9E9FC8611F66B97ULL;
    x = rotl(x, 32);
    x += 0x76D456C62C974A30ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n215(std::uint64_t x){
    x ^= 0x26B9C40570AB22B4ULL;
    x = rotl(x, 33);
    x += 0xDFAE0FA3E12B3175ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n216(std::uint64_t x){
    x ^= 0xEA7E9648006987B7ULL;
    x = rotl(x, 34);
    x += 0xF57201AA80B5A26CULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n217(std::uint64_t x){
    x ^= 0xC950976BFDCA7DBFULL;
    x = rotl(x, 35);
    x += 0xBDFC71D5B3A9B637ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n218(std::uint64_t x){
    x ^= 0x9D1AED92CF09CAA3ULL;
    x = rotl(x, 36);
    x += 0x268CF89914569922ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t n219(std::uint64_t x){
    x ^= 0x7C46ED35E76CCF81ULL;
    x = rotl(x, 37);
    x += 0x6C65536B6DAD3525ULL;
    if ((x & 0xFFFFULL) == 0x1234ULL) x ^= mix2(x);
    return mix2(x);
}
static std::uint64_t entry(std::uint64_t v){
    std::uint64_t x=v;
    x = n0(x);
    x = n1(x);
    x = n2(x);
    x = n3(x);
    x = n4(x);
    x = n5(x);
    x = n6(x);
    x = n7(x);
    x = n8(x);
    x = n9(x);
    x = n10(x);
    x = n11(x);
    x = n12(x);
    x = n13(x);
    x = n14(x);
    x = n15(x);
    x = n16(x);
    x = n17(x);
    x = n18(x);
    x = n19(x);
    x = n20(x);
    x = n21(x);
    x = n22(x);
    x = n23(x);
    x = n24(x);
    x = n25(x);
    x = n26(x);
    x = n27(x);
    x = n28(x);
    x = n29(x);
    x = n30(x);
    x = n31(x);
    x = n32(x);
    x = n33(x);
    x = n34(x);
    x = n35(x);
    x = n36(x);
    x = n37(x);
    x = n38(x);
    x = n39(x);
    x = n40(x);
    x = n41(x);
    x = n42(x);
    x = n43(x);
    x = n44(x);
    x = n45(x);
    x = n46(x);
    x = n47(x);
    x = n48(x);
    x = n49(x);
    x = n50(x);
    x = n51(x);
    x = n52(x);
    x = n53(x);
    x = n54(x);
    x = n55(x);
    x = n56(x);
    x = n57(x);
    x = n58(x);
    x = n59(x);
    x = n60(x);
    x = n61(x);
    x = n62(x);
    x = n63(x);
    x = n64(x);
    x = n65(x);
    x = n66(x);
    x = n67(x);
    x = n68(x);
    x = n69(x);
    x = n70(x);
    x = n71(x);
    x = n72(x);
    x = n73(x);
    x = n74(x);
    x = n75(x);
    x = n76(x);
    x = n77(x);
    x = n78(x);
    x = n79(x);
    x = n80(x);
    x = n81(x);
    x = n82(x);
    x = n83(x);
    x = n84(x);
    x = n85(x);
    x = n86(x);
    x = n87(x);
    x = n88(x);
    x = n89(x);
    x = n90(x);
    x = n91(x);
    x = n92(x);
    x = n93(x);
    x = n94(x);
    x = n95(x);
    x = n96(x);
    x = n97(x);
    x = n98(x);
    x = n99(x);
    x = n100(x);
    x = n101(x);
    x = n102(x);
    x = n103(x);
    x = n104(x);
    x = n105(x);
    x = n106(x);
    x = n107(x);
    x = n108(x);
    x = n109(x);
    x = n110(x);
    x = n111(x);
    x = n112(x);
    x = n113(x);
    x = n114(x);
    x = n115(x);
    x = n116(x);
    x = n117(x);
    x = n118(x);
    x = n119(x);
    x = n120(x);
    x = n121(x);
    x = n122(x);
    x = n123(x);
    x = n124(x);
    x = n125(x);
    x = n126(x);
    x = n127(x);
    x = n128(x);
    x = n129(x);
    x = n130(x);
    x = n131(x);
    x = n132(x);
    x = n133(x);
    x = n134(x);
    x = n135(x);
    x = n136(x);
    x = n137(x);
    x = n138(x);
    x = n139(x);
    x = n140(x);
    x = n141(x);
    x = n142(x);
    x = n143(x);
    x = n144(x);
    x = n145(x);
    x = n146(x);
    x = n147(x);
    x = n148(x);
    x = n149(x);
    x = n150(x);
    x = n151(x);
    x = n152(x);
    x = n153(x);
    x = n154(x);
    x = n155(x);
    x = n156(x);
    x = n157(x);
    x = n158(x);
    x = n159(x);
    x = n160(x);
    x = n161(x);
    x = n162(x);
    x = n163(x);
    x = n164(x);
    x = n165(x);
    x = n166(x);
    x = n167(x);
    x = n168(x);
    x = n169(x);
    x = n170(x);
    x = n171(x);
    x = n172(x);
    x = n173(x);
    x = n174(x);
    x = n175(x);
    x = n176(x);
    x = n177(x);
    x = n178(x);
    x = n179(x);
    x = n180(x);
    x = n181(x);
    x = n182(x);
    x = n183(x);
    x = n184(x);
    x = n185(x);
    x = n186(x);
    x = n187(x);
    x = n188(x);
    x = n189(x);
    x = n190(x);
    x = n191(x);
    x = n192(x);
    x = n193(x);
    x = n194(x);
    x = n195(x);
    x = n196(x);
    x = n197(x);
    x = n198(x);
    x = n199(x);
    x = n200(x);
    x = n201(x);
    x = n202(x);
    x = n203(x);
    x = n204(x);
    x = n205(x);
    x = n206(x);
    x = n207(x);
    x = n208(x);
    x = n209(x);
    x = n210(x);
    x = n211(x);
    x = n212(x);
    x = n213(x);
    x = n214(x);
    x = n215(x);
    x = n216(x);
    x = n217(x);
    x = n218(x);
    x = n219(x);
    return x;
}
}
static volatile std::uint64_t __nv_ultra_sink = novacpp_ultra_decoy::entry(0xA5A5A5A55A5A5A5AULL);
// ===== /NovaCPP ULTRA decoy mesh =====
