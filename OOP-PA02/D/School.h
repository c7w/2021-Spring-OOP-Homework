#pragma once
#include "Student.h"

class School {
   private:
    Student* data;
    int sz = 0;

   public:
    School(int n);
    ~School();
    void add_member(Student s);
    string operator[](int sid);
    string operator[](string name);
    string operator[](char province);
};