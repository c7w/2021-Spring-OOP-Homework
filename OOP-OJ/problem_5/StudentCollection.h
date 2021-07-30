#pragma once
#include "Student.h"
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

class StudentCollection
{
private:
    std::vector<Student> sco;
    std::map<std::string, int> sco_index;

public:
    Student& operator[] (std::string str)
    {
        if(sco_index[str])
        {
            for(auto &x:sco)
            {
                if(x.name == str)
                    return x;
            }
        }

        Student newStu;
        newStu.name = str;
        sco.push_back(newStu);
        sco_index[str] = 1;
        return sco.back();
    }

    friend std::istream& operator>>(std::istream& in, StudentCollection& sc)
    {
        std::string temp;
        in >> temp;
        
        std::string _name, _subject, _score;
        int op = 0;
        for(auto &x: temp)
        {
            if(x == '-')
            {
                op++;
                continue;
            }
            if(op == 0)
            {
                _name += x;
            }
            else if (op == 1)
            {
                _subject += x;
            }
            else
            {
                _score += x;
            }
        }
        int score = atoi(_score.c_str());
        sc[_name].setScore(_subject, score);
        return in;
    }

    void sortByScore()
    {
        std::sort(sco.begin(), sco.end());
    }

    friend std::ostream& operator<<(std::ostream& out, const StudentCollection& sc)
    {
        auto x = sc.sco.end();
        x--;
        while(x != sc.sco.begin())
        {
            out << *x << std::endl;
            x--;
        }
        out << *x << std::endl;
        return out;
    }

};