#ifndef VIRTUAL_MACHINE_FACTORY_HPP
#define VIRTUAL_MACHINE_FACTORY_HPP

#include "factory/IVirtualMachine.hpp"
#include <memory>

enum class VMType {
    Windows10,
    Ubuntu
};

class VirtualMachineFactory {
    public:
        static std::shared_ptr<IVirtualMachine> createVM(VMType type, const std::string& name);
};

#endif // VIRTUAL_MACHINE_FACTORY_HPP
