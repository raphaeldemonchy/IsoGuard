#ifndef VIRTUAL_MACHINE_HPP
#define VIRTUAL_MACHINE_HPP

#include "factory/IVirtualMachine.hpp"
#include <string>

class VirtualMachine : public IVirtualMachine {
    public:
        explicit VirtualMachine(std::string name) noexcept;
        virtual ~VirtualMachine() noexcept override = default;

        std::string getName() const noexcept override;

    protected:
        std::string m_name;
};

#endif // VIRTUAL_MACHINE_HPP
