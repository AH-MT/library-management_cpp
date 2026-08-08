#include "member.h"
#include <iostream>
#include <algorithm>

void Member::borrowBook(const Book* book){
    borrowedISBNs.push_back(book->getBookId());
}
void Member::returnBook(const Book* book){
    auto it = std::find(borrowedISBNs.begin(), borrowedISBNs.end(), book->getBookId());
    if (it != borrowedISBNs.end()) {
        borrowedISBNs.erase(it);
    }
}
bool Member::canBorrow()const {
    return borrowedISBNs.size() < 4;
}
void Member::displayInfo() const{
    std::cout<<"name: "<<this->name<<"  |  id: "<<this->id;
}
std::string Member::getRole() const{
    return "Member";
}
int Member::getId()const{
    return this->id;
}
const std::vector<int>* Member::getBooks() const{
    return &borrowedISBNs;
}
