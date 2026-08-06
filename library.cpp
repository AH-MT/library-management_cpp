#include "library.h"
#include <iostream>
#include <algorithm>
int Library::memberIdMaker(){
    nextMemberId++;
    return nextMemberId -1;
}
int Library::bookIdMaker(){
    nextBookId++;
    return nextBookId -1;
}
void Library::addBook(const std::string& title, const std::string& author){
    Book book(title,author,this->bookIdMaker(),true);
    books.push_back(book);
    std::cout<<"book secsessfully added."<<std::endl;
}
bool Library::removeBook(const int& bookId){
    for(int i=0; i<books.size(); i++){
        if (books[i].getBookId() == bookId){
            if(books[i].getAvailability() == false){
                return false;
            }
            books.erase(books.begin() + i);
            return true;
        }
    }
    return false;
}
void Library::addMember(const std::string& name){
        int id = this->memberIdMaker();
        Member member(name,id);
        members.push_back(member);
}
bool Library::removeMember(const int& memberId){
    for(int i=0; i<members.size(); i++){
        if (members[i].getId() == memberId){
            members.erase(members.begin() + i);
            return true;
        }
    }
    return false;
}
Book* Library::findBookById(const int& bookId){
    for(int i=0; i<books.size(); i++){
        if (books[i].getBookId() == bookId){
            return &books[i];
        }
    }
    return nullptr;
}
Member* Library::findMemberById(const int& memberId){
    for(int i=0; i<members.size(); i++){
        if (members[i].getId() == memberId){
            return &members[i];
        }
    }
    return nullptr;
}
bool Library::isMemberById(const int& memberId){
    for(int i=0; i<members.size(); i++){
        if (members[i].getId() == memberId){
            return true;
        }
    }
    return false;
}
bool Library::borrowBook(const int& bookId, const int& memberId){
    Book* book = findBookById(bookId);
    Member* member = findMemberById(memberId);
    if(book == nullptr){
        std::cout<<"There is no such book."<<std::endl;
        return false;
    }
    else if(book->getAvailability() == false){
        std::cout<<"this book have borrowed..."<<std::endl;
        return false;
    }
    if(member == nullptr){
        std::cout<<"There is no such person."<<std::endl;
        return false;
    }
    else if(!member->canBorrow()){
        std::cout<<"This person has tacken 3 books."<<std::endl;
        return false;
    }
    book->setAvailability(false);
    member->borrowBook(book);
    std::cout << "Book " << book->getTitle() << " successfully borrowed by Member " << memberId << "." << std::endl;
    return true;
}
bool Library::returnBook(const int& bookId, const int& memberId){
    Book* book = findBookById(bookId);
    Member* member = findMemberById(memberId);
    if(book == nullptr){
        std::cout<<"There is no such book."<<std::endl;
        return false;
    }
    else if(book->getAvailability() == true){
        std::cout<<"this book have not borrowed..."<<std::endl;
        return false;
    }
    if(member == nullptr){
        std::cout<<"There is no such person."<<std::endl;
        return false;
    }

    book->setAvailability(true);
    member->returnBook(book);
    std::cout << "Book " << book->getTitle() << " successfully returned by Member " << memberId << "." << std::endl;
    return true;
}
void Library::displayAllMembers(){
    for(int i=0; i<members.size(); i++){
        std::cout<<i+1<<"| "<<"name: "<<members[i].getName()<<" - "<<"id: "<<members[i].getId()<<std::endl;
    }
}
void Library::displayAllBooks(){
    for(int i=0; i<books.size(); i++){
        std::cout<<i+1<<"| "<<"title: "<<books[i].getTitle()<<" - "<<"author: "<<books[i].getAuthor()<<" - "<<"book id: "<<books[i].getBookId()
        <<" - avalability: "<<books[i].getAvailability()<<std::endl;
    }
}
void Library::displayAvBooks(){
    for(int i=0; i<books.size(); i++){
        if(books[i].getAvailability()){
        std::cout<<i+1<<"| "<<"title: "<<books[i].getTitle()<<" - "<<"author: "<<books[i].getAuthor()<<" - "<<"book id: "<<books[i].getBookId()<<std::endl;
        }
    }
}
