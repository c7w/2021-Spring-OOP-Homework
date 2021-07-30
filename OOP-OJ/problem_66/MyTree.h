#pragma once
#include <iostream>
#include "BaseTree.h"

class MyTree: public BaseTree {

    int getElement(int x)
    {
        return getsum(x) - getsum(x - 1);
    }

public:
    void add(int x, int t)
    {
        update(x, t);
    }

    void sub(int x, int t)
    {
        update(x, -t);
    }

    void query(int l, int r)
    {
        std::cout <<  getsum(r) - getsum(l-1) << std::endl;
    }

    void set (int x, int t)
    {
        update(x, t - getElement(x));
    }

    void mul ( int x, int t)
    {
        int curr = getElement(x);
        update(x, curr * (t - 1));
    }

};
