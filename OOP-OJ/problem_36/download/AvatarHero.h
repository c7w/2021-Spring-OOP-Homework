#pragma once
#include "SkilledHero.h"

class AvatarHero : public SkilledHero {

	Hero *src = nullptr;

public:
	// TODO

	AvatarHero(Hero * _src) : src(_src) {}

	void getSkill(name2Level &skillMap) 
	{
		src->getSkill(skillMap);
		skillMap["Avatar"] += 1;
	}
	
	~AvatarHero() {}
};