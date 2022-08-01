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
	abilityName craftAbility(sf::String ab1, sf::String ab2);
	Ability createAbility(abilityName abName);
	Ability createEarthArmor();
	Ability createTest();
	Ability createBarrier();
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
	Ability createEarthquake();
	Ability createGeiser();
	Ability createPoisonGas();
	Ability createMagmaWave();
	Ability createInferno();
	Ability createSwirl();
	Ability createSabakuKyu();
	~AbilityFactory();
};

#endif