#include "vm/Windows10VM.hpp"

Windows10VM::Windows10VM(const std::string& name) noexcept
    : VirtualMachine(name) {}

bool Windows10VM::start() noexcept {
    std::cout << "[Windows10] - Starting Windows 10 VM: " << m_name << "\n";
    return true;
}

bool Windows10VM::stop() noexcept {
    std::cout << "[Windows10] - Stopping Windows 10 VM: " << m_name << "\n";
    return true;
}

bool Windows10VM::destroy() noexcept {
    std::cout << "[Windows10] - Destroying Windows 10 VM: " << m_name << "\n";
    return true;
}
