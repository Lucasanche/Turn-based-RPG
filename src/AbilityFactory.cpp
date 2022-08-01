#include "stdafx.h"
#include "AbilityFactory.h"


AbilityFactory::AbilityFactory() {
	_ability.reset();
}

abilityName	AbilityFactory::craftAbility(sf::String ab1, sf::String ab2) {
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
			return Earthquake;
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
			return EarthBarrier;
		}
		if (ab1 == "WindBlow" || ab2 == "WindBlow") {
			 return EarthArmor;
		}
	}
	else { return CraftError; }
}



Ability AbilityFactory::createAbility(abilityName abName) {
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
		return this->createEarthquake();
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

Ability AbilityFactory::createEarthArmor() {
	_ability.reset();
	_ability.setName("Earth Armor");
	_ability.setDescription("Aumenta la defensa fisica");
	_ability.setMpCost(5);
	_ability.setIncreasePD();
	_ability.setElements(Earth, Neutral);
	return _ability;
}



Ability AbilityFactory::createBarrier()
{
	_ability.reset();
	_ability.setName("Barrier");
	_ability.setDescription("Aumenta la defensa magica");
	_ability.setMpCost(5);
	_ability.setIncreaseMD();
	_ability.setElements(Neutral, Neutral);
	return _ability;
}

Ability AbilityFactory::createHeal()
{
	_ability.reset();
	_ability.setName("Heal");
	_ability.setDescription("Cura una proporcion de HP");
	_ability.setMpCost(5);
	_ability.setHeal();
	_ability.setElements(Neutral, Neutral);
	return _ability;
}


Ability AbilityFactory::createFireball()
{
	_ability.reset();
	_ability.setName("Fireball");
	_ability.setID(Fireball);
	_ability.setDescription("Lanza una bola de fuego\n");
	_ability.setMagicDamage(200);
	_ability.setMpCost(5);
	_ability.setElements(Fire, Neutral);
	return _ability;
}

Ability AbilityFactory::createBubble()
{
	_ability.reset();
	_ability.setName("Bubble");
	_ability.setID(Bubble);
	_ability.setDescription("Escupe burbujas de agua\n");
	_ability.setMagicDamage(200);
	_ability.setMpCost(5);
	_ability.setElements(Water, Neutral);
	return _ability;
}

Ability AbilityFactory::createWindBlow()
{
	_ability.reset();
	_ability.setName("WindBlow");
	_ability.setID(WindBlow);
	_ability.setDescription("Lanza una rafaga de viento cortante\n");
	_ability.setMagicDamage(200);
	_ability.setMpCost(5);
	_ability.setElements(Air, Neutral);
	return _ability;
}

Ability AbilityFactory::createTsunami()
{
	_ability.reset();
	_ability.setName("Tsunami");
	_ability.setDescription("Crea una ola gigante que reduce el MD del enemigo");
	_ability.setID(Tsunami);
	_ability.setMagicDamage(800);
	_ability.setReduceMD();
	_ability.setMpCost(20);
	_ability.setElements(Water, Neutral);
	return _ability;
}

Ability AbilityFactory::createFireTornado()
{
	_ability.reset();
	_ability.setName("Fire Tornado");
	_ability.setDescription("Crea un tornado de fuego");
	_ability.setID(FireTornado);
	_ability.setMagicDamage(800);
	_ability.setMpCost(20);
	_ability.setElements(Fire, Air);
	return _ability;
}



Ability AbilityFactory::createEarthquake()
{
	_ability.reset();
	_ability.setName("Earthquake");
	_ability.setDescription("Genera un terremoto que puede stunear al enemigo");
	_ability.setID(Earthquake);
	_ability.setMagicDamage(800);
	_ability.setMpCost(20);
	_ability.setStun();
	_ability.setElements(Water, Earth);
	return _ability;
}

Ability AbilityFactory::createGeiser()
{
	_ability.reset();
	_ability.setName("Geiser");
	_ability.setDescription("Dispara un chorro de vapor caliente a gran velocidad que reduce el MR del enemigo");
	_ability.setID(Geiser);
	_ability.setMagicDamage(800);
	_ability.setMpCost(20);
	_ability.setElements(Water, Fire);
	return _ability;
}

Ability AbilityFactory::createPoisonGas()
{
	_ability.reset();
	_ability.setName("Poison Gas");
	_ability.setDescription("Crea una nube de gas que envenena al enemigo");
	_ability.setID(PoisonGas);
	_ability.setMagicDamage(400);
	_ability.setMpCost(25);
	_ability.setPoison();
	_ability.setElements(Air, Neutral);
	return _ability;
}

Ability AbilityFactory::createMagmaWave()
{
	_ability.reset();
	_ability.setName("Magma Wave");
	_ability.setDescription("Invoca una ola de magma que reduce el PD del enemigo");
	_ability.setID(MagmaWave);
	_ability.setMagicDamage(800);
	_ability.setMpCost(20);
	_ability.setReducePD();
	_ability.setElements(Fire, Earth);
	return _ability;
}

Ability AbilityFactory::createInferno()
{
	_ability.reset();
	_ability.setName("Inferno");
	_ability.setDescription("Ataca con llamas infernales que se mantienen encendidas durante 3 turnos");
	_ability.setID(Inferno);
	_ability.setMagicDamage(1200);
	_ability.setMpCost(30);
	_ability.setBurns();
	_ability.setElements(Fire, Neutral);
	return _ability;
}

Ability AbilityFactory::createSwirl()
{
	_ability.reset();
	_ability.setName("Swirl");
	_ability.setDescription("Crea un remolino de agua que reduce el ataque del enemigo");
	_ability.setID(Swirl);
	_ability.setMagicDamage(1000);
	_ability.setMpCost(30);
	_ability.setReduceAtt();
	_ability.setElements(Water, Air);
	return _ability;
}

Ability AbilityFactory::createSabakuKyu()
{
	_ability.reset();
	_ability.setName("Sabaku Kyu");
	_ability.setDescription("Encierra a un enemigo en una tumba de arena que ignora cualquier defensa");
	_ability.setID(SabakuKyu);
	_ability.setMagicDamage(1000);
	_ability.setMpCost(30);
	_ability.setTrueDamage();
	_ability.setElements(Air, Earth);
	return _ability;
}

Ability AbilityFactory::createRestore()
{
	_ability.reset();
	_ability.setName("Restore");
	_ability.setDescription("Cura los estados negativos");
	_ability.setID(Restore);
	_ability.setMpCost(15);
	_ability.setRestore();
	_ability.setElements(Neutral, Neutral);
	return _ability;
}

Ability AbilityFactory::createCosmicWisdom()
{
	_ability.reset();
	_ability.setName("Cosmic Wisdom");
	_ability.setDescription("Incrementa el MD");
	_ability.setID(CosmicWisdom);
	_ability.setMpCost(10);
	_ability.getIncreaseMD();
	_ability.setElements(Neutral, Neutral);
	return _ability;
}

Ability AbilityFactory::createDoton()
{
	_ability.reset();
	_ability.setName("Doton");
	_ability.setID(Doton);
	_ability.setMpCost(35);
	_ability.setIncreaseMR();
	_ability.setIncreasePR();
	_ability.setElements(Earth, Neutral);
	return _ability;
}
//TODO: implementar estas habilidades:

//Ability AbilityFactory::createElementalBarrier(){
//_ability.setMpCost(10);
//}

Ability AbilityFactory::createHotVampire() {
	_ability.reset();
	_ability.setName("Hot Vampire");
	_ability.setDescription("Cura el 30% del daño infligido.");
	_ability.setID(HotVampire);
	_ability.setMagicDamage(800);
	//TODO: ver implementación de vampireishon
	_ability.setVampireishon();
	_ability.setMpCost(25);
	_ability.setElements(Fire, Neutral);
	return _ability;
}

//Ability AbilityFactory::createMirror() {
//	_ability.reset();
//	_ability.setName("Mirror");
// _ability.setID(Mirror);
//	_ability.setDescription("Devuelve una habilidad o ataque del enemigo");
//	_ability.setMpCost(20);
//	_ability.setMirror();
//	return _ability;
//}

AbilityFactory::~AbilityFactory() {
	std::cout << "se eliminó abilityFactory \n \n";
}