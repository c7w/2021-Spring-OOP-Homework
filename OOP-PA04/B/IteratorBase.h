#ifndef __ITERATORBASE
#define __ITERATORBASE

class IteratorBase {
    
protected:
    int* data;
    int idx;

public:

    IteratorBase(int* _data, int _idx): data(_data), idx(_idx) {

    }

    // TODO
    bool operator==(IteratorBase anotherIt);
    bool operator!=(IteratorBase anotherIt);
    int operator*();
    IteratorBase& operator++(int);
};


#endif