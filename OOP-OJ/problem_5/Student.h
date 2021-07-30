#pragma once
#include <iostream>
class Student
{
public:
    std::string name;
    int cn = 0, math = 0, en = 0;
    int score;

    void setScore(std::string subject, int score)
    {
        if(subject == "Chinese")
        {
            cn = score;
        }
        if(subject == "Math")
        {
            math = score;
        }
        if(subject == "English")
        {
            en = score;
        }
        this->score = cn + math + en;
    }

    friend bool operator< (Student a, Student b)
    {
        if (a.score < b.score)
        {
            return true;
        }
        if (a.score > b.score)
        {
            return false;
        }
        if (a.cn < b.cn)
        {
            return true;
        }
        if (a.cn > b.cn)
        {
            return false;
        }
        if (a.math < b.math)
        {
            return true;
        }
        if (a.math > b.math)
        {
            return false;
        }
        if (a.en < b.en)
        {
            return true;
        }
        if (a.en > b.en)
        {
            return false;
        }
        return true;
    }

    friend std::ostream& operator<< (std::ostream& out, Student a)
    {
        out << a.name << "-Total-" << a.score << "-Chinese-" << a.cn << "-Math-" << a.math << "-English-" << a.en;
        return out;
    }
};