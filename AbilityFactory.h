#pragma once


class AbilityFactory
{
private:
	Ability* _ability;
public:
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
};
