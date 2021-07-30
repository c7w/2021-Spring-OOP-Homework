#include <iostream>
using namespace std;

class Test {
    const int member1;
    static float member2;

   public:
    Test(int mem) : member1(mem) {}
    int MyMember1() const {
        member2 += 2;
        return member1;
    }
    static float Mymember2() { return member2; }
};
float Test::member2 = 0;

int main(){
    const Test t(2);
    cout << t.MyMember1();
    cout << t.Mymember2();
}