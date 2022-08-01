#include "stdafx.h"
#include "Dragon.h"

//TODO: setear en false los estados negativos y positivos - Lucas
Dragon::Dragon() : _negativeStates(9, true), _positiveStates(14, true) {
	_spriteStatesPosition = {};
	_elementWeak = Neutral;
	_spriteStates.setScale(0.5, 0.5);
	_elementResist = Neutral;
	_HP = _HPbase = _MP = _MPbase = _physicalDamage = _physicalDamagebase = _magicDamage = _magicDamagebase = _physicalResistance = _physicalResistancebase = _magicResistance = _magicResistancebase = _backGround = _rectWidth = _rectHeight = _totalFrames = _burnedCount = _healingCount = _stunedCount = _reducedPDCount =_reducedPRCount = _reducedMRCount = _reducedAttCount = _reducedMDCount = _increasedAttCount = _increasedPDCount = _increasedMRCount = _increasedPRCount = _increasedMDCount = _XP = _frame = 0;
	_isAlive = true;
	_flagDie = true;
	_flagWin = true;
	_physicalDamage = 10;
	_physicalDamagebase = 10;

	_textureStates.loadFromFile("./Textures/Interface/states.png");
	//Texturas de sprites de estados
	_spriteStates.setTexture(_textureStates);
}

void Dragon::setAbilityFromInventory(int abilityNumber, abilityName abName) {
	_ability[abilityNumber] = _abilityFactory.createAbility(abName);
}

void Dragon::checkHP() {
	if (_HP <= 0) {
		_isAlive = false;
	}
}

void Dragon::useAbility(Dragon& dragon, int i, int& damage) {
	if (_ability[i].getMpCost() > _MP) {
		std::cout << "Maná insuficiente \n";
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
			this->setDoton();
		}
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
		if (_ability[i].getNegativeStates(reduceMD)) {
			dragon.setReduceMD();
		}
		if (!_positiveStates[trueDamage]) {
			if (dragon.getElementResist() != Neutral) {
				if (_ability[i].getElement1() == dragon.getElementResist()) {
					totalDamage *= 0.5;
				}
				if (_ability[i].getElement2() == dragon.getElementResist()) {
					totalDamage *= 0.5;
				}
			}
			if (dragon.getElementWeak() != Neutral) {
				if (_ability[i].getElement1() == dragon.getElementWeak()) {
					totalDamage *= 1.15;
				}
				if (_ability[i].getElement2() == dragon.getElementWeak()) {
					totalDamage *= 1.15;
				}
			}
			totalDamage *= this->getMDmultiplier();
			totalDamage *= dragon.getMRmultiplier();
		}
		this->checkPositiveStates();
		dragon.damageTaken(int(totalDamage));
		damage = int(totalDamage);
	}
}

