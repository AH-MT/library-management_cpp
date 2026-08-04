#pragma once
#include <string>
#include <vector>
#include "person.h"

class Librarian : public Person{
    private:
        const std::string employeeCode;

    public:
        Librarian(std::string name, std::string id, std::string employeeCode):Person(name,id), employeeCode(employeeCode){}
        void displayInfo() const override;
        std::string getRole() const override;
        ~Librarian()override{}
};