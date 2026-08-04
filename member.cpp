#include "member.h"
#include <iostream>
#include <string>
#include <vector>

void Member::borrowBook(){

}
void Member::returnBook(){

}
void Member::hasBorrowedBook(){

}
bool Member::canBorrow()const {

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