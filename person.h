#pragma once
#include <string>
#include <vector>

class Person{
    protected:
        std::string name;
        int id;
        int password;
    public:
        Person(std::string name_t, int id_t, int pasword_t):name(std::move(name_t)),id(id_t),password(pasword_t){}
        //getters
        std::string getName()const;
        int getId()const;
        int getPassword()const;
        virtual void displayInfo()const = 0;
        virtual std::string getRole()const = 0;
        
        //setters
        void setName(const std::string& name_t);
        virtual ~Person(){}
};
