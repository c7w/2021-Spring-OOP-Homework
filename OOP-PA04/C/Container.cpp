#include "Container.h"

template <typename T>
void Container<T>::insert(int x, int y, T item){
    pos++;
    log[pos].topic = x;
    log[pos].reply = y;
    log[pos].admin = item;
}

template <typename T>
T* Container<T>::find(int x, int y){
    for (int i = 0; i <= pos; i++){
        if(log[i].topic == x && log[i].reply == y){
            return &log[i].admin;
        }
    }
    return nullptr;
}

