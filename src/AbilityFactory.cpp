#include "stdafx.h"
#include "AbilityFactory.h"


AbilityFactory::AbilityFactory() {
	_ability.reset();
}

Ability	AbilityFactory::combineAbility(abilityName ab1, abilityName ab2) {

	//TODO: ver "TO DO" de createAbility en AbilityFactory

	if (ab1 == Fireball || ab2 == Fireball) {
		if (ab1 == WindBlow || ab2 == WindBlow) {
			//return this->createFireTornado();
		}
		if (ab1 == Heal || ab2 == Heal) {
			//return this->createHotVampire();
		}
		if (ab1 == Bubble || ab2 == Bubble) {
			//return this->createGeiser();
		}
		if (ab1 == EarthArmor || ab2 == EarthArmor) {
			//return this->createMagmaWave();
		}
	}
	if (ab1 == Bubble || ab2 == Bubble) {
		if (ab1 == EarthArmor || ab2 == EarthArmor) {
			//this->createEarthquake();
		}
		if (ab1 == WindBlow || ab2 == WindBlow) {
			//return this->createSwirl();
		}
	}
	if (ab1 == WindBlow || ab2 == WindBlow) {
		if (ab1 == Heal || ab2 == Heal) {
			//return this->createPoisonGas();
		}
		if (ab1 == EarthArmor || ab2 == EarthArmor) {
			//return this->createSabakuKyu();
		}
	}
	if (ab1 == Mirror || ab2 == Mirror) {
		if (ab1 == EarthBarrier || ab2 == EarthBarrier || ab1 == WaterBarrier || ab2 == WaterBarrier || ab1 == FireBarrier || ab2 == FireBarrier || ab1 == WindBarrier || ab2 == WindBarrier) {
			//return this->createRestore();
		}
	}
	if (ab1 == Barrier || ab2 == Barrier) {
		if (ab1 == EarthArmor || ab2 == EarthArmor) {
			//return this->createEarthBarrier();
		}
		if (ab1 == WindBlow || ab2 == WindBlow) {
			// return this->createEarthArmor();
		}

	}
	return _ability;
}

Ability AbilityFactory::createAbility(abilityName abName) {
	//TODO: implementar métodos correspondientes y descomentar (estos métodos también sirven para el método combineAbility) - Lucas
	switch (abName) {
	case Fireball:
		//return this->createFireball();
		break;
	case Bubble:
		//return this->createBubble();
		break;
	case WindBlow:
		//return this->createWindBlow();
		break;
	case EarthArmor:
		//return this->createEarthArmor();
		break;
	case Barrier:
		//return this->createBarrier();
		break;
	case Heal:
		//return this->createBarrier();
		break;
	case Restore:
		//return this->createRestore();
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
		//return this->createTsunami();
		break;
	case FireTornado:
		//return this->createFireTornado();
		break;
	case HotVampire:
		//return this->createHotVampire();
		break;
	case Earthquake:
		//return this->createEarthquake();
		break;
	case Geiser:
		//return this->createGeiser();
		break;
	case PoisonGas:
		//return this->createPoisonGas();
		break;
	case MagmaWave:
		//return this->createMagmaWave();
		break;
	case Inferno:
		//return this->createInferno();
		break;
	case Swirl:
		//return this->createSwirl();
		break;
	case SabakuKyu:
		//return this->createSabakuKyu();
		break;
	case Doton:
		//return this->createDoton();
		break;
	}
	return Ability();
}

Ability AbilityFactory::createTest() {
	_ability.reset();
	_ability.setName("Test");
	_ability.setReduceAtt();
	return _ability;
}

//ABILITY SUPPORT
Ability AbilityFactory::createEarthArmor() {
	_ability.reset();
	_ability.setName("EarthArmor");
	_ability.setMpCost(5);
	_ability.setElements(Earth, Neutral);
	return _ability;
}

/*Ability AbilityFactory::createBarrier()
{
	_ability = new Ability;
	_ability->setName("Barrier");
	_ability->setMpCost(5);
	_ability->setElements(Neutral, Neutral);
	return _ability;
}

Ability AbilityFactory::createHeal()
{
	_ability = new Ability;
	_ability->setName("Heal");
	_ability->setMpCost(10);
	_ability->setElements(Neutral, Neutral);
	return _ability;
}


//ABILITY MAGIC
Ability AbilityFactory::createFireball()
{
	_ability = new Ability;
	_ability->setName("Fireball");
	_ability->setMagicDamage(15);
	_ability->setMpCost(5);
	_ability->setElements(Fire, Neutral);
	return _ability;
}

Ability AbilityFactory::createBubble()
{
	_ability = new Ability;
	_ability->setName("Bubble");
	_ability->setMagicDamage(15);
	_ability->setMpCost(5);
	_ability->setElements(Water, Neutral);
	return _ability;
}

Ability* AbilityFactory::createWindBlow()
{
	_ability = new Ability;
	_ability->setName("WindBlow");
	_ability->setMagicDamage(15);
	_ability->setMpCost(5);
	_ability->setElements(Air, Neutral);
	return _ability;
}


///HABILIDADES COMBINADAS MAGIC - FALTA CRAFTEO
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

//HABILIDADES COMBINADAS SUPPORT - FALTA CRAFTEO
AbilitySupport* AbilityFactory::createRestore()
{
	_abilitySupport = new AbilitySupport;
	_abilitySupport->setName("Restore");
	_abilitySupport->setMpCost(15);
	_abilitySupport->setElements(Neutral, Neutral);
	return _abilitySupport;
}

AbilitySupport* AbilityFactory::createCosmicWisdom()
{
	_abilitySupport = new AbilitySupport;
	_abilitySupport->setName("Cosmic Wisdom");
	_abilitySupport->setMpCost(10);
	_abilitySupport->setElements(Neutral, Neutral);
	return _abilitySupport;
}

AbilitySupport* AbilityFactory::createDoton()
{
	_abilitySupport = new AbilitySupport;
	_abilitySupport->setName("Doton");
	_abilitySupport->setMpCost(35);
	_abilitySupport->setElements(Earth, Neutral);
	return _abilitySupport;
}*/
