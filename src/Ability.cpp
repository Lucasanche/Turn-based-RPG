#include "stdafx.h"
#include "Ability.h"


Ability::Ability() : _negativeStates(9, false), _positiveStates(14, false) {
	_name="empty";
	_description = "empty";
	_ID = Empty;
	_magicDamage = 0;
	_mpCost = 0;
	_element1 = Neutral;
	_element2 = Neutral;
}

void Ability::setElements(elements element1, elements element2) {
	_element1 = element1;
	_element2 = element2;
}

void Ability::reset() {
	std::replace(_negativeStates.begin(), _negativeStates.end(), true, false);
	std::replace(_positiveStates.begin(), _positiveStates.end(), true, false);
	this->setID(Empty);
	this->setMagicDamage(0);
	this->setMpCost(0);
	this->setElements(Neutral, Neutral);
}


