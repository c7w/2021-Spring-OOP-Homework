#include <iostream>

class opreload
{
    int data;

public:
    // 前置
    opreload &operator++()
    {
        ++data;
        return *this;
    }

    // 后置
    opreload &operator++(int dummy)
    {
        opreload return_val(*this);
        ++data;
        return return_val;
    }

    friend opreload operator++(opreload &src);
    friend opreload operator++(opreload &src, int dummy);

    friend istream &operator>>(istream &in, opreload &des);
    friend ostream &operator<<(ostream &out, const opreload &src);
};

opreload operator++(opreload &src)
{
    ++src.data;
    return src;
}

opreload operator++(opreload &src, int dummy)
{
    opreload return_val(src);
    ++src.data;
    return return_val;
}