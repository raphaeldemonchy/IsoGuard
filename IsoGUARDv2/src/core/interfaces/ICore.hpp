#ifndef ICORE_HPP
#define ICORE_HPP

#include <string>

class IModule;

class ICore {
    public:
        virtual ~ICore() = default;
        virtual void addModule(IModule* module) = 0;
        virtual void distribute(IModule* sender, const std::string& message, IModule* target = nullptr) = 0;
};

#endif // ICORE_HPP
