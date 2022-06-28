#include "stdafx.h"
#include "AbilityMagic.h"

AbilityMagic::AbilityMagic()
{
	_name.setString("empty");
	_description.setString("empty");
	_magicDamage = 0;
	_mpCost = 0;
	_id = 0;
	_element1 = neutral;
	_element2 = neutral;
	_damageMultiplier = _vampireishon = _stun = _reducePD = _reduceMR = _reduceAtt = _burns = _poison = _truedamash = false;
}

float AbilityMagic::useAbility(Dragon &dragon)
{

	float totalDamage = _magicDamage;

	if (_damageMultiplier) {
		totalDamage *= 2;
	}
	//if (_vampireishon) {
	   // Ver como PINGO lo asemo
	//}
	if (_burns) {
		//dragon.setBurn();
	}
	if (_poison) {
		dragon.setPoison();
	}
	if (_stun) {
		//dragon.setStun();
	}
	if (_reduceAtt) {
		//dragon.setAttReduced();
	}
	if (_reducePD) {
		//dragon.setPD(_PDreduced);
	}
	if (_reduceMR){
		//dragon.setMR(_MRreduced);
	}
	if(_element1 == dragon.getElementWeak()) {
		totalDamage *= 1.15;
	}
	if(_element2 == dragon.getElementWeak()) {
		totalDamage *= 1.15;
	}
	if (!_truedamash) {
		//totalDamage *= dragon.getMR();
	}
	//dragon.addStates();
	dragon.damageTaken(int(totalDamage));
}

