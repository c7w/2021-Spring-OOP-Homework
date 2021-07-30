#pragma once
# include <string>

class VerificationStrategy{
public:
	virtual std::string verify(std::string mes) = 0;
};

class PrefixStrategy : public VerificationStrategy
{
public:
	std::string verify(std::string mes)
	{
		std::string result;
		for (int i = 0; i < 3; i ++)
		{
			result += mes[i];
		}
		return result;
	}
};

class IntervalStrategy : public VerificationStrategy
{
public:
	std::string verify(std::string mes)
	{
		std::string result;
		int size = mes.size();
		for (int i = 0; i < mes.size(); i+=2)
		{
			result += mes[i];
		}
		return result;
	}
};