std::vector <bool> Dragon::checkNegativeStates(turns& turn) {
	//Habilidades negativas
	sf::String string;
	this->resetStats();
	if (_negativeStates[stun]) {
		if (_stunedCount != 2) { //OK
			if (turn == check) {
				std::cout << "Dyvir se encuentra stuneado" << std::endl;

				turn = enemyCheck;
			}
			else if (turn == enemyCheck) {
				std::cout << "el enemigo se encuentra stuneado" << std::endl;
				turn = start;
			}
			_stunedCount++;
		}
		else {
			_stunedCount = 0;
			_negativeStates[stun] = false;
		}
	}
	else if (turn == check) {
		turn = wait;
	}
	else if (turn == enemyCheck) {
		turn = enemyTurn;
	}
	if (_negativeStates[poison]) { //OK
		if (turn == enemyTurn) {
			std::cout << "El enemigo se encuentra envenenado" << std::endl;
			std::cout << "El enemigo recibió " << _HPbase * 0.07 << " de daño por el veneno " << std::endl;
		}
		if (turn == wait) {
			std::cout << "Estás envenenao" << std::endl;
			std::cout << "Recibiste " << _HPbase * 0.05 << " de daño por veneno" << std::endl;
		}
		_HP -= _HPbase * 0.07;
		std::cout << "despues del poison" << _HP << " por el veneno " << std::endl;

	}
	if (_negativeStates[burns]) { //OK
		if (turn == enemyTurn) {
			std::cout << "El enemigo se encuentra quemado" << std::endl;
			std::cout << "El enemigo recibió " << _HPbase * 0.10 << " por el fuego " << std::endl;
		}
		if (turn == wait) {
			std::cout << "Estás prendido fuego D: " << std::endl;
			std::cout << "Recibiste " << _HPbase * 0.10 << " de daño por fuego" << std::endl;
		}
		if (_burnedCount != 3) {
			_burnedCount++;
			_HP -= _HPbase * 0.10;
		}
		else {
			_negativeStates[burns] = false;
			_burnedCount = 0;
		}
	}
	if (_negativeStates[reducePR]) {
		_physicalResistance -= _physicalResistancebase * 0.2;
		_reducedPDCount++;
		if (_reducedPDCount == 3) {
			_reducedPDCount = 0;
			_negativeStates[reducePR] = false;
		}
	}
	if (_negativeStates[reduceMR]) {
		_magicResistance -= _magicResistancebase * 0.2;
		_reducedMRCount++;
		if (_reducedMRCount == 3) {
			_reducedMRCount = 0;
			_negativeStates[reduceMR] = false;
		}
	}
	if (_negativeStates[reduceMD]) {
		_magicDamage -= _magicDamagebase * 0.2;
		_reducedMDCount++;
		if (_reducedMDCount == 3) {
			_reducedMDCount = 0;
			_negativeStates[reduceMD] = false;
		}
	}
	if (_negativeStates[reducePD]) {
		_physicalDamage -= _physicalDamagebase * 0.2;
		_reducedAttCount++;
		if (_reducedAttCount == 3) {
			_reducedAttCount = 0;
			_negativeStates[reducePD] = false;
		}
	}
	return _negativeStates;
}

std::vector <bool>  Dragon::checkPositiveStates() {
	if (_positiveStates[increasePD]) {
		if (_negativeStates[reducePD]) { //Chequea si el daño físico está reducido y anula el estado negativo
			_negativeStates[reducePD] = false;
			_reducedPDCount = 0;
		}
		_physicalDamage = _physicalDamagebase;
		_physicalDamage *= 3;
		_positiveStates[increasePD] = false;
	}
	if (_positiveStates[increaseMR]) {
		_magicResistance += _magicResistancebase * 0.2;
		_increasedMRCount++;
		if (_increasedMRCount == 3) {
			_increasedMRCount = 0;
			_positiveStates[increaseMR] = false;
		}
	}
	if (_positiveStates[increaseMD]) {
		_magicDamage += _magicDamagebase * 0.2;
		_increasedMDCount++;
		if (_increasedMDCount == 3) {
			_increasedMDCount = 0;
			_positiveStates[increaseMD] = false;
		}
	}
	if (_positiveStates[increasePR]) {
		_physicalResistance += _physicalResistancebase * 0.2;
		_increasedPRCount++;
		if (_increasedPRCount == 3) {
			_increasedPRCount = 0;
			_positiveStates[increasePR] = false;
		}
	}
	if (_positiveStates[heal]) {
		_HP += 500;
		if (_HP > _HPbase) {
			_HP = _HPbase;
		}
		_positiveStates[heal] = false;
	}
	if (_positiveStates[restore]) {
		this->clearStates();
	}
	return _positiveStates;
}




int Dragon::doDamage(int PRenemy) {
	int finalDamage = _physicalDamage * PRenemy;
	return finalDamage;
}

float Dragon::getMRmultiplier() {
	float result = 0;
	result = 1 - (_magicResistance / (_magicResistance + 50));
	return result;
}

float Dragon::getPRmultiplier() {
	float result = 0;
	result = 1 - (_physicalResistance / (_physicalResistance + 50));
	return result;
}

float Dragon::getMDmultiplier() {
	float result = 0;
	result = 1 + (_magicDamage / (_magicDamage + 50));
	return result;
}

int Dragon::damageTaken(int damageTaken) {
	_HP -= damageTaken;
	if (_HP <= 0) {
		_HP = 0;
		_isAlive = false;
	}
	return damageTaken;
}

void Dragon::resetStats() {
	_physicalDamage = _physicalDamagebase;
	_physicalResistance = _physicalResistancebase;
	_magicDamage = _magicDamagebase;
	_magicResistance = _magicResistancebase;
}

