#ifndef MODULEN_HPP
#define MODULEN_HPP

#include "../core/interfaces/IModule.hpp"
#include <iostream>

class ModuleNetworks : public IModule {
    public:
        void receive(const std::string& message) override;
        void send(const std::string& message, IModule* target = nullptr) override;
        void handleAPIRequest(const std::string& request);

    private:
        

};

#endif // MODULEN_HPP
