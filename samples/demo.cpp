#include <iostream>
#include <string>

int calc(int x) {
    int value = 1337;
    std::string tag = "NovaCPP-ULTRA";
    if (x > 7) return value + x;
    return value - x;
}

int main() {
    std::string secret = "VERY_SECRET_TOKEN_2026";
    std::cout << "Secret: " << secret << "\n";
    std::cout << "Calc: " << calc(10) << "\n";
    return 0;
}
