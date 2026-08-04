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

class Member : public Person{
    private:
        std::vector<std::string> borrowedISBNs;
    

    public:
        Member(std::string name, std::string id):Person(name,id){}
        void borrowBook();
        void returnBook();
        void hasBorrowedBook();
        bool canBorrow()const;
        std::vector<std::string> getBorrowedBooks()const;
        int getBorrowedCount()const;

        void displayInfo() const override;
        std::string getRole() const override;

        ~Member()override{}

};
