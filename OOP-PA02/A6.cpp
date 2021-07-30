#include <iostream>
using namespace std;

class A {
public:
    A(){}
    int data;
    void non_const_func(){}
    ~A() { cout << "A Destructing"; }
};

class B{
    int mb = 100;
    friend A::~A();
};

int main(){
    A a;
    B b;
}