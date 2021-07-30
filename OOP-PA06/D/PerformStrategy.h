#pragma once
class PerformStrategy{
protected:
    double p;

public:
    PerformStrategy(double p) : p(p) {}
    virtual int get_total(int x) = 0;
};

class sPerformStrategy : public PerformStrategy
{
public:
    using PerformStrategy::PerformStrategy;
    virtual int get_total(int x) { return x + 1000; }
};

class mPerformStrategy : public PerformStrategy
{
public:
    using PerformStrategy::PerformStrategy;
    virtual int get_total(int x) { return x + x * p; }
};
class lPerformStrategy : public PerformStrategy
{
public:
    using PerformStrategy::PerformStrategy;
    virtual int get_total(int x) { return x + x * p * 2; }
};