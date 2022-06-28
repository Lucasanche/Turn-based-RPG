#include "stdafx.h"
#include "AbilityFactory.h"
#include "AbilityMagic.h"

Ability* AbilityFactory::createFireball()
{
	_ability = new AbilityMagic;
	_ability->setName("Fireball");
	_ability->setMagicDamage(15);
	_ability->setMpCost(5);
	_ability->setElements(Fire, Neutral);
	return _ability;
}

Ability* AbilityFactory::createBubble()
{
	_ability = new AbilityMagic;
	_ability->setName("Bubble");
	_ability->setMagicDamage(15);
	_ability->setMpCost(5);
	_ability->setElements(Water, Neutral);
	return _ability;
}

Ability* AbilityFactory::createWindBlow()
{
	_ability = new AbilityMagic;
	_ability->setName("WindBlow");
	_ability->setMagicDamage(15);
	_ability->setMpCost(5);
	_ability->setElements(Air, Neutral);
	return _ability;
}


///ABILIDADES COMBINADAS - FALTA CRAFTEO
Ability* AbilityFactory::createTsunami()
{
	_ability = new AbilityMagic;
	_ability->setName("Tsunami");
	_ability->setDescription("Duplica el daño de la habilidad hacia enemigos de fuego.");
	_ability->setMagicDamage(25);
	_ability->setMpCost(20);
	_ability->setElements(Water, Water);
	return _ability;
}

Ability* AbilityFactory::createFireTornado()
{
	_ability = new AbilityMagic;
	_ability->setName("Fire Tornado");
	_ability->setDescription("Hace daño de fuego y aire.");
	_ability->setMagicDamage(25);
	_ability->setMpCost(20);
	_ability->setElements(Fire, Air);
	return _ability;
}

Ability* AbilityFactory::createHotVampire()
{
	_ability = new AbilityMagic;
	_ability->setName("Hot Vampire");
	_ability->setDescription("Cura el 30% del daño infligido.");
	_ability->setMagicDamage(25);
	_ability->setMpCost(25);
	_ability->setElements(Fire, Neutral);
	return _ability;
}

Ability* AbilityFactory::createEarthQuake()
{
	_ability = new AbilityMagic;
	_ability->setName("EarthQuake");
	_ability->setDescription("Probabilidad de stunear al enemigo.");
	_ability->setMagicDamage(25);
	_ability->setMpCost(20);
	_ability->setElements(Water, Earth);
	return _ability;
}

Ability* AbilityFactory::createGeiser()
{
	_ability = new AbilityMagic;
	_ability->setName("Geiser");
	_ability->setDescription("Reduce la defensa mágica del enemigo.");
	_ability->setMagicDamage(25);
	_ability->setMpCost(20);
	_ability->setElements(Water, Fire);
	return _ability;
}

Ability* AbilityFactory::createPoisonGas()
{
	_ability = new AbilityMagic;
	_ability->setName("Poison Gas");
	_ability->setDescription("Envenena al enemigo hasta el final de la pelea.");
	_ability->setMagicDamage(10);
	_ability->setMpCost(25);
	_ability->setElements(Air, Neutral);
	return _ability;
}

Ability* AbilityFactory::createMagmaWave()
{
	_ability = new AbilityMagic;
	_ability->setName("Magma wave");
	_ability->setDescription("Reduce la defensa física.");
	_ability->setMagicDamage(25);
	_ability->setMpCost(20);
	_ability->setElements(Fire, Earth);
	return _ability;
}

Ability* AbilityFactory::createInferno()
{
	_ability = new AbilityMagic;
	_ability->setName("Inferno");
	_ability->setDescription("Quema al enemigo por 3 turnos.");
	_ability->setMagicDamage(30);
	_ability->setMpCost(15);
	_ability->setElements(Fire, Neutral);
	return _ability;
}

Ability* AbilityFactory::createSwirl()
{
	_ability = new AbilityMagic;
	_ability->setName("Swirl");
	_ability->setDescription("Reduce un 20% el siguiente ataque del enemigo.");
	_ability->setMagicDamage(25);
	_ability->setMpCost(30);
	_ability->setElements(Water, Air);
	return _ability;
}

Ability* AbilityFactory::createSabakuKyu()
{
	_ability = new AbilityMagic;
	_ability->setName("Sabaku Kyu");
	_ability->setDescription("Inflige daño verdadero.");
	_ability->setMagicDamage(25);
	_ability->setMpCost(30);
	_ability->setElements(Air, Earth);
	return _ability;
}









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

