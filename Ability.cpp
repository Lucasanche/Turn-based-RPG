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

	//AbilitySupport
	_increasePD = _increaseMR = _increaseMD = _heal = _restore = _doton = _waterResist = _airResist = _fireResist = _earthResist = false;

	//AbilityMagic
	_magicDamage = 0;
	_damageMultiplier = _vampireishon = _stun = _reducePD = _reduceMR = _reduceAtt = _burns = _poison = _truedamash = false;

}

void Ability::setElements(elements element1, elements element2)
{
	_element1 = element1;
	_element2 = element2;
}


float Ability::useAbilitySupport(Dragon& dragon)
{
	if (_increasePD) {
		dragon.setIncreasePD();
	}
	if (_increaseMR) {
		dragon.setIncreaseMR();
	}
	/*if (_increaseElementDefense) {
		dragon.setIncreaseElementDefense();
	}*/
	if (_increaseMD) {
		dragon.setIncreaseMD();
	}
	if (_heal) {
		dragon.setHeal();
	}
	if (_restore) {
		dragon.clearState(All);
	}
	if (_doton) {
		dragon.setDoton();//aja?
	}
	return 1;
}



float Ability::useAbilityMagic(Dragon& dragon)
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
	if (_reduceMR) {
		dragon.setMRreduce();
	}
	if (_element1 == dragon.getElementWeak()) {
		totalDamage *= 1.15;
	}
	if (_element2 == dragon.getElementWeak()) {
		totalDamage *= 1.15;
	}
	if (!_truedamash) {
		totalDamage *= dragon.getMR();
	}
	dragon.damageTaken(int(totalDamage));
	return 1;
}