// PasswordChecker.cpp
// Compile with: cl /EHsc PasswordChecker.cpp /Fe:PasswordChecker.exe
// (or any C++17 compiler on Windows)

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <ctime>
#include <windows.h>  // For GetModuleFileName, IsDebuggerPresent

// ------------------------------------------------------------------
// Protection: anti-debugging check
// Returns true if a debugger is present (detected)
// ------------------------------------------------------------------
bool isDebuggerPresent() {
    // Windows API check
    if (IsDebuggerPresent()) {
        return true;
    }
    // Additional simple check: look for common debugger environment variables
    // (some debuggers set these)
    if (GetEnvironmentVariableA("DEBUGGER_PRESENT", nullptr, 0) > 0 ||
        GetEnvironmentVariableA("_DEBUGGER_", nullptr, 0) > 0) {
        return true;
    }
    return false;
}

// ------------------------------------------------------------------
// Get the full path to the executable's directory
// ------------------------------------------------------------------
std::string getExeDirectory() {
    char buffer[MAX_PATH];
    GetModuleFileNameA(nullptr, buffer, MAX_PATH);
    std::string exePath(buffer);
    size_t lastSlash = exePath.find_last_of("\\/");
    if (lastSlash != std::string::npos) {
        return exePath.substr(0, lastSlash + 1);
    }
    return ".\\"; // fallback
}

// ------------------------------------------------------------------
// Write a log entry (timestamp + message) to a file next to the .exe
// ------------------------------------------------------------------
void logToFile(const std::string& message) {
    std::string logFilePath = getExeDirectory() + "password_attempts.log";
    std::ofstream logFile(logFilePath, std::ios::app); // append mode
    if (logFile.is_open()) {
        auto now = std::chrono::system_clock::now();
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);
        logFile << std::ctime(&now_time) << " - " << message << std::endl;
        logFile.close();
    }
}

// ------------------------------------------------------------------
// Main program
// ------------------------------------------------------------------
int main() {
    // ---- PROTECTION: check for debugger ----
    if (isDebuggerPresent()) {
        std::cout << "[Security] Debugger detected. Program will not run." << std::endl;
        logToFile("BLOCKED: Debugger detected, program aborted.");
        return 1; // exit with error
    }

    const std::string correctPassword = "MySecurePass123";
    std::string userInput;

    std::cout << "Enter password: ";
    std::cin >> userInput;

    if (userInput == correctPassword) {
        std::cout << "Access GRANTED." << std::endl;
        logToFile("SUCCESS: Correct password entered.");
        return 0;
    }
    else {
        std::cout << "Access DENIED." << std::endl;
        logToFile("FAILURE: Wrong password entered (attempt: '" + userInput + "')");
        return 1;
    }
}