#include "stdafx.h"
#include "AbilityFactory.h"


AbilityFactory::AbilityFactory() {
	_ability.reset();
}

abilityName	AbilityFactory::craftAbility(std::string ab1, std::string ab2) {
	//TODO: ver "TO DO" de createAbility en AbilityFactory
	if (ab1 == "Fireball" || ab2 == "Fireball") {
		if (ab1 == "WindBlow" || ab2 == "WindBlow") {
			return FireTornado;
		}
		if (ab1 == "Heal" || ab2 == "Heal") {
			return HotVampire;
		}
		if (ab1 == "Bubble" || ab2 == "Bubble") {
			return Geiser;
		}
		if (ab1 == "Earth Armor" || ab2 == "Earth Armor") {
			return MagmaWave;
		}
	}
	if (ab1 == "Bubble" || ab2 == "Bubble") {
		if (ab1 == "Earth Armor" || ab2 == "Earth Armor") {
			//this->createEarthquake();
		}
		if (ab1 == "WindBlow" || ab2 == "WindBlow") {
			return Swirl;
		}
	}
	if (ab1 == "WindBlow" || ab2 == "WindBlow") {
		if (ab1 == "Heal" || ab2 == "Heal") {
			return PoisonGas;
		}
		if (ab1 == "Earth Armor" || ab2 == "Earth Armor") {
			return SabakuKyu;
		}
	}
	if (ab1 == "Mirror" || ab2 == "Mirror") {
		if (ab1 == "Earth Barrier" || ab2 == "Earth Barrier" || ab1 == "Water Barrier" || ab2 == "Water Barrier" || ab1 == "Fire Barrier" || ab2 == "Fire Barrier" || ab1 == "Wind Barrier" || ab2 == "Wind Barrier") {
			return Restore;
		}
	}
	if (ab1 == "Barrier" || ab2 == "Barrier") {
		if (ab1 == "Earth Armor" || ab2 == "Earth Armor") {
			//return this->createEarthBarrier();
		}
		if (ab1 == "WindBlow" || ab2 == "WindBlow") {
			 return EarthArmor;
		}
	}
	else { return CraftError; }
}



Ability AbilityFactory::createAbility(abilityName abName) {
	//TODO: implementar métodos correspondientes y descomentar (estos métodos también sirven para el método combineAbility) - Lucas
	switch (abName) {
	case Fireball:
		return this->createFireball();
		break;
	case Bubble:
		return this->createBubble();
		break;
	case WindBlow:
		return this->createWindBlow();
		break;
	case EarthArmor:
		return this->createEarthArmor();
		break;
	case Barrier:
		return this->createBarrier();
		break;
	case Heal:
		return this->createBarrier();
		break;
	case Restore:
		return this->createRestore();
		break;
	case EarthBarrier:
		//return this->createEarthBarrier();
		break;
	case WindBarrier:
		//return this->createWindBarrier();
		break;
	case WaterBarrier:
		//return this->createWaterBarrier();
		break;
	case FireBarrier:
		//return this->createFireBarrier();
		break;
	case Mirror:
		//return this->createMirror();
		break;
	case Tsunami:
		return this->createTsunami();
		break;
	case FireTornado:
		return this->createFireTornado();
		break;
	case HotVampire:
		return this->createHotVampire();
		break;
	case Earthquake:
		//return this->createEarthquake();
		break;
	case Geiser:
		return this->createGeiser();
		break;
	case PoisonGas:
		return this->createPoisonGas();
		break;
	case MagmaWave:
		return this->createMagmaWave();
		break;
	case Inferno:
		return this->createInferno();
		break;
	case Swirl:
		return this->createSwirl();
		break;
	case SabakuKyu:
		return this->createSabakuKyu();
		break;
	case Doton:
		return this->createDoton();
		break;
	case Test:
		return this->createTest();
	}
	return Ability();
}

Ability AbilityFactory::createTest() {
	_ability.reset();
	_ability.setMpCost(10);
	_ability.setMagicDamage(10);
	_ability.setName("Test");
	_ability.setReduceAtt();
	_ability.setHeal();
	return _ability;
}

//ABILITY SUPPORT
Ability AbilityFactory::createEarthArmor() {
	_ability.reset();
	_ability.setName("Earth Armor");
	_ability.setMpCost(5);
	_ability.setElements(Earth, Neutral);
	return _ability;
}



Ability AbilityFactory::createBarrier()
{
	_ability.reset();
	_ability.setName("Barrier");
	_ability.setMpCost(5);
	_ability.setElements(Neutral, Neutral);
	return _ability;
}

Ability AbilityFactory::createHeal()
{
	_ability.reset();
	_ability.setName("Heal");
	_ability.setMpCost(10);
	_ability.setElements(Neutral, Neutral);
	return _ability;
}


