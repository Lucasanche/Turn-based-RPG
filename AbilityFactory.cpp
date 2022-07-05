#include "stdafx.h"
#include "AbilityFactory.h"


AbilityFactory::AbilityFactory()
{
	//Fireball

}

abilityName AbilityFactory::createAbility(abilityName ab1, abilityName ab2) {
	if (ab1 == Fireball || ab2 == Fireball) {
		if (ab1 == WindBlow || ab2 == WindBlow) {
			return FireTornado;
		}
		if (ab1 == Heal || ab2 == Heal) {
			return HotVampire;
		}
		if (ab1 == Bubble || ab2 == Bubble) {
			return Geiser;
		}
		if (ab1 == EarthArmor || ab2 == EarthArmor) {
			return MagmaWave;
		}
	}
	if (ab1 == Bubble || ab2 == Bubble) {
		if (ab1 == EarthArmor || ab2 == EarthArmor) {
			return Earthquake;
		}
		if (ab1 == WindBlow || ab2 == WindBlow) {
			return Swirl;
		}
	}
	if (ab1 == WindBlow || ab2 == WindBlow) {
		if (ab1 == Heal || ab2 == Heal) {
			return PoisonGas;
		}
		if (ab1 == EarthArmor || ab2 == EarthArmor) {
			return SabakuKyu;
		}
	}
	if (ab1 == Mirror || ab2 == Mirror) {
		if (ab1 == EarthBarrier || ab2 == EarthBarrier || ab1 == WaterBarrier || ab2 == WaterBarrier || ab1 == FireBarrier || ab2 == FireBarrier || ab1 == WindBarrier || ab2 == WindBarrier) {
			return Restore;
		}
	}
	if (ab1 == Barrier || ab2 == Barrier) {
		if (ab1 == EarthArmor || ab2 == EarthArmor) {
			return EarthBarrier;
		}
		if (ab1 == WindBlow || ab2 == WindBlow){
		}

	}
}

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

AbilityFactory::~AbilityFactory()
{
	delete _ability;
	_ability = nullptr;
	if (_ability != nullptr) {
		std::cout << "no se liberó la memoria de AbilityFactory/n";
	}
}
