#include <iostream>
#include <regex>
#include <string>
#include <algorithm>

using namespace std;

class Student
{
public:
    string birth;
    string output;
} stu[1001];

bool comp(Student a, Student b)
{
    if (a.birth < b.birth)
    {
        return true;
    }
    else
        return false;
}

string add(string m)
{
    if (m.length() == 1)
    {
        return string("0") + m;
    }
    return m;
}

int main()
{
    int n;
    cin >> n;
    cin.get();

    for (int i = 0; i < n; ++i)
    {
        char intro[1000] = {0};
        cin.getline(intro, 1000);
        string str(intro);
        regex re1(R"((I am|My name is) (\w+)\.)");
        regex re2(R"((\d{4})[\.-](\d{1,2})[\.-](\d{1,2}))");
        regex re3(R"([1-9][0-9]{10})");
        regex re4(R"(\w[-\w.+]*@([A-Za-z0-9][-A-Za-z0-9]+\.)+[A-Za-z]{2,14})");

        smatch m1, m2, m3, m4;
        regex_search(str, m1, re1);
        regex_search(str, m2, re2);
        regex_search(str, m3, re3);
        regex_search(str, m4, re4);
        stringstream cout;
        cout << m1[2] << "-";
        cout << m2[1] << "." <<  add(m2[2]) << "." << add(m2[3]) << "-";
        cout << m3[0] << "-";
        cout << m4[0];
        cout << endl;
        cout >> stu[i].output;
        cout << m2[1] << "." << add(m2[2]) << "." << add(m2[3]);
        cout >> stu[i].birth;
    }
    sort(stu, stu + n, comp);
    for (int i = 0; i < n; ++i)
    {
        cout << stu[i].output << endl;
    }

    return 0;
}