#include "librarian.h"
#include <iostream>
#include <string>
#include <vector>

void Librarian::displayInfo() const{
    std::cout<<"name: "<<this->name<<"  |  id: "<<this->id;
}
std::string Librarian::getRole() const{
    return "Librarian";
}