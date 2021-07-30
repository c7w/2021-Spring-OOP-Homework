#include <iostream>
#include <string>
#include "MList.h"
using namespace std;

Mlist mlist;

void process(int key, string val)
{
    int sep[1001] = {0};
    sep[0]++;
    sep[sep[0]] = -1;
    for (int i = 0; i < val.length(); ++i){
        if(val[i] == '/'){
            sep[0]++;
            sep[sep[0]] = i;
        }
    }
    sep[0]++;
    sep[sep[0]] = val.length();
    for (int i = 1; i <= sep[0]-1; ++i){
        mlist.add_message(key, val.substr(sep[i] + 1, sep[i + 1] - sep[i] - 1));
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        int key;
        string val;
        cin >> key >> val;
        process(key, val);
        //mlist.add_message(key, val);
    }
    cin >> n;
    for (int i = 1; i <= n; ++i){
        int key;
        string val;
        cin >> key >> val;
        mlist.add_message(key, val);
    }
    mlist.show();
    return 0;
}