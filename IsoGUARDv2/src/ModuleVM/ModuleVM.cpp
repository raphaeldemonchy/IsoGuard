#include "ModuleVM.hpp"

void ModuleVM::receive(const std::string& message) {
    std::cout << "ModuleVM received: " << message << std::endl;
}

void ModuleVM::send(const std::string& message, IModule* target) {
    std::cout << "ModuleVM sends: " << message << std::endl;
    core->distribute(this, message, target);
}

void ModuleVM::manageVM(const std::string& action) {
    std::cout << "ModuleVM managing VM: " << action << std::endl;
}

void ModuleVM::createVM(const std::string& name) {
    std::shared_ptr<VM> vm = vmFactory.createVM(name);
    vms.push_back(vm);
    std::cout << "VM created: ID=" << vm->getId() << ", Name=" << vm->getName() << std::endl;
}

void ModuleVM::listVMs() const {
    std::cout << "List of VMs:" << std::endl;
    for (const auto& vm : vms) {
        std::cout << "ID=" << vm->getId() << ", Name=" << vm->getName() << std::endl;
    }
}

int ModuleVM::getLastVMId() const {
    if (!vms.empty()) {
        return vms.back()->getId();
    }
    return -1;
}