#include "LinearDataStruct.h"
#include <iostream>
using namespace std;


void LinearDataStruct::push(int n){
    if(this->n<max_n){
        data[idx_end] = n;
        idx_end++;
        this->n+=1;
        if (idx_end == 1000) idx_end = 0;
    }
}

int LinearDataStruct::max_size(){
    return max_n;
}

int LinearDataStruct::size(){
    return n;
}



