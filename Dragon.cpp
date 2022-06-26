#include "stdafx.h"
#include "Dragon.h"

void Dragon::checkStates()
{
	
	if (_stuned) {

	_stuned = false;
	}
	if (_poisoned) {

	}
	if (_burnsed) {

	}
	if (_PDreduced) {
		
	}
	if (_MRreduced) {

	}
	if (_attReduced) {

	}
}

void Dragon::setPoison()
{
	_poison = true;
}
