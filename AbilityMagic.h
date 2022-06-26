#pragma once
#include "Ability.h"

class AbilityMagic : public Ability
{
private:
	int _damage;
	float _PDreduced;
	float _MRreduced;
	bool _damageMultiplier,
		_vampireishon,
		_stun,
		_reducePD,
		_reduceMR,
		_burns,
		_poison,
		_reduceAtt,
		_truedamash;
public: 
	AbilityMagic();
	//void setFireball();
	//ability.setFireball();
	float useAbility(Dragon &dragon);

};

