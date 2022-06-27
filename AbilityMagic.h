#pragma once
#include "Ability.h"

class AbilityMagic : public Ability
{
private:
	int _magicDamage;
	bool _damageMultiplier,
		_vampireishon,
		_stun,
		_reducePD,
		_reduceMR,
		_reduceAtt,
		_burns,
		_poison,
		_truedamash;
public: 
	AbilityMagic();
	//void setFireball();
	//ability.setFireball();
	float useAbility(Dragon &dragon);

};

