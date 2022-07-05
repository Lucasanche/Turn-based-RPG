#include "stdafx.h"



Dragon::Dragon()
{	_HP = _HPMax;
	_isAlive = true;

	_stuned = _PDreduced = _MRreduced = _burnsed = _poisoned = _attReduced = false;
	_burnedCount = _healingCount = _stunedCount = _reducedPDCount = _reducedMRCount = _reducedAttCount = 0;

	_PDincreased = _MRincreased  = _MDincreased = _healed = _restored = _dotoned = false;
}

void Dragon::checkStates(bool &turn)
{
	//ABILITY MAGIC
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
	
	//ABILITY SUPPORT
	if (_PDincreased)
	{
		_physicalDamage *= 1.2;
	}
	if (_MRincreased)
	{
		_magicResist *= 1.2;
	}
	if (_MDincreased)
	{
		_magicalDamage *= 1.2;
	}
	if (_healed)
	{
		_HP += 20;
	}
	if (_restored) {} //ESTA NO HACE FALTA PORQUE LA HACE EN ABILITYSUPPORT
	if (_dotoned) //CHEQUEAR
	{

	}

}

void Dragon::clearState(alteredState state)
{
	switch (state) {
	case All:
		_stuned = _PDreduced = _MRreduced = _burnsed = _poisoned = _attReduced = false;
		_burnedCount = _stunedCount = _reducedPDCount = _reducedMRCount = _reducedAttCount = 0;
		break;
	case Poison:
		_poisoned = false;
		break;
	case Burns:
		_burnsed = false;
		break;
	case AttReduce:
		_attReduced = false;
		break;
	case MRreduce:
		_MRreduced = false;
		break;
	case PDreduce:
		_PDreduced = false;
		break;
	case Stun:
		_stuned = false;
		break;
	}
}

int Dragon::doDamage(int PDenemy) {
	int finalDamage = _physicalDamage * PDenemy;
	return finalDamage;
}

float Dragon::getMR()
{
	float result = 0;
	result = 1 - (_magicResist / (_magicResist + 50));
	return result;
}

float Dragon::getPD()
{
	float resultado = 0;
	resultado = 1 - (_physicalDefense / (_physicalDefense + 50));
	return resultado;
}

void Dragon::damageTaken(int damageTaken) {
	_HP -= damageTaken;
	if (_HP <= 0) {
		_HP = 0;
		_isAlive = false;
	}
}

void Dragon::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}