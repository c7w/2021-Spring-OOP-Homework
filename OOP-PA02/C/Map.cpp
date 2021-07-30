#include "Map.h"
#include <string>
using namespace std;

int Map::size(){
    return sz;
}

Map::Map(int n){
    sz = 0;
    data = new Pair[n];
}

Map::~Map(){
    delete[] data;
}

int Map::operator[](string s) const{
    bool hasKey = false;
    int keyId = 0;
    for (int i = 1; i <= sz; i++){
        if(data[i].hasKey(s)){
            keyId = i;
            hasKey = true;
            break;
        }
    }
    if(hasKey){
        return data[keyId].getVal();
    }else{
        return 0;
    }
}

int& Map::operator[](string s){
    bool hasKey = false;
    int keyId = 0;
    for (int i = 1; i <= sz; i++) {
        if (data[i].hasKey(s)) {
            keyId = i;
            hasKey = true;
            break;
        }
    }
    if (hasKey) {
        return data[keyId].getVal();
    } else {
        sz++;
        data[sz].reset(s, 0);
        return data[sz].getVal();
    }
}

