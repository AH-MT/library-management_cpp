#pragma once
#include <string>
#include <vector>
#include "person.h"
#include "book.cpp"

class Member : public Person{
    private:
        std::vector<int> borrowedISBNs;
        std::string role = "Member";
    
    public:
        Member(std::string name_t, int id_t, int pasword_t):Person(name_t,id_t, pasword_t){}
        void borrowBook(const Book* book);
        void returnBook(const Book* book);
        //void hasBorrowedBook();
        bool canBorrow()const;
        //std::vector<std::string> getBorrowedBooks()const;
        //int getBorrowedCount()const;
        int getId()const;
        void displayInfo() const override;
        std::string getRole() const override;
        const std::vector<int>* getBooks() const;;
        ~Member()override{}
};
