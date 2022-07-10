#include "stdafx.h"
#include "Dragon.h"


Dragon::Dragon() : _negativeStates(6, false), _positiveStates(12, false) {
	_HP = _HPMax;
	_isAlive = true;
	_burnedCount = _healingCount = _stunedCount = _reducedPDCount = _reducedMRCount = _reducedAttCount = 0;
}

void Dragon::useAbility(Dragon& dragon, int i) {
	if (_ability[i].getMpCost() > _MP) {
		std::cout << "Maná insuficiente" << std::endl;
	}
	else {
		_MP -= _ability[i].getMpCost();
		if (_ability[i].getPositiveStates(increasePD)) {
			this->setIncreasePD();
		}
		if (_ability[i].getPositiveStates(increaseMR)) {
			this->setIncreaseMR();
		}
		if (_ability[i].getPositiveStates(increaseMD)) {
			this->setIncreaseMD();
		}
		if (_ability[i].getPositiveStates(heal)) {
			this->setHeal();
		}
		if (_ability[i].getPositiveStates(restore)) {
			this->clearStates();
		}
		if (_ability[i].getPositiveStates(doton)) {
			this->setDoton();//aja?
		}
		/*if (_increaseElementDefense) {
			dragon.setIncreaseElementDefense();
		}*/
		float totalDamage = _ability[i].getMagicDamage();
		if (_positiveStates[damageMultiplier]) {
			totalDamage *= 2;
		}
		//TODO: Implementar vampireishon
		//if (_vampireishon) {
		//}
		if (_ability[i].getNegativeStates(stun)) {
			dragon.setStun();
		}
		if (_ability[i].getNegativeStates(burns)) {
			dragon.setBurns();
		}
		if (_ability[i].getNegativeStates(poison)) {
			dragon.setPoison();
		}
		if (_ability[i].getNegativeStates(reducePD)) {
			dragon.setReducePD();
		}
		if (_ability[i].getNegativeStates(reduceMR)) {
			dragon.setReduceMR();
		}
		if (_ability[i].getNegativeStates(reduceAtt)) {
			dragon.setReduceAtt();
		}
		if (_ability[i].getElement1() == dragon.getElementWeak()) {
			totalDamage *= 1.15;
		}
		if (_ability[i].getElement2() == dragon.getElementWeak()) {
			totalDamage *= 1.15;
		}
		if (!_positiveStates[trueDamage]) {
			totalDamage *= dragon.getMR();
		}
		dragon.damageTaken(int(totalDamage));
	}
}

void Dragon::checkStates(turns& turn) {
	//TODO: Ver como hacer para que cuando termine la pelea los estados negativos vuelvan a los valores originales
	//Habilidades negativas
	if (_negativeStates[stun]) {
		if (_stunedCount != 2) {
			if (turn == wait) {
				std::cout << "Dyvir se encuentra stuneado" << std::endl;
				turn = enemyWait;
			}
			else if (turn == enemyWait) {
				std::cout << "el enemigo se encuentra stuneado" << std::endl;
				turn = wait;
			}
			_stunedCount++;
		}
		else {
			_stunedCount = 0;
			_negativeStates[stun] = false;
		}
	}
	if (_negativeStates[poison]) {
		_HP -= _HPMax * 0.07;
	}
	if (_negativeStates[burns]) {
		if (_burnedCount != 3) {
			_burnedCount++;
			_HP -= _HPMax * 0.15;
		}
		else {
			_negativeStates[burns] = false;
			_burnedCount = 0;
		}
	}
	if (_negativeStates[reducePD]) {
		if (_reducedPDCount == 0) {
			_physicalDefense *= 0.8;
		}
		_reducedPDCount++;
		if (_reducedPDCount == 3) {
			_reducedPDCount = 0;
			_negativeStates[reducePD] = false;
		}
	}
	if (_negativeStates[reduceMR]) {
		if (_reducedMRCount == 0) {
			_magicResist *= 0.8;
		}
		_reducedMRCount++;
		if (_reducedMRCount == 3) {
			_reducedMRCount = 0;
			_negativeStates[reduceMR] = false;
		}
	}
	if (_negativeStates[reduceAtt]) {
		_physicalDamage *= 0.8;
	}
	//Habilidades positivas
	if (_positiveStates[increasePD]) {
		_physicalDamage *= 1.2;
	}
	if (_positiveStates[increaseMR]) {
		_magicResist *= 1.2;
	}
	if (_positiveStates[increaseMD]) {
		_magicalDamage *= 1.2;
	}
	if (_positiveStates[heal]) {
		_HP += 20;
	}
	if (_positiveStates[restore]) {
		this->clearStates();
	}
	if (_positiveStates[doton]) {//CHEQUEAR
		int  i;
	}
}

int Dragon::doDamage(int PDenemy) {
	int finalDamage = _physicalDamage * PDenemy;
	return finalDamage;
}

float Dragon::getMR() {
	float result = 0;
	result = 1 - (_magicResist / (_magicResist + 50));
	return result;
}

float Dragon::getPD() {
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

void Dragon::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_sprite, states);
}