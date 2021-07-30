#ifndef HOUSR_H
#define HOUSR_H
#include <string>
#include <vector>
#include <iostream>
#include "Strategy.h"
class House {
protected:
	int money;
	std::string house_type;
    Strategy* strategy;
public:
    House(int money, std::string house_type): money{money}, house_type{house_type} {}

    ~House(){}

    void setStrategy(Strategy* strategy) { this->strategy = strategy; }

    void sell(){
        std::cout << "The tax of a " << house_type << " worth " << money << " is " << strategy->caluTaxes(money) << std::endl;
    }
};

//TODO : finish the subclass HouseResidence whose house_type is Residence.
class HouseResidence : public House{
public:
    HouseResidence(int money, std::string house_type) : House(money, house_type)
    {
        strategy = new StrategyResidence();
    }
};

//TODO : finish the subclass HouseApartment whose house_type is Apartment.
class HouseApartment : public House
{
public:
    HouseApartment(int money, std::string house_type) : House(money, house_type)
    {
        strategy = new StrategyApartment();
    }
};

//TODO : finish the subclass HouseQuadrangle whose house_type is Quadrangle.
class HouseQuadrangle : public House
{
public:
    HouseQuadrangle(int money, std::string house_type) : House(money, house_type)
    {
        strategy = new StrategyQuadrangle();
    }
};
#endif // #ifndef HOUSR_H