#include "stdafx.h"
#include "AbilityFactory.h"
#include "AbilityMagic.h"

//void AbilityFactory::createFireball()
//{
//	_ability = new AbilityMagic();
//	_ability->setDamage(50);
//
//}

Ability* AbilityFactory::createFireball()
{
	_ability = new AbilityMagic;
	return _ability;
}

Ability* AbilityFactory::createBubble()
{
	return _ability;
}

Ability* AbilityFactory::createWindBlow()
{
	return _ability;
}



