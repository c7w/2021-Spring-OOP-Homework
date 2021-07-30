#include "Test.h"
using namespace std;

Test f1(Test src);
Test& f2(Test& b);
void f3(Test& a, Test& b);

Test f1(Test src){
    src.print("a");
    return src;
}

Test& f2(Test& b){
    b.print("b");
    return b;
}

void f3(Test& a, Test& b){
    Test temp = move(a);
    a = move(b);
    b = move(temp);
}