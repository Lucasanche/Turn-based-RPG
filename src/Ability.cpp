#include "stdafx.h"
#include "Ability.h"


Ability::Ability() : _negativeStates(7, false), _positiveStates(12, false) {
	_name.setString("empty");
	_description.setString("empty");
	_mpCost = 0;
	_id = 0;
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
}
