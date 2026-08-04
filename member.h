#pragma once
#include <string>
#include <vector>
#include "person.h"
#include "book.cpp"

class Member : public Person{
    private:
        std::vector<std::string> borrowedISBNs;
    public:
        Member(std::string name, std::string id):Person(name,id){}
        void borrowBook(const Book* book);
        void returnBook(const Book* book);
        void hasBorrowedBook();
        bool canBorrow()const;
        std::vector<std::string> getBorrowedBooks()const;
        int getBorrowedCount()const;
        std::string getId()const;
        void displayInfo() const override;
        std::string getRole() const override;

        ~Member()override{}
};
