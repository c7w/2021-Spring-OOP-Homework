#include <cstring>
#include <iostream>
#include "what.h"
using namespace std;

#ifndef __ALIEN__
#define __ALIEN__
class Alien : public WhatCanMotion, public WhatCanSpeak{
   private:
    string name;
   public:
    Alien(string k): name(k){}
    void motion() { cout << name << " is moving" << endl; }
    void speak() { cout << name << " is speaking" << endl; }
    void stop() { cout << name << " stops" << endl; }
};
#endif