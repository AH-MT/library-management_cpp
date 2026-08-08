#include "person.h"
#include <string>
#include <vector>
#include <iostream>

std::string Person::getName() const {
    return this->name;
}
int Person::getId() const {
    return this->id;
}
int Person::getPassword() const {
    return this->password;
}
void Person::setName(const std::string& name_t){
    this->name = name_t;
}
