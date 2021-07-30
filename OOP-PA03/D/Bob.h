#pragma once
#include <iostream>
#include "Robot.h"
using namespace std;

class Bob : public Robot {
   public:
    using Robot::Robot;
    int run();
    friend ostream& operator<<(ostream& out, Bob& a);
};