#ifndef MODULEVM_HPP
#define MODULEVM_HPP

#include "../core/interfaces/IModule.hpp"
#include "Factory/VMFactory.hpp"
#include <iostream>
#include <vector>
#include <memory>

class ModuleVM : public IModule {
    public:
        void receive(const std::string& message) override;
        void send(const std::string& message, IModule* target = nullptr) override;
        void manageVM(const std::string& action);
        void createVM(const std::string& name);
        void listVMs() const;
        int getLastVMId() const;

    private:
        VMFactory vmFactory;
        std::vector<std::shared_ptr<VM>> vms;
};

#endif // MODULEVM_HPP
