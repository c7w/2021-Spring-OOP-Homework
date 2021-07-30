#pragma once
#include "card.h"

class Soldier : public Card
{
public:
    Soldier() : Card("soldier") {}
    int battle(Card *other)
    {
        if (other->name() == "beggar")
            return 1;

        if (other->name() == "king")
            return -1;

        return 0;
    }
};