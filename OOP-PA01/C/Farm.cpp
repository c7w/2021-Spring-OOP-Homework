#include "Farm.h"
#include "Cow.h"
#include <string>
using namespace std;

Farm::Farm(int n){
    n = n;
}
void Farm::addCow(Cow w){
    cowPos++;
    s[cowPos] = w;
}

int Farm::findCowById(string name){
    for (int i = 1; i <= cowPos; i++){
        if(s[i].getName() == name){
            return i;
        }
    }
    return 0;
}

void Farm::supply(string name, int a){
    int id = findCowById(name);
    s[id].supply(a);
}

void Farm::startMeal(){
    for (int i = 1; i <= cowPos; i++){
        if(s[i].getleftMeal() == 0){
            s[i].setStatus(0);
            continue;
        }
        if(s[i].getleftMeal() < s[i].getL()){
            s[i].setStatus(1);
            s[i].eatMeal(s[i].getleftMeal());
            continue;
        }
        if(s[i].getleftMeal() <= s[i].getU()){
            s[i].setStatus(2);
            s[i].eatMeal(s[i].getleftMeal());
            continue;
        }
        if(s[i].getleftMeal() > s[i].getU()){
            s[i].setStatus(2);
            s[i].eatMeal(s[i].getU());
            continue;
        }
    }
}

void Farm::produceMilk(){
    for (int i = 1; i <= cowPos; i++){
        if(s[i].getStatus() == 0){
            milkProduction += 0;
        }
        if(s[i].getStatus() == 1){
            milkProduction += 0.5 * (double)s[i].getM();
        }
        if(s[i].getStatus() == 2){
            milkProduction += (double)s[i].getM();
        }
    }
}

double Farm::getMilkProduction(){
    return milkProduction;
}