#ifndef VM_MANAGER_HPP
#define VM_MANAGER_HPP

#include "factory/VirtualMachineFactory.hpp"
#include <unordered_map>
#include <memory>
#include <string>

class VMManager {
    public:
        bool addVM(const std::string& name, VMType type);
        bool startVM(const std::string& name);
        bool stopVM(const std::string& name);
        bool eraseVM(const std::string& name);
        void listVMs() const;

    private:
        std::unordered_map<std::string, std::shared_ptr<IVirtualMachine>> vms_pool;
};

#endif // VM_MANAGER_HPP
