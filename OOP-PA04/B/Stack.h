#ifndef __STACK
#define __STACK

#include "LinearDataStruct.h"
#include "IteratorBase.h"

class Stack: public LinearDataStruct {
    // TODO
public:

    class Iterator: public IteratorBase {
        // TODO
       public:
        Iterator(int idx, int* data) : IteratorBase(data, idx) {}
    };

    // TODO
    using LinearDataStruct::LinearDataStruct;
    int pop();
    Iterator begin();
    Iterator end();
};


#endif