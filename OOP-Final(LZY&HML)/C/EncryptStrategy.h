#pragma once
# include <string>

class EncryptStrategy{
public:
	virtual std::string encode(std::string mes) = 0;
};

class InsertStrategy : public EncryptStrategy
{
public:
	std::string encode(std::string mes)
	{
		std::string result;
		for (auto &x : mes)
		{
			result += x;
			result += '#';
		}
		return result;
	}
};

class InvertStrategy : public EncryptStrategy
{
public:
	std::string encode(std::string mes)
	{
		std::string result;
		auto x = mes.end();
		x--;
		while(x != mes.begin())
		{
			result += *x;
			x--;
		}
		result += *x;
		return result;
	}
};

