#include <string>
using namespace std;

#ifndef __Cow__
#define __Cow__
class Cow{
   private:
    int cowNum;
    string name;
    int l;
    int u;
    int m;
    int leftMeal = 0;
    int status = 0;
    // 0 零产量 1 半产量 2 标准产量

   public:
    Cow();
    Cow(string name, int l, int u, int m);
    string getName();
    void supply(int a);

    int getleftMeal();
    void eatMeal(int k);
    int getStatus();
    void setStatus(int k);

    int getL();
    int getU();
    int getM();
};
#endif