#include "stdafx.h"
#include "AbilityFactory.h"
#include "AbilityMagic.h"

Ability* AbilityFactory::createFireball()
{
	_ability = new AbilityMagic;
	_ability->setMagicDamage(15);
	_ability->setMpCost(5);
	_ability->setElements(Fire, Neutral);
	return _ability;
}

Ability* AbilityFactory::createBubble()
{
	_ability = new AbilityMagic;
	_ability->setMagicDamage(15);
	_ability->setMpCost(5);
	_ability->setElements(Water, Neutral);
	return _ability;
}

Ability* AbilityFactory::createWindBlow()
{
	_ability = new AbilityMagic;
	_ability->setMagicDamage(15);
	_ability->setMpCost(5);
	_ability->setElements(Air, Neutral);
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

