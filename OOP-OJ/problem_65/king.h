#pragma once
#include "card.h"

class King : public Card
{
public:
    King() : Card("king") {}
    int battle(Card *other) {
        if (other->name() == "beggar")
            return -1;
        
        if (other->name() == "soldier")
            return 1;

        return 0;
    }
};