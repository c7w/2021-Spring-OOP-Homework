#ifndef __QUEUE
#define __QUEUE

#include "LinearDataStruct.h"
#include "IteratorBase.h"

class Queue: public LinearDataStruct {
    // TODO
public:

    class Iterator: public IteratorBase {
        // TODO
       public:
        Iterator(int idx, int* data) : IteratorBase(data, idx) {}
    };

    using LinearDataStruct::LinearDataStruct;
    int pop();
    Iterator begin();
    Iterator end();
};

#endif