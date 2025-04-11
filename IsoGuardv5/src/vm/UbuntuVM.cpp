#include "vm/UbuntuVM.hpp"

UbuntuVM::UbuntuVM(const std::string& name) noexcept
    : VirtualMachine(name) {}

bool UbuntuVM::start() noexcept {
    std::cout << "Starting Ubuntu VM: " << m_name << "\n";
    return true;
}

bool UbuntuVM::stop() noexcept {
    std::cout << "Stopping Ubuntu VM: " << m_name << "\n";
    return true;
}

bool UbuntuVM::destroy() noexcept {
    std::cout << "Destroying Ubuntu VM: " << m_name << "\n";
    return true;
}
