#include "person.h"
#include <string>
#include <vector>
#include <iostream>

std::string Person::getName() const {
    return this->name;
}
std::string Person::getId() const {
    return this->id;
}
void Person::setName(const std::string& name){
    this->name = name;
}
