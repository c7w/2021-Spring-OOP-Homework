#pragma once

#include <string>
#include <iostream>

class Animal{
private:
public:
    std::string name;
    Animal(std::string _name): name(_name) {}
    virtual void speak() = 0;
    virtual void swim() = 0;
    virtual void action()
    {
        this->speak();
        this->swim();
    }
    virtual ~Animal() {}
};