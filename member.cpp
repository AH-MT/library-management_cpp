#include "member.h"
#include <iostream>
#include <string>
#include <vector>

void Member::borrowBook(const Book* book){
    borrowedISBNs.push_back(book->getBookId());
}
void Member::returnBook(const Book* book){
    for(int i=0; i<borrowedISBNs.size(); i++){
        if(book->getBookId() == borrowedISBNs[i]){
            borrowedISBNs.erase(borrowedISBNs.begin() + i);
            return;
        }
    }
}
void Member::hasBorrowedBook(){

}
bool Member::canBorrow()const {
    return borrowedISBNs.size() < 4;
}
std::vector<std::string> Member::getBorrowedBooks()const{

}
int Member::getBorrowedCount()const {

}
void Member::displayInfo() const{
    std::cout<<"name: "<<this->name<<"  |  id: "<<this->id;
}
std::string Member::getRole() const{
    return "Member";
}
std::string Member::getId()const{
    return this->id;
}
