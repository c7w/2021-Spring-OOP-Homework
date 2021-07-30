#include <iostream>
#include "Test.h" 
#include "func.h" 

using namespace std;

int Test::idPool = 0;
Test F(Test&& a) {
    Test b = std::move(a);
    return b;
}
int main() {
    Test A = F(1);
    return 0;
}