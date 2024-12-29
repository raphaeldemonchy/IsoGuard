#ifndef VM_HPP
#define VM_HPP

#include <string>
#include <iostream>

class VM {
    public:
        VM(int id, const std::string& name);
        int getId() const;
        std::string getName() const;

    private:
        int id;
        std::string name;
};

#endif // VM_HPP
