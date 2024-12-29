#include "Core.hpp"

void Core::addModule(IModule* module) {
    modules.push_back(module);
    module->setCore(this);
}

void Core::distribute(IModule* sender, const std::string& message, IModule* target) {
    if (target) {
        target->receive(message);
    } else {
        for (auto module : modules) {
            if (module != sender) {
                module->receive(message);
            }
        }
    }
}
