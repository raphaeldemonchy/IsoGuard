#include "manager/VMManager.hpp"
#include <iostream>

bool VMManager::addVM(const std::string& name, VMType type) {
    if (vms_pool.count(name)) {
        std::cerr << "[VMManager] - VM '" << name << "' already exists." << std::endl;
        return false;
    }

    auto vm = VirtualMachineFactory::createVM(type, name);
    if (!vm) {
        std::cerr << "[VMManager] - Unknown VM type." << std::endl;
        return false;
    }

    vms_pool[name] = vm;
    std::cout << "[VMManager] - VM '" << name << "' created." << std::endl;
    return true;
}

bool VMManager::startVM(const std::string& name) {
    if (!vms_pool.count(name)) {
        std::cerr << "[VMManager] - VM not found." << std::endl;
        return false;
    }

    return vms_pool[name]->start();
}

bool VMManager::stopVM(const std::string& name) {
    if (!vms_pool.count(name)) {
        std::cerr << "[VMManager] - VM not found." << std::endl;
        return false;
    }

    return vms_pool[name]->stop();
}

bool VMManager::eraseVM(const std::string& name) {
    if (!vms_pool.count(name)) {
        std::cerr << "[VMManager] - VM not found." << std::endl;
        return false;
    }

    vms_pool[name]->destroy();
    vms_pool.erase(name);
    std::cout << "[VMManager] - VM '" << name << "' destroyed and removed." << std::endl;
    return true;
}

void VMManager::listVMs() const {
    if (vms_pool.empty()) {
        std::cout << "[VMManager] - No VMs managed." << std::endl;
        return;
    }

    std::cout << "[VMManager] - Managed VMs:" << std::endl;
    for (const auto& [name, vm] : vms_pool) {
        std::cout << "- " << name << std::endl;
    }
}
