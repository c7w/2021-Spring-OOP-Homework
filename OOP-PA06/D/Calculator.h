#pragma once
#include "LevelStrategy.h"
#include "PerformStrategy.h"

class Calculator
{
    LevelStrategy *m_levelStrategy;
    PerformStrategy *m_perfomStrategy;
public:
    Calculator(LevelStrategy *m_levelStrategy, PerformStrategy *m_perfomStrategy)
    {
        this->m_levelStrategy = m_levelStrategy;
        this->m_perfomStrategy = m_perfomStrategy;
    }

    int get_base(){
        return m_levelStrategy->get_base();
    }

    int get_total(int x){
        return m_perfomStrategy->get_total(x);
    }
};