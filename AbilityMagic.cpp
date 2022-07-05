#include "stdafx.h"
#include "AbilityMagic.h"
#include "Dragon.h"

AbilityMagic::AbilityMagic()
{
	_magicDamage = 0;
	_damageMultiplier = _vampireishon = _stun = _reducePD = _reduceMR = _reduceAtt = _burns = _poison = _truedamash = false;
}

float AbilityMagic::useAbility(Dragon &dragon)
{
	float totalDamage = _magicDamage;

	if (_damageMultiplier) {
		totalDamage *= 2;
	}
	//TODO: Implementar vampireishon
	//if (_vampireishon) {
	//}
	if (_burns) {
		dragon.setBurns();
	}
	if (_poison) {
		dragon.setPoison();
	}
	if (_stun) {
		dragon.setStun();
	}
	if (_reduceAtt) {
		dragon.setAttReduce();
	}
	if (_reducePD) {
		dragon.setPDreduce();
	}
	if (_reduceMR){
		dragon.setMRreduce();
	}
	if(_element1 == dragon.getElementWeak()) {
		totalDamage *= 1.15;
	}
	if(_element2 == dragon.getElementWeak()) {
		totalDamage *= 1.15;
	}
	if (!_truedamash) {
		totalDamage *= dragon.getMR();
	}
	dragon.damageTaken(int(totalDamage));
	return 1;
}

