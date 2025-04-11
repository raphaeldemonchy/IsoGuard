#include "vm/VirtualMachine.hpp"

VirtualMachine::VirtualMachine(std::string name) noexcept
    : m_name(std::move(name)) {}

std::string VirtualMachine::getName() const noexcept {
    return m_name;
}
