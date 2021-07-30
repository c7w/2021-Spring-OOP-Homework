#include "MList.h"
#include <stack>
#include <iostream>
#include <string>
using namespace std;

void Mlist::add_message(int n, string val) 
{
    f.push(n);
    s[n].push(val);
}

void Mlist::show()
{
    while(!f.empty()){
        int k = f.top();
        f.pop();
        if(!s[k].empty()){
            cout << k << endl;
        }
        while (!s[k].empty()) {
            string v = s[k].top();
            cout << v << endl;
            s[k].pop();
        }
    }
}