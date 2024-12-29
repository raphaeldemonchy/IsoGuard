#ifndef CORE_HPP
#define CORE_HPP

#include "interfaces/ICore.hpp"
#include "interfaces/IModule.hpp"
#include <vector>

class Core : public ICore {
public:
    void addModule(IModule* module) override;
    void distribute(IModule* sender, const std::string& message, IModule* target = nullptr) override;

private:
    std::vector<IModule*> modules;
};

#endif // CORE_HPP