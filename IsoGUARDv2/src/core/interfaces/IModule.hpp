#ifndef IMODULE_HPP
#define IMODULE_HPP

#include <string>
#include "ICore.hpp"

class IModule {
    public:
        virtual ~IModule() = default;
        virtual void receive(const std::string& message) = 0;
        virtual void send(const std::string& message, IModule* target = nullptr) = 0;
        void setCore(ICore* core);

    protected:
        ICore* core;
};

#endif // IMODULE_HPP
