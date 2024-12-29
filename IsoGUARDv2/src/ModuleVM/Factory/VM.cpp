#include "VM.hpp"

VM::VM(int id, const std::string& name) : id(id), name(name) {
    std::cout << "VM " << id << " created" << std::endl;
}

int VM::getId() const {
    return id;
}

std::string VM::getName() const {
    return name;
}
