#include "ModuleNetworks.hpp"

void ModuleNetworks::receive(const std::string& message) {
    std::cout << "ModuleNetworks received: " << message << std::endl;
}

void ModuleNetworks::send(const std::string& message, IModule* target) {
    std::cout << "ModuleNetworks sends: " << message << std::endl;
    core->distribute(this, message, target);
}

void ModuleNetworks::handleAPIRequest(const std::string& request) {
    std::cout << "ModuleNetworks handling API request: " << request << std::endl;
}
