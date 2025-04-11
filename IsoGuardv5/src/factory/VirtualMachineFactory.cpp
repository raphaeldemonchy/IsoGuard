#include "factory/VirtualMachineFactory.hpp"
#include "vm/Windows10VM.hpp"
#include "vm/UbuntuVM.hpp"
#include <stdexcept>

std::shared_ptr<IVirtualMachine> VirtualMachineFactory::createVM(VMType type, const std::string& name) {
    switch (type) {
        case VMType::Windows10:
            return std::make_shared<Windows10VM>(name);
        case VMType::Ubuntu:
            return std::make_shared<UbuntuVM>(name);
        default:
            throw std::runtime_error("Unknown VM type");
    }
}
