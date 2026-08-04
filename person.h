#pragma once
#include <string>
#include <vector>

class Person{
    protected:
        std::string name;
        const std::string id;
    public:
        Person(std::string name, std::string id):name(std::move(name)),id(std::move(id)){}
        //getters
        std::string getName()const;
        std::string getId()const;
        virtual void displayInfo()const = 0;
        virtual std::string getRole()const = 0;
        
        //setters
        void setName(const std::string& name);
        virtual ~Person(){}
    };