void Dragon::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_sprite, states);
}

    
//	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1
//	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1
//	1	1	1	1	0	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1
//	1	1	1	1	0	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1
//	1	1	1	1	0	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1
//	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	0	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1
//	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	0	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1
//	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	0	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	7	0	0	0	1	1	1	1	1	1
//	1	1	1	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	0	0	1	1	1	1	1	1
//	1	1	1	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	0	0	1	1	1	1	1	1
//	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	0	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	0	0	1	1	1	1	1	1
//	1	1	1	0	0	0	0	0	0	0	1	1	1	1	1	0	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	2	0	0	0	0	0	0	1	1	1	1	1	1
//	1	1	1	0	0	0	0	0	0	0	1	1	1	1	1	2	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	0	0	1	1	1	1	1	1
//	1	1	1	0	0	0	0	0	0	0	1	1	1	1	1	0	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	0	0	1	1	1	1	1	1
//	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	3	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	0	0	1	1	1	1	1	1
//	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	0	0	1	1	1	1	1	1
//	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	0	0	1	1	1	1	1	1
//	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	0	0	1	1	1	1	1	1
//	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	0	0	1	1	1	1	1	1
//	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	0	0	1	1	1	1	1	1
//	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1
//	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1
//	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1
//	1	1	1	1	1	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1
//	1	1	1	1	1	0	0	0	0	1	1	1	1	0	0	0	0	0	0	0	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1
//	1	1	1	1	1	0	0	0	0	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1
//	1	1	1	1	1	2	0	0	0	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	1	1	1	1	1	1	0	0	6	0	0	1	1	1	1	1	1	1
//	1	1	1	1	1	0	0	0	0	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	1	1	1	1	1	1	0	0	0	0	0	1	1	1	1	1	1	1
//	1	1	1	1	1	1	4	1	1	1	1	1	1	1	0	0	0	0	1	1	1	1	1	1	1	1	1	0	0	0	0	0	1	1	1	1	1	1	2	0	0	0	0	1	1	1	1	1	1	1
//	1	1	1	1	1	1	0	1	1	1	1	1	1	1	0	0	0	0	0	0	0	0	0	0	0	1	1	0	0	0	0	0	1	1	1	1	1	1	0	0	0	0	0	1	1	1	1	1	1	1
//	1	1	1	1	1	1	0	1	1	1	1	1	1	1	0	0	0	0	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	1	1	1	1	1	1	1
//	1	1	1	1	1	1	0	1	1	1	1	1	1	1	0	0	0	0	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1
//	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1
//	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1
//	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1
//	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1
//	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	0	1	1	1	1
//	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	0	0	0	0	0	0	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1
//	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1
//	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1
//	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1
//	1	1	1	0	0	0	0	0	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1
//	1	1	1	0	0	0	0	0	0	0	0	0	1	1	1	1	1	1	0	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1
//	1	1	1	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	5	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1
//	1	1	1	0	0	0	0	0	0	0	0	0	1	1	1	1	1	1	0	0	0	0	2	1	1	1	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1
//	1	1	1	0	0	0	0	0	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1
//	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	0	0	0	0	0	0	0	0	1	1	1	1	1	1	0	1	1	1	1
//	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1
//	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1
//	1	1	1	1	1	1	1	1	1	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1
//	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	1	1	1	1	0	1	1	1	1
//	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	0	1	1	1	1	1	1	1	1	0	1	1	1	1	0	1	1	1	1
//	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	1	1	1	1	1	1	1	1	0	1	1	1	1	0	1	1	1	1
//	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	0	0	0	0	0	0	1	1	0	0	0	0	1	1	0	1	1	1	1	0	1	1	1	1
//	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	0	0	0	0	0	0	1	1	0	0	0	0	0	0	0	1	1	1	1	0	1	1	1	1
//	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	0	1	1	0	1	1	1	0	0	0	0	1	1	1	1	1	1	1	0	1	1	1	1
//	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1	1	1	1	1	1	1	0	1	1	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1
//	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	0	0	0	0	0	0	0	1	1	0	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	1	1	1	1
//	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	0	1	1	1	1
//	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1
//	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1	1

