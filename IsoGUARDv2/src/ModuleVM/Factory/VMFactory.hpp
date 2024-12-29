#ifndef VMFACTORY_HPP
#define VMFACTORY_HPP

#include "VM.hpp"
#include <memory>

class VMFactory {
    public:
        std::shared_ptr<VM> createVM(const std::string& name);

    private:
        int nextId = 1;
};

#endif // VMFACTORY_HPP
