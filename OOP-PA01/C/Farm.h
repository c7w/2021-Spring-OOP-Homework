#include "Cow.h"
#include <string>
using namespace std;

#ifndef __farm__
#define __farm__
class Farm {
   private:
    int cowNum;
    int cowPos = 0;
    Cow s[101];

    double milkProduction = 0.0;

    int findCowById(string name);

   public:
    Farm(int n);
    void addCow(Cow w);
    void supply(string name, int a);

    void startMeal();
    void produceMilk();

    double getMilkProduction();
};
#endif