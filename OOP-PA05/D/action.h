#include "animal.h"

void action(Animal* animal,
            std::vector<Dog>& dogzone,
            std::vector<Bird>& birdzone)
{
    Dog* dogptr = dynamic_cast<Dog*>(animal);
    if (dogptr != nullptr){
        dogzone.push_back(std::move(*dogptr));
        return;
    }
    Bird* birdptr = dynamic_cast<Bird*>(animal);
    if (birdptr != nullptr) {
        birdzone.push_back(std::move(*birdptr));
        return;
    }
}