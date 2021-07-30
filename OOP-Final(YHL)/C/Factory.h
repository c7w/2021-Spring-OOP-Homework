#ifndef FACTORY_H
#define FACTORY_H
#include "House.h"
class Factory {
public:
	virtual House* createHouse(int) = 0;
};

//TODO : finish the subclass FactoryResidence 
class FactoryResidence : public Factory {
public:
	HouseResidence *createHouse(int money)
	{
		return new HouseResidence(money, "Residence");
	}
};

//TODO : finish the subclass FactoryApartment 
class FactoryApartment : public Factory {
public:
	HouseApartment *createHouse(int money)
	{
		return new HouseApartment(money, "Apartment");
	}
};

//TODO : finish the subclass FactoryQuadrangle 
class FactoryQuadrangle : public Factory {
public:
	HouseQuadrangle *createHouse(int money)
	{
		return new HouseQuadrangle(money, "Quadrangle");
	}
};
#endif // #ifndef FACTORY_H