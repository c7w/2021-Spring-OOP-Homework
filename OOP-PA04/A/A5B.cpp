#include <iostream>
using namespace std;
class B {
   public:
    virtual void f(){};
};
class D : public B {
   // public:
    // int i{2018};
    public:
    void f(){}
};
int main() {
    D d;
    B b;
    B* b2 = new D();
    //    D d1 = static_cast<D>(b); ///未定义类型转换方式
    //    D d2 = dynamic_cast<D>(b); ///只允许指针和引用转换

    D* pd1 = static_cast<D*>(b2);  /// 有继承关系，允许转换
    if (pd1 != nullptr) {
        cout << "static_cast, B*(B) --> D*: OK" << endl;
        // cout << "D::i=" << pd1->i << endl;
    }
    /// 但是不安全：对D中成员i可能非法访问

    D* pd2 = dynamic_cast<D*>(b2);
    if (pd2 == nullptr)  /// 不允许不安全的转换
        cout << "dynamic_cast, B*(B) --> D*: FAILED" << endl;
}