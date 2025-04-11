#ifndef WINDOWS_10_VM_HPP
#define WINDOWS_10_VM_HPP

#include "vm/VirtualMachine.hpp"
#include <iostream>

class Windows10VM final : public VirtualMachine {
    public:
        explicit Windows10VM(const std::string& name) noexcept;

        bool start() noexcept override;
        bool stop() noexcept override;
        bool destroy() noexcept override;
};

#endif // WINDOWS_10_VM_HPP
