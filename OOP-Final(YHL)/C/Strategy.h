#ifndef STRATEGY_H
#define STRATEGY_H
#include <math.h>
class Strategy {
public:
	virtual int caluTaxes(int money) = 0;
};

//TODO : finish the subclass StrategyResidence 
class StrategyResidence : public Strategy {
	const int a = 10000, b = 100000, c = 5, d = 10;

public:
	int caluTaxes(int money)
	{
		if (money <= a)
		{
			return 0;
		}else if (money <= b)
		{
			return (money - a) * c / 100;
		}else
		{
			return (money - b) * d / 100 + (b-a) * c / 100;
		}
	}
};

//TODO : finish the subclass StrategyApartment 
class StrategyApartment : public Strategy {
	const int a = 8000, b = 300000, c = 4, d = 8;

public:
	int caluTaxes(int money)
	{
		if (money <= a)
		{
			return 0;
		}
		else if (money <= b)
		{
			return (money - a) * c / 100;
		}
		else
		{
			return (money - b) * d / 100 + (b - a) * c / 100;
		}
	}
};

//TODO : finish the subclass StrategyApartment 
class StrategyQuadrangle : public Strategy {
	const int a = 50000, b = 200000, c = 6, d = 12;

public:
	int caluTaxes(int money)
	{
		if (money <= a)
		{
			return 0;
		}
		else if (money <= b)
		{
			return (money - a) * c / 100;
		}
		else
		{
			return (money - b) * d / 100 + (b - a) * c / 100;
		}
	}
};
#endif // #ifndef STRATEGY_H