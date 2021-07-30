#pragma once
#include <iostream>
using namespace std;

class Student {
    int sid;
    string name;
    char province;
    int data;
    char grade;

   public:
    friend istream& operator>>(istream& in, Student& stu);
    string getInfo();
    int GetSid() const { return sid; }
    void SetSid(int sid) { this->sid = sid; }
    string GetName() const { return name; }
    void SetName(string name) { this->name = name; }
    char GetProvince() const { return province; }
    void SetProvince(char province) { this->province = province; }
    int GetData() const { return data; }
    void SetData(int data) { this->data = data; }
    char GetGrade() const { return grade; }
    void SetGrade(char grade) { this->grade = grade; }
};