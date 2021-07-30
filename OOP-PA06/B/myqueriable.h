#include <list>
#include <vector>

using namespace std;

template <class T>
class MyQueriable
{

private:
    vector<T> _data;

public:
    MyQueriable(vector<T> src) : _data(src) {}
    MyQueriable() {}
    int size()
    {
        return _data.size();
    }

    void insert(T data)
    {
        _data.push_back(data);
    }

    template <typename F>
    MyQueriable<T> where(F func)
    {
        MyQueriable<T> newq;
        for (auto &x : _data)
        {
            if (func(x))
            {
                newq.insert(x);
            }
        }
        return newq;
    }

    template <typename F>
    MyQueriable<T> apply(F func)
    {
        MyQueriable<T> newq;
        for (auto &x : _data)
        {
            newq.insert(func(x));
        }
        return newq;
    }

    T sum()
    {
        T total = 0;
        for (auto &x : _data)
        {
            total += x;
        }

        return total;
    }

    T &operator[](int num)
    {
        return _data[num];
    }
};

template <class T>
MyQueriable<T> from(list<T> src)
{
    MyQueriable<T> newq;
    for(auto &x : src)
    {
        newq.insert(x);
    }
    return newq;
}

template <class T>
MyQueriable<T> from(vector<T> src)
{
    return MyQueriable<T>(src);
}