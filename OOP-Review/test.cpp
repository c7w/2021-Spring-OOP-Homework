#include <iostream>
#include <vector>
using namespace std;

template <class T>
void print(vector<T>& v)
{
    for (auto &x: v)
    {
        cout << x << " ";
    }
    cout << endl;
}



int main()
{
    vector<int> v;
    for (int i = 0; i < 5; ++i)
    {
        v.push_back(i);
    }
    print(v);

    for(auto x:v)
    {
        x += 1;
    }
    print(v);

    for(auto &x:v)
    {
        x += 1;
    }
    print(v);

    for (auto x = v.begin(); x != v.end(); x++)
    {
        *x += 1;
    }
    print(v);
    return 0;
}