#include "AbilityMagic.h"

AbilityMagic::AbilityMagic()
{
	_damage = 10;
	_element1 = neutral;
	_element2 = neutral;
}

float AbilityMagic::useAbility(Dragon &dragon)
{

	float totalDamage = _damage;

	if (_damageMultiplier) {
		totalDamage *= 2;
	}
	//if (_vampireishon) {
	   // Ver como PINGO lo asemo
	//}
	if (_burns) {
		dragon.setBurn();
	}
	if (_poison) {
		dragon.setPoison();
	}
	if (_stun) {
		dragon.setStun();
	}
	if (_reduceAtt) {
		dragon.setAttReduced();
	}
	if (_reducePD) {
		dragon.setPD(_PDreduced);
	}
	if (_reduceMR){
		dragon.setMR(_MRreduced);
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
}

