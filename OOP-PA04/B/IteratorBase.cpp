#include <iostream>
#include "IteratorBase.h"
using namespace std;

bool IteratorBase::operator==(IteratorBase anotherIt) {
    if (this->idx == anotherIt.idx)
        return true;
    else
        return false;
}

bool IteratorBase::operator!=(IteratorBase anotherIt) {
    if (this->idx == anotherIt.idx)
        return false;
    else
        return true;
}

int IteratorBase::operator*(){
    return *data;
}

IteratorBase& IteratorBase::operator++(int dummy){
    int oldIDX = idx;
    idx++;
    if (idx == 1000) idx = 0;
    data += (idx - oldIDX);
    return *this;
}