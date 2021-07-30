class B {
public:
   B(int i) {}
};

class A {
private:
   int a = 1;
   B b;   // (2)
public:
   A() = default; // (1)
   A(int i):a(i), b(i) {}
};

int main(){
    A a;
}