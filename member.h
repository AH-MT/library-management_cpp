#pragma once
#include <string>
#include <vector>


class Person{
    protected:
        std::string name;
        const std::string id;
    public:
        Person(std::string name, std::string id):name(name),id(id){}
        //getters
        std::string getName()const;
        std::string getId()const;
        virtual void displayInfo()const;
        virtual std::string getRole()const;
        
        //setters
        void setName(const std::string& name);
        virtual ~Person(){}
    };

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
        int getBorrowedCount();

        void displayInfo() const override;
        std::string getRole() const override;

        ~Member()override{}

};