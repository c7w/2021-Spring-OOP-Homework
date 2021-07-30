#pragma once
#include <string>
#include "OccupationStrategy.h"
#include "PayStrategy.h"

class Calculator {
    OccupationStrategy *m_occupationStrategy;
    PayStrategy* m_payStrategy;
public:
    Calculator(OccupationStrategy *rm_occupationStrategy, PayStrategy *rm_payStrategy)
    {
        m_occupationStrategy = rm_occupationStrategy;
        m_payStrategy = rm_payStrategy;
    }

    double getSalary(double base, double bonus, double level)
    {
        return m_occupationStrategy->getSalary(base, bonus, level);
    }

    double pay(std::string name, double salary)
    {
        return m_payStrategy->pay(name, salary);
    }
};