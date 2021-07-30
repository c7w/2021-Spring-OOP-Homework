#include "Stack.h"

Stack::Iterator Stack::begin() {
    return Iterator(idx_begin, data + idx_begin);
}

Stack::Iterator Stack::end() {
    return Iterator(idx_end, data + idx_end);
}

int Stack::pop() {
    if(n!=0){
        idx_end--;
        if (idx_end == -1) idx_end = 999;
        n--;
        return data[idx_end];
    }
    return 1919810;
}