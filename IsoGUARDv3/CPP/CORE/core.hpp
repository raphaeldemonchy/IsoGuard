#ifndef CORE_HPP
#define CORE_HPP

#include <string>

class Core {
    public:
        static std::string loadXMLConfig(const std::string& xmlPath, const std::string& vmName);
        static void createVM(const std::string& xmlPath, const std::string& vmName);
        //deleteVM
        //StartVM
        //ShutdownVM
    private:
};

#endif // CORE_HPP
