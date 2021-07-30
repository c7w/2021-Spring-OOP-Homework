#include "Cow.h"
#include <string>
using namespace std;

Cow::Cow(){
    
}

Cow::Cow(string name, int l, int u, int m){
    this->name = name;
    this->l = l;
    this->u = u;
    this->m = m;
}

string Cow::getName(){
    return name;
}

void Cow::supply(int k){
    leftMeal += k;
}

int Cow::getleftMeal(){
    return leftMeal;
}

void Cow::eatMeal(int k){
    leftMeal -= k;
}
int Cow::getStatus(){
    return status;
}

void Cow::setStatus(int k){
    status = k;
}

int Cow::getL(){
    return l;
}

int Cow::getU(){
    return u;
}

int Cow::getM(){
    return m;
}

