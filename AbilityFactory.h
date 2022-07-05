#pragma once
#ifndef ABILITYFACTORY_H
#define ABILITYFACTORY_H
#include "AbilityMagic.h"
#include "Dragon.h"

class AbilityFactory
{
private:
	AbilityMagic *_ability;
public:
	AbilityFactory();
	abilityName createAbility(abilityName, abilityName);
	Ability* createFireball();
	Ability* createBubble();
	Ability* createWindBlow();
	Ability* createTsunami();
	Ability* createFireTornado();
	Ability* createHotVampire();
	Ability* createEarthQuake();
	Ability* createGeiser();
	Ability* createPoisonGas();
	Ability* createMagmaWave();
	Ability* createInferno();
	Ability* createSwirl();
	Ability* createSabakuKyu();
	~AbilityFactory();
};

#endif