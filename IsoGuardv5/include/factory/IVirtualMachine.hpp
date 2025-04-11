#ifndef I_VIRTUAL_MACHINE_HPP
#define I_VIRTUAL_MACHINE_HPP

#include <string>

class IVirtualMachine {
    public:
        virtual ~IVirtualMachine() noexcept = default;

        virtual bool start() noexcept = 0;
        virtual bool stop() noexcept = 0;
        virtual bool destroy() noexcept = 0;

        virtual std::string getName() const noexcept = 0;
};

#endif // I_VIRTUAL_MACHINE_HPP
