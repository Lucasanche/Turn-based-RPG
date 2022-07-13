#pragma once
#ifndef ABILITYFACTORY_H
#define ABILITYFACTORY_H

#include "Ability.h"

class AbilityFactory
{
private:
	Ability _ability;
public:
	AbilityFactory();
	Ability combineAbility(abilityName ab1, abilityName ab2);
	Ability createAbility(abilityName abName);
	Ability createEarthArmor();
	Ability createTest();

	/*Ability createBarrier();
	Ability createHeal();
	Ability createRestore();
	Ability createCosmicWisdom();
	Ability createDoton();
	Ability createFireball();
	Ability createBubble();
	Ability createWindBlow();
	Ability createTsunami();
	Ability createFireTornado();
	Ability createHotVampire();
	Ability createEarthQuake();
	Ability createGeiser();
	Ability createPoisonGas();
	Ability createMagmaWave();
	Ability createInferno();
	Ability createSwirl();
	Ability createSabakuKyu();
	~AbilityFactory();*/
};

#endif