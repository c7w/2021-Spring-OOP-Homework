#include <iostream>
using namespace std;

class B{
    public:
    virtual void fn(){cout << "B";}
};
class D : public B{
    public:
    void fn(){cout << "D";}
};
int main(){
    D d;
    B* b = &d;
    b->Derive::fn();
}