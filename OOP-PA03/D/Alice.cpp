#include "Alice.h"
#include <iostream>
using namespace std;

int Alice::run(){
    int temp = 0;
    for (int i = 0; i < len; i++){
        int currVal = array[i].getVal();
        temp += currVal;
    }
    return temp;
}

ostream& operator<<(ostream& out, Alice& a){
    out << "Build robot Alice";
    return out;
}