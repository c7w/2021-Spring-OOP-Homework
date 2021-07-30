#pragma once
#include <iostream>
#include "Robot.h"
using namespace std;

class Alice : public Robot{
   public:
    using Robot::Robot;    
    int run();
    friend ostream& operator<<(ostream& out, Alice& a);
};