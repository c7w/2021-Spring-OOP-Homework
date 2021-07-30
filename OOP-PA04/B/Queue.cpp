#include "Queue.h"

Queue::Iterator Queue::begin() {
    return Iterator(idx_begin, data + idx_begin);
}

Queue::Iterator Queue::end() {
    return Iterator(idx_end, data + idx_end);
}

int Queue::pop(){
    if(n>0){
        int temval = data[idx_begin];
        idx_begin++;
        if (idx_begin == 1000) idx_begin = 0;
        n--;
        return temval;
    }
    return 1919810;
}