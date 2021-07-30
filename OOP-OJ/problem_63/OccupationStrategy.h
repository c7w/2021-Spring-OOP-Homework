#pragma once

class OccupationStrategy {
public:
	virtual double getSalary(double base, double bonus, double level) = 0;
};

class SalesmanStrategy : public OccupationStrategy {

public:
	double getSalary(double base, double bonus, double level)
	{
		if( level <60)
			bonus = 0;
		else if (level < 70)
			bonus *= 0.6;
		else if (level < 80)
			bonus *= 0.7;

		return base + bonus;
	}
};

class DeveloperStrategy : public OccupationStrategy {
public:
	double getSalary(double base, double bonus, double level)
	{
		bonus *= (level / 100);
		return base + bonus;
	}
};