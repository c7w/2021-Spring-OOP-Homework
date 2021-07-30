#pragma once
#include "Pair.h"
#include <string>
using namespace std;

class Map{
    Pair * data;
    int sz;
public:
    Map(int n);
    // TODO
    ~Map();
    int& operator[](string s);
    int operator[](string s) const;
    int size();
};