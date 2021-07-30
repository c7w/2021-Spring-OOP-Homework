#include <stack>
#include <string>
using namespace std;

#ifndef __MList__
#define __MList__
class Mlist{
    stack<string> s[10001];
    stack<int> f;
   public:
    void add_message(int n, string val);
    void show();
};

#endif