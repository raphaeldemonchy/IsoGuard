#include "VMFactory.hpp"

std::shared_ptr<VM> VMFactory::createVM(const std::string& name) {
    return std::make_shared<VM>(nextId++, name);
}
