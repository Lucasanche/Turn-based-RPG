#include "stdafx.h"
#include "Dragon.h"

Dragon::Dragon()
{
	_burnedCount = 0;
	_stunedCount = 0;
	_stuned = _PDreduced = _MRreduced = _burnsed = _poisoned = _attReduced = false;
	_burnedCount = _stunedCount = _reducedPDCount = _reducedMRCount = _reducedAttCount = 0;
	_isAlive = true;
	_HP = _HPMax;
}

void Dragon::checkStates(bool &turn)
{
	if (_stuned) {
		if (_stunedCount != 2) {
			turn = !turn;
		}
		else {
			_stunedCount = 0;
			_stuned = false;
		}
	}
	if (_poisoned) {
		_HP -= _HPMax * 0.07;
	}
	if (_burnsed) {
		if (_burnedCount != 3) {
			_burnedCount++;
			_HP -= _HPMax * 0.15;
		}
		else {
			_burnsed = false;
			_burnedCount = 0;
		}
	}
	if (_PDreduced) {
		if (_reducedPDCount == 0) {
			_physicalDefense *= 0.8;
		}
		_reducedPDCount++;
		if (_reducedPDCount == 3) {
			_reducedPDCount = 0;
			_PDreduced = false;
		}
	}
	if (_MRreduced) {
		if (_reducedMRCount == 0) {
			_magicResist *= 0.8;
		}
		_reducedMRCount++;
		if (_reducedMRCount == 3) {
			_reducedMRCount = 0;
			_MRreduced = false;
		}
	}
	if (_attReduced) {
		_physicalDamage *= 0.8;
	}
}

void Dragon::setPoison()
{
	_poisoned = true;
}
