#include "School.h"
#include "Student.h"
#include <iostream>
using namespace std;

School::School(int n){
    data = new Student[n + 1];
}

School::~School(){
    delete[] data;
}

void School::add_member(Student s){
    sz++;
    data[sz] = s;
}

string School::operator[](int sid){
    int stuId = -1;
    for (int i = 1; i<=sz; i++){
        if(data[i].GetSid() == sid){
            stuId = i;
            break;
        }
    }
    if(stuId == -1){
        return "Not Found\n";
    }else{
        return data[stuId].getInfo();
    }
}

string School::operator[](string name){
    int stuId = -1;
    int currData = 0, currSid = 0;
    for (int i = 1; i <= sz; i++) {
        if (data[i].GetName() == name) {
            if(data[i].GetData() > currData){
                currData = data[i].GetData();
                currSid = data[i].GetSid();
                stuId = i;
            }else if(data[i].GetData() < currData){

            }else{
                if(data[i].GetSid() > currSid){
                    currSid = data[i].GetSid();
                    stuId = i;
                }
            }

        }
    }
    if (stuId == -1) {
        return "Not Found\n";
    } else {
        return data[stuId].getInfo();
    }
}

string School::operator[](char province){
    int stuId = -1;
    int currData = 0, currSid = 0;
    for (int i = 1; i <= sz; i++) {
        if (data[i].GetProvince() == province) {
            if (data[i].GetData() > currData) {
                currData = data[i].GetData();
                currSid = data[i].GetSid();
                stuId = i;
            } else if (data[i].GetData() < currData) {
            } else {
                if (data[i].GetSid() > currSid) {
                    currSid = data[i].GetSid();
                    stuId = i;
                }
            }
        }
    }
    if (stuId == -1) {
        return "Not Found\n";
    } else {
        return data[stuId].getInfo();
    }
}