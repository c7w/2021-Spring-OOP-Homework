#include "Student.h"
#include <iostream>
#include <sstream>
using namespace std;

// [l, r)
string range(string raw, int l, int r){
    string oper = "";
    for (int i = l; i < r; i++)
        oper += raw[i];
    return oper;
}

istream& operator>>(istream& in, Student& stu){
    string raw;
    in >> raw;
    int dashPos[4], dashPosP = -1;
    int len = raw.length();
    for (int i = 0; i < len; i++){
        if(raw[i] == '-') {
            dashPosP++;
            dashPos[dashPosP] = i;
        }
    }


    stu.SetName(range(raw, 0, dashPos[0]));
    stu.SetProvince(raw[dashPos[1] - 1]);
    stu.SetGrade(raw[dashPos[1] + 1]);

    string dates = range(raw, dashPos[2] + 1, dashPos[3]);
    string sids = range(raw, dashPos[3] + 1, len);
    stu.SetData(atoi(dates.c_str()));
    stu.SetSid(atoi(sids.c_str()));

    return in;
}

string Student::getInfo(){
    stringstream ss;
    ss << name <<  "-";
    if(data < 10){
        ss << "000" << data;
    }else if (data < 100){
        ss << "00" << data;
    }else if(data < 1000){
        ss << "0" << data;
    }else{
        ss << data;
    }
    ss << "-" << grade << "-" << sid << endl;
    string output = ss.str();
    return output;
}