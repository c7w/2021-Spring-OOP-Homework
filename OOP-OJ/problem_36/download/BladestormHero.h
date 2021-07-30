#pragma once
#include "SkilledHero.h"

class BladestormHero : public SkilledHero {
	// TODO

	Hero *src = nullptr;

public:
	BladestormHero(Hero* _src)
	{
		src = _src;
	}

	void getSkill(name2Level &skillMap)
	{
		src->getSkill(skillMap);
		skillMap["Bladestorm"] += 1;
	}

	~BladestormHero() {}
};