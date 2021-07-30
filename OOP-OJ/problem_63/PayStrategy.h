#pragma once
#include <string>

class PayStrategy {
public:
	virtual double pay(std::string name, double money) = 0;
};

class NormalStrategy : public PayStrategy {
public:
	double pay(std::string name, double money)
	{
		return money;
	}
};

class SwiftStrategy : public PayStrategy {
public:
	double pay(std::string name, double money)
	{
		if (money <= 10000)
		{
			return money - 10;
		}
		double tax = money / 1000;
		if(tax>20)
			tax = 20;
		return money - tax;
	}
};

class BitcoinStrategy : public PayStrategy {
public:
	double pay(std::string name, double money)
	{
		return money - (name.length() + 8) * 0.01;
	}
};
