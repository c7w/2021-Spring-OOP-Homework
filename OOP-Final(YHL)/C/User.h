#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include "House.h"
#include "Factory.h"
class User {
private:
    std::vector<House*> house_list;
public:
    User() {}

    ~User(){
        for (int i = 0; i < house_list.size(); ++i)
            delete house_list[i];
    }

    void addHouse(int money, int label){
    	Factory* factory;
    	if (label == 1)
    		factory = new FactoryResidence();
    	else if (label == 2)
    		factory = new FactoryApartment();
    	else
    		factory = new FactoryQuadrangle();
        House* house = factory->createHouse(money);
    	house_list.push_back(house);
    	delete factory;
    }

    void sellHouse(int k){
    	house_list[k-1]->sell();
    }
};
#endif // #ifndef USER_H