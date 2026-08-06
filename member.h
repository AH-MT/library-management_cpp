#pragma once
#include <string>
#include <vector>
#include "person.h"
#include "book.cpp"

class Member : public Person{
    private:
        std::vector<int> borrowedISBNs;
    

    public:
        Member(std::string name_t, int id_t):Person(name_t,id_t){}
        void borrowBook(const Book* book);
        void returnBook(const Book* book);
        //void hasBorrowedBook();
        bool canBorrow()const;
        //std::vector<std::string> getBorrowedBooks()const;
        //int getBorrowedCount()const;
        int getId()const;
        void displayInfo() const override;
        std::string getRole() const override;

        ~Member()override{}
};
