#pragma once
#include <vector>
#include "Instruction.h"
using namespace std;

class specialElement
{
    
public:
    int id;
    vector<Instruction *>* ins;
    void operator+=(int x)
    {
        ins->push_back(new plusConst(id, x));
    }
    void operator+=(specialElement another)
    {
        ins->push_back(new plusElement(another.id, id));
    }
    void operator=(specialElement another)
    {
        ins->push_back(new assignElement(another.id, id));
    }
    friend ostream& operator<<(ostream& out, const specialElement& se)
    {
        se.ins->push_back(new outputElement(out, se.id));
        return out;
    }

};

class MagicArray
{
    int size;
    vector<Instruction *> ins;
    specialElement *se;

public:
    MagicArray(int s) : size(s) {
        se = new specialElement[s];
        for (int i = 0; i < s; ++i)
        {
            se[i].id = i;
            se[i].ins = &ins;
        }
    }
    
    specialElement& operator[] (int id)
    {
        return se[id];
    }

    void apply(std::vector<int> &vec)
    {
        for(auto &x:ins)
        {
            x->apply(vec);
        }
    }
    void apply(std::vector<double> &vec)
    {
        for(auto &x:ins)
        {
            x->apply(vec);
        }
    }

    std::vector<Instruction *> &getInstructions()
    {
        return ins;
    }

    specialElement endl()
    {
        specialElement k;
        k.id = -1;
        k.ins = &ins;
        return k;
    }
};