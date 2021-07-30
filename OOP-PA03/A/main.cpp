#include <iostream>
using namespace std;

class Test {
   public:
    int* buf;  //// only for demo.
    Test() {
        buf = new int[10];  //申请一块内存
        cout << "Test(): this->buf @ " << hex << buf << endl;
    }
    ~Test() {
        cout << "~Test(): this->buf @ " << hex << buf << endl;
        if (buf) delete[] buf;
    }
    Test(const Test& t) : buf(new int[10]) {
        for (int i = 0; i < 10; i++)
            buf[i] = t.buf[i];  //拷贝数据
        cout << "Test(const Test&) called. this->buf @ " << hex << buf << endl;
    }
    Test(Test&& t) : buf(t.buf) {  //直接复制地址，避免拷贝
        cout << "Test(Test&&) called. this->buf @ " << hex << buf << endl;
        t.buf = nullptr;  //将t.buf改为nullptr，使其不再指向原来内存区域
    }
};

Test GetTemp() {
    Test tmp;
    cout << "GetTemp(): tmp.buf @ " << hex << tmp.buf << endl;
    return tmp;
}
void fun(Test t) {
    cout << "fun(Test t): t.buf @ " << hex << t.buf << endl;
}
int main() {
    Test a = GetTemp();
    cout << "main() : a.buf @ " << hex << a.buf << endl;
    fun(a);
    return 0;
}
