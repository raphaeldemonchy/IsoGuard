#ifndef UBUNTU_VM_HPP
#define UBUNTU_VM_HPP

#include "vm/VirtualMachine.hpp"
#include <iostream>

class UbuntuVM final : public VirtualMachine {
    public:
        explicit UbuntuVM(const std::string& name) noexcept;

        bool start() noexcept override;
        bool stop() noexcept override;
        bool destroy() noexcept override;
};

#endif // UBUNTU_VM_HPP
