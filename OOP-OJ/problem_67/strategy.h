#pragma once
#include "message.h"
#include <algorithm>
#include <vector>

using namespace std;

bool compare1(Message a, Message b)
{
    if (a.first_score() < b.first_score())
    {
        return false;
    }
    if (a.first_score() > b.first_score())
    {
        return true;
    }
    if (a.id() > b.id())
    {
        return true;
    }
}
bool compare2(Message a, Message b)
{
    if (a.second_score() < b.second_score())
    {
        return false;
    }
    if (a.second_score() > b.second_score())
    {
        return true;
    }
    if (a.id() > b.id())
    {
        return true;
    }
}
bool compare3(Message a, Message b)
{
    if (a.total_score() < b.total_score())
    {
        return false;
    }
    if (a.total_score() > b.total_score())
    {
        return true;
    }
    if (a.id() > b.id())
    {
        return true;
    }
}
bool compare4(Message a, Message b)
{
    if (a.id() > b.id())
    {
        return true;
    }
}
class Strategy {
public:
    virtual void sort(vector<Message>& stu_list) = 0;
};

class FirstStrategy : public Strategy {
public:
    void sort(vector<Message> &stu_list)
    {
        std::sort(stu_list.begin(), stu_list.end(), compare1);
    }
};

class SecondStrategy : public Strategy {
public:
    void sort(vector<Message> &stu_list)
    {
        std::sort(stu_list.begin(), stu_list.end(), compare2);
    }
};

class TotalStrategy : public Strategy {
public:
    void sort(vector<Message> &stu_list)
    {
        std::sort(stu_list.begin(), stu_list.end(), compare3);
    }
};

class StudentidStrategy : public Strategy {
public:
    void sort(vector<Message> &stu_list)
    {
        std::sort(stu_list.begin(), stu_list.end(), compare4);
    }
};