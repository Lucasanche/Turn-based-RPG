#include "stdafx.h"
#include "Ability.h"

Ability::Ability()
{
	_name.setString("empty");
	_description.setString("empty");
	_mpCost = 0;
	_id = 0;
	_element1 = Neutral;
	_element2 = Neutral;
}

void Ability::setElements(elements element1, elements element2)
{
	_element1 = element1;
	_element2 = element2;
}