//ABILITY MAGIC
Ability AbilityFactory::createFireball()
{
	_ability.reset();
	_ability.setName("Fireball");
	_ability.setMagicDamage(15);
	_ability.setMpCost(5);
	_ability.setElements(Fire, Neutral);
	return _ability;
}

Ability AbilityFactory::createBubble()
{
	_ability.reset();
	_ability.setName("Bubble");
	_ability.setMagicDamage(15);
	_ability.setMpCost(5);
	_ability.setElements(Water, Neutral);
	return _ability;
}

Ability AbilityFactory::createWindBlow()
{
	_ability.reset();
	_ability.setName("WindBlow");
	_ability.setMagicDamage(15);
	_ability.setMpCost(5);
	_ability.setElements(Air, Neutral);
	return _ability;
}


///HABILIDADES COMBINADAS MAGIC - FALTA CRAFTEO
Ability AbilityFactory::createTsunami()
{
	_ability.reset();
	_ability.setName("Tsunami");
	_ability.setDescription("Duplica el daño de la habilidad hacia enemigos de fuego.");
	_ability.setMagicDamage(25);
	_ability.setMpCost(20);
	_ability.setElements(Water, Water);
	return _ability;
}

Ability AbilityFactory::createFireTornado()
{
	_ability.reset();
	_ability.setName("Fire Tornado");
	_ability.setDescription("Hace daño de fuego y aire.");
	_ability.setMagicDamage(25);
	_ability.setMpCost(20);
	_ability.setElements(Fire, Air);
	return _ability;
}

Ability AbilityFactory::createHotVampire()
{
	_ability.reset();
	_ability.setName("Hot Vampire");
	_ability.setDescription("Cura el 30% del daño infligido.");
	_ability.setMagicDamage(25);
	_ability.setMpCost(25);
	_ability.setElements(Fire, Neutral);
	return _ability;
}

Ability AbilityFactory::createEarthQuake()
{
	_ability.reset();
	_ability.setName("Earthquake");
	_ability.setDescription("Probabilidad de stunear al enemigo.");
	_ability.setMagicDamage(25);
	_ability.setMpCost(20);
	_ability.setElements(Water, Earth);
	return _ability;
}

Ability AbilityFactory::createGeiser()
{
	_ability.reset();
	_ability.setName("Geiser");
	_ability.setDescription("Reduce la defensa mágica del enemigo.");
	_ability.setMagicDamage(25);
	_ability.setMpCost(20);
	_ability.setElements(Water, Fire);
	return _ability;
}

Ability AbilityFactory::createPoisonGas()
{
	_ability.reset();
	_ability.setName("Poison Gas");
	_ability.setDescription("Envenena al enemigo hasta el final de la pelea.");
	_ability.setMagicDamage(10);
	_ability.setMpCost(25);
	_ability.setElements(Air, Neutral);
	return _ability;
}

Ability AbilityFactory::createMagmaWave()
{
	_ability.reset();
	_ability.setName("Magma Wave");
	_ability.setDescription("Reduce la defensa física.");
	_ability.setMagicDamage(25);
	_ability.setMpCost(20);
	_ability.setElements(Fire, Earth);
	return _ability;
}

Ability AbilityFactory::createInferno()
{
	_ability.reset();
	_ability.setName("Inferno");
	_ability.setDescription("Quema al enemigo por 3 turnos.");
	_ability.setMagicDamage(30);
	_ability.setMpCost(15);
	_ability.setElements(Fire, Neutral);
	return _ability;
}

Ability AbilityFactory::createSwirl()
{
	_ability.reset();
	_ability.setName("Swirl");
	_ability.setDescription("Reduce un 20% el siguiente ataque del enemigo.");
	_ability.setMagicDamage(25);
	_ability.setMpCost(30);
	_ability.setElements(Water, Air);
	return _ability;
}

Ability AbilityFactory::createSabakuKyu()
{
	_ability.reset();
	_ability.setName("Sabaku Kyu");
	_ability.setDescription("Inflige daño verdadero.");
	_ability.setMagicDamage(25);
	_ability.setMpCost(30);
	_ability.setElements(Air, Earth);
	return _ability;
}

AbilityFactory::~AbilityFactory()
{
	std::cout << "se eliminó abilityFactory \n \n";
}

Ability AbilityFactory::createRestore()
{
	_ability.reset();
	_ability.setName("Restore");
	_ability.setMpCost(15);
	_ability.setElements(Neutral, Neutral);
	return _ability;
}

Ability AbilityFactory::createCosmicWisdom()
{
	_ability.reset();
	_ability.setName("Cosmic Wisdom");
	_ability.setMpCost(10);
	_ability.setElements(Neutral, Neutral);
	return _ability;
}

Ability AbilityFactory::createDoton()
{
	_ability.reset();
	_ability.setName("Doton");
	_ability.setMpCost(35);
	_ability.setElements(Earth, Neutral);
	return _ability;
}
