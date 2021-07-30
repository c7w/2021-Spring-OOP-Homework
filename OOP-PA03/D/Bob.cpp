#include <iostream>
#include "Bob.h"
using namespace std;

int Bob::run() {
    int temp = 0;
    for (int i = 0; i < len; i++) {
        int currVal = array[i].getVal();
        temp += currVal * currVal;
    }
    return temp;
}

ostream& operator<<(ostream& out, Bob& a) {
    out << "Build robot Bob";
    return out;
}