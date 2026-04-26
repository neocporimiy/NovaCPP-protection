#include <iostream>
#include <string>
// ===== NovaCPP Runtime (auto) =====
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



int __nv_cf097aca(int __nv_5e7e91a5) {
    volatile std::uint64_t __nv_fe0dd051 = novacpp_rt::mix(0xDDA0B87399551993ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_fe0dd051 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_380a571a = novacpp_rt::mix(0x4384A3B21E766787ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_380a571a & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_7b59c7a6 = novacpp_rt::mix(0x3014445DEFF30E2DULL ^ (std::uint64_t)__LINE__);
    if (((__nv_7b59c7a6 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_67926602 = novacpp_rt::mix(0x80D87C9D72D54847ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_67926602 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_8cb8b641 = novacpp_rt::mix(0x597E1F8C2D0BA5CAULL ^ (std::uint64_t)__LINE__);
    if (((__nv_8cb8b641 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_a59841c2 = novacpp_rt::mix(0x9C642AFC16EB061ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_a59841c2 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_82ee24cc = novacpp_rt::mix(0xBB8D82BB9F828751ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_82ee24cc & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_f11be479 = novacpp_rt::mix(0xB4D5BF645BE42ACAULL ^ (std::uint64_t)__LINE__);
    if (((__nv_f11be479 & 7ULL) == 9ULL)) { std::abort(); }

    int __nv_e3f9276d = ((507469255 ^ 507468030));
    std::string __nv_f210f11 = ([](){
    volatile std::uint64_t __nv_fe0dd051 = novacpp_rt::mix(0x5FA9941AB640529BULL ^ (std::uint64_t)__LINE__);
    if (((__nv_fe0dd051 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_380a571a = novacpp_rt::mix(0xE4E19F44DA454AA2ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_380a571a & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_7b59c7a6 = novacpp_rt::mix(0xDD23DA6E80AE8128ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_7b59c7a6 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_67926602 = novacpp_rt::mix(0x5939BD042EEFBULL ^ (std::uint64_t)__LINE__);
    if (((__nv_67926602 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_8cb8b641 = novacpp_rt::mix(0x353CA1D867094EDDULL ^ (std::uint64_t)__LINE__);
    if (((__nv_8cb8b641 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_a59841c2 = novacpp_rt::mix(0x316EBA5DB465E466ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_a59841c2 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_82ee24cc = novacpp_rt::mix(0xE38959525F1A7F9ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_82ee24cc & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_f11be479 = novacpp_rt::mix(0xA9686B1A2EAA78B7ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_f11be479 & 7ULL) == 9ULL)) { std::abort(); }
 static const unsigned char __nv_4b2d9c4d[]={0x18, 0x39, 0x20, 0x37, 0x15, 0x06, 0x06, 0x7B, 0x03, 0x1A, 0x02, 0x04, 0x17, 0x56}; static std::string __nv_6c15b064 = novacpp_rt::dec(__nv_4b2d9c4d, sizeof(__nv_4b2d9c4d), 0x56); return __nv_6c15b064.c_str(); }());
    if (__nv_5e7e91a5 > ((420092751 ^ 420092744))) return __nv_e3f9276d + __nv_5e7e91a5;
    return __nv_e3f9276d - __nv_5e7e91a5;
}

int __nv_6716c07d() {
    volatile std::uint64_t __nv_fe0dd051 = novacpp_rt::mix(0xE9B88AA88D69436AULL ^ (std::uint64_t)__LINE__);
    if (((__nv_fe0dd051 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_380a571a = novacpp_rt::mix(0x917AE4758259375EULL ^ (std::uint64_t)__LINE__);
    if (((__nv_380a571a & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_7b59c7a6 = novacpp_rt::mix(0x223E760EE59304C0ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_7b59c7a6 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_67926602 = novacpp_rt::mix(0x5E7FC3FFC4AB8E8ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_67926602 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_8cb8b641 = novacpp_rt::mix(0x46D8A58DC590135DULL ^ (std::uint64_t)__LINE__);
    if (((__nv_8cb8b641 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_a59841c2 = novacpp_rt::mix(0x3E15E26CE9CD0C8BULL ^ (std::uint64_t)__LINE__);
    if (((__nv_a59841c2 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_82ee24cc = novacpp_rt::mix(0x90A5E9824A3C965AULL ^ (std::uint64_t)__LINE__);
    if (((__nv_82ee24cc & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_f11be479 = novacpp_rt::mix(0xF6D31F25446A49EFULL ^ (std::uint64_t)__LINE__);
    if (((__nv_f11be479 & 7ULL) == 9ULL)) { std::abort(); }

    std::string __nv_b82b1027 = ([](){
    volatile std::uint64_t __nv_fe0dd051 = novacpp_rt::mix(0x995ECAEE72CF9B3BULL ^ (std::uint64_t)__LINE__);
    if (((__nv_fe0dd051 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_380a571a = novacpp_rt::mix(0x1681BF9BE079F949ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_380a571a & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_7b59c7a6 = novacpp_rt::mix(0x8449C71D5EBB0E7ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_7b59c7a6 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_67926602 = novacpp_rt::mix(0xA11083CCB4705336ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_67926602 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_8cb8b641 = novacpp_rt::mix(0xD13CB4B51EC750CULL ^ (std::uint64_t)__LINE__);
    if (((__nv_8cb8b641 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_a59841c2 = novacpp_rt::mix(0x79F06C8B9123BAF8ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_a59841c2 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_82ee24cc = novacpp_rt::mix(0x38457C6075768EULL ^ (std::uint64_t)__LINE__);
    if (((__nv_82ee24cc & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_f11be479 = novacpp_rt::mix(0x655D2A475F432977ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_f11be479 & 7ULL) == 9ULL)) { std::abort(); }
 static const unsigned char __nv_afd95bbb[]={0x9A, 0x89, 0x9E, 0x95, 0x93, 0x9F, 0x89, 0x8F, 0x9E, 0x89, 0x98, 0x93, 0x98, 0x83, 0x87, 0x89, 0x82, 0x93, 0xFE, 0xFC, 0xFE, 0xFA, 0xCC}; static std::string __nv_48a56d8f = novacpp_rt::dec(__nv_afd95bbb, sizeof(__nv_afd95bbb), 0xCC); return __nv_48a56d8f.c_str(); }());
    std::cout << ([](){
    volatile std::uint64_t __nv_fe0dd051 = novacpp_rt::mix(0xD5888A05321F79B7ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_fe0dd051 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_380a571a = novacpp_rt::mix(0x695FEB23E8812B29ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_380a571a & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_7b59c7a6 = novacpp_rt::mix(0x4CF49E37C9DD414AULL ^ (std::uint64_t)__LINE__);
    if (((__nv_7b59c7a6 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_67926602 = novacpp_rt::mix(0x75B8396B1E91EE3ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_67926602 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_8cb8b641 = novacpp_rt::mix(0x33EF275D32702224ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_8cb8b641 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_a59841c2 = novacpp_rt::mix(0xA5770C66CCECF17AULL ^ (std::uint64_t)__LINE__);
    if (((__nv_a59841c2 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_82ee24cc = novacpp_rt::mix(0xD6F565AAF9283F6AULL ^ (std::uint64_t)__LINE__);
    if (((__nv_82ee24cc & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_f11be479 = novacpp_rt::mix(0xCACD5729D749B43ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_f11be479 & 7ULL) == 9ULL)) { std::abort(); }
 static const unsigned char __nv_3b2d25cb[]={0x8B, 0xBD, 0xBB, 0xAA, 0xBD, 0xAC, 0xE2, 0xF8, 0xD8}; static std::string __nv_aabe1402 = novacpp_rt::dec(__nv_3b2d25cb, sizeof(__nv_3b2d25cb), 0xD8); return __nv_aabe1402.c_str(); }()) << __nv_b82b1027 << ([](){
    volatile std::uint64_t __nv_fe0dd051 = novacpp_rt::mix(0x6EEEFC1285DA9974ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_fe0dd051 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_380a571a = novacpp_rt::mix(0x514F2AB5980E29C4ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_380a571a & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_7b59c7a6 = novacpp_rt::mix(0xAAF88B941C68F6DBULL ^ (std::uint64_t)__LINE__);
    if (((__nv_7b59c7a6 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_67926602 = novacpp_rt::mix(0x1031EDA65D327B55ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_67926602 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_8cb8b641 = novacpp_rt::mix(0x6D8DF0B499761027ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_8cb8b641 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_a59841c2 = novacpp_rt::mix(0xE50A218F1E8E5D89ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_a59841c2 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_82ee24cc = novacpp_rt::mix(0x23AD0DC0AA634A38ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_82ee24cc & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_f11be479 = novacpp_rt::mix(0x90432DC6286B5168ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_f11be479 & 7ULL) == 9ULL)) { std::abort(); }
 static const unsigned char __nv_f80aefc3[]={0x53, 0x61, 0x0F}; static std::string __nv_1852da0e = novacpp_rt::dec(__nv_f80aefc3, sizeof(__nv_f80aefc3), 0x0F); return __nv_1852da0e.c_str(); }());
    std::cout << ([](){
    volatile std::uint64_t __nv_fe0dd051 = novacpp_rt::mix(0xB24E8C3AB3BD6545ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_fe0dd051 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_380a571a = novacpp_rt::mix(0xD5E8F3F8C6540CC6ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_380a571a & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_7b59c7a6 = novacpp_rt::mix(0x91702489A12A94BULL ^ (std::uint64_t)__LINE__);
    if (((__nv_7b59c7a6 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_67926602 = novacpp_rt::mix(0x8E35E9357615DA14ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_67926602 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_8cb8b641 = novacpp_rt::mix(0xAC38D051C9CB5C1AULL ^ (std::uint64_t)__LINE__);
    if (((__nv_8cb8b641 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_a59841c2 = novacpp_rt::mix(0x48A5C3A1E94066B6ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_a59841c2 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_82ee24cc = novacpp_rt::mix(0xE743869B9E23C47DULL ^ (std::uint64_t)__LINE__);
    if (((__nv_82ee24cc & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_f11be479 = novacpp_rt::mix(0x6D7372A23F5FC91DULL ^ (std::uint64_t)__LINE__);
    if (((__nv_f11be479 & 7ULL) == 9ULL)) { std::abort(); }
 static const unsigned char __nv_128a81ae[]={0x5F, 0x7D, 0x70, 0x7F, 0x26, 0x3C, 0x1C}; static std::string __nv_c2fa8926 = novacpp_rt::dec(__nv_128a81ae, sizeof(__nv_128a81ae), 0x1C); return __nv_c2fa8926.c_str(); }()) << __nv_cf097aca(((502946881 ^ 502946891))) << ([](){
    volatile std::uint64_t __nv_fe0dd051 = novacpp_rt::mix(0x8AA5C17EEBF9BCBBULL ^ (std::uint64_t)__LINE__);
    if (((__nv_fe0dd051 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_380a571a = novacpp_rt::mix(0xA96EC49916203FC3ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_380a571a & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_7b59c7a6 = novacpp_rt::mix(0x58888A41BCC3D8E9ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_7b59c7a6 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_67926602 = novacpp_rt::mix(0x9E5D730564B89D9ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_67926602 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_8cb8b641 = novacpp_rt::mix(0x81ED7A4CC3A8C4FDULL ^ (std::uint64_t)__LINE__);
    if (((__nv_8cb8b641 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_a59841c2 = novacpp_rt::mix(0xDC55A059F8DDA1D3ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_a59841c2 & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_82ee24cc = novacpp_rt::mix(0xC5757FBA31D7E900ULL ^ (std::uint64_t)__LINE__);
    if (((__nv_82ee24cc & 7ULL) == 9ULL)) { std::abort(); }

    volatile std::uint64_t __nv_f11be479 = novacpp_rt::mix(0x2A5F924DF696A6BEULL ^ (std::uint64_t)__LINE__);
    if (((__nv_f11be479 & 7ULL) == 9ULL)) { std::abort(); }
 static const unsigned char __nv_c9ba2d6a[]={0xBE, 0x8C, 0xE2}; static std::string __nv_aad16179 = novacpp_rt::dec(__nv_c9ba2d6a, sizeof(__nv_c9ba2d6a), 0xE2); return __nv_aad16179.c_str(); }());
    return 0;
}
