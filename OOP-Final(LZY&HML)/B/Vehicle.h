#pragma once
#include <iostream>
using namespace std;

class Vehicle
{
protected:
    int max_wheel;
    int max_wing;
    int wheel, wing;

public:
    void set_max_wheel_num(int x)
    {
        max_wheel = x;
    }
    void set_max_wing_num(int x)
    {
        max_wing = x;
    }
    virtual void run() { cout << "I am running" << endl; }
    void add_wheel()
    {
        wheel++;
    }
    void add_wing()
    {
        wing++;
    }
    bool finished()
    {
        return ((wheel == max_wheel) && (wing == max_wing));
    }
};