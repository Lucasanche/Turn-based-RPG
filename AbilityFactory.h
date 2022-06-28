#pragma once
#ifndef ABILITYFACTORY_H
#define ABILITYFACTORY_H

#include "AbilityMagic.h"

class AbilityFactory
{
private:
	Ability* _ability;
public:
	AbilityFactory();
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