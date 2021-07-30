// 本次提交仅修正离场后的题面修改问题

#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Instruction
{
public:
    virtual void apply(std::vector<int> &vec) = 0;
    virtual void apply(std::vector<double> &vec) = 0;
    virtual void output() = 0;
};


class plusConst : public Instruction
{
    int pos;
    int num;

public:
    plusConst(int p, int x) : pos(p), num(x) {}
    void apply(std::vector<int> &vec)
    {
        vec[pos] += num;
    }
    void apply(std::vector<double> &vec)
    {
        vec[pos] += num;
    }
    void output()
    {
        std::cout << "arr[" << pos << "] += " << num << std::endl;
    }
};

class plusElement : public Instruction
{
    int src;
    int des;

public:
    plusElement(int s, int d) : src(s), des(d) {}
    void apply(std::vector<int> &vec)
    {
        vec[des] += vec[src];
    }
    void apply(std::vector<double> &vec)
    {
        vec[des] += vec[src];
    }
    void output()
    {
        std::cout << "arr[" << des << "] += arr[" << src << "]" << std::endl;
    }
};

class assignElement : public Instruction
{
    int src;
    int des;

public:
    assignElement(int s, int d) : src(s), des(d) {}
    void apply(std::vector<int> &vec)
    {
        vec[des] = vec[src];
    }
    void apply(std::vector<double> &vec)
    {
        vec[des] = vec[src];
    }
    void output()
    {
        std::cout << "arr[" << des << "] = arr[" << src << "]" << std::endl;
    }
};

class outputElement : public Instruction
{
    int id;
    ostream &out;

public:
    outputElement(ostream& os, int pos) : out(os), id(pos) {}
    void apply(std::vector<int> &vec)
    {
        if (id != -1) 
        {
            out << vec[id];
            return;
        }
        out << endl;
    }
    void apply(std::vector<double> &vec)
    {
        if (id != -1)
        {
            out << vec[id];
            return;
        }
        out << endl;
    }
    void output()
    {
        if (id != -1)
        {
            std::cout << "cout << arr[" << id << "]" << std::endl;
            return;
        }
        std::cout << "cout << endl" << std::endl;
    }
};