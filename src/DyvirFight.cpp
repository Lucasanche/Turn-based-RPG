#include "stdafx.h"
#include "DyvirFight.h"
#include "AbilityFactory.h"

DyvirFight::DyvirFight() : _abilityInventory(3) {
	//TODO: Implementar leveo, subida de stats, etc.  DEJAR!!!!!!!!!!!!!!!!!!!!!!!!!
	_abilityInventory[0] = _abilityFactory.createFireball();
	_abilityInventory[1] = _abilityFactory.createWindBlow();
	_abilityInventory[2] = _abilityFactory.createHotVampire();
	
	_level = 1;
	_XP = 0;
	_HPbase = 1000;
	_MPbase = 500; 
	_physicalDamagebase = 150;
	_magicalDamagebase = 50; 
	_physicalDefensebase = 50;
	_magicResistbase = 50;
	
	_HP = _HPbase;
	_MP = _MPbase;
	_physicalDamage = _physicalDamagebase;
	_magicalDamage = _magicalDamagebase;
	_physicalDefense = _physicalDefensebase;
	_magicResist = _magicResistbase;

	this->setFightSprite();
	_isAlive = true;
	_wins = 0;

	//Variables útiles para los sprites
	_flagDie = true; // Usar para reproducir la animación de muerte
	_flagWin = true;
	_frame = 0;
}

void DyvirFight::update(bool enemyIsAlive, int enemyXP) {
	if (enemyIsAlive) {
		if (_isAlive) {
			_frame += 0.15;
			if (_frame >= 8 && _isAlive) {
				_frame = 0;
			}
			_sprite.setTextureRect({ int(_frame) * 260, 0, 260, 230 });
		}
		else {
			this->Die();
		}
	}
	else {
		this->Win(enemyXP);
		this->resetStats();
	}
}

void DyvirFight::Die() {
	if (_flagDie) {
		_frame = 0;
		_texture.loadFromFile("./Textures/Characters/spritesheets/DyvirDead.png");
		_sprite.setTexture(_texture);
		_sprite.setScale(1, 1);
		_flagDie = false;
	}
	_frame += 0.15;
	if (_frame >= 9) {
		_frame = 9;
	}
	_sprite.setTextureRect({ int(_frame) * 170, 0, 170, 110 });
	_sprite.setPosition(85, 480 - _sprite.getGlobalBounds().height);
}

void DyvirFight::Win(int enemyXP) {
	this->increaseXP(enemyXP);
	if (_flagWin) {
		_frame = 0;
		_texture.loadFromFile("./Textures/Characters/spritesheets/DyvirWin 110x200.png");
		_sprite.setTexture(_texture);
		_sprite.setScale(1, 1);
		_flagWin = false;
	}
	_frame += 0.15;
	if (_frame >= 6) {
		_frame = 0;
	}
	_sprite.setTextureRect({ int(_frame) * 110, 0, 110, 200 });
	_sprite.setPosition(85, 480 - _sprite.getGlobalBounds().height);
}

std::string DyvirFight::increaseXP(int XP) {
	_XP += XP;
	if (_level == 20) {
		return "Nivel máximo alcanzado";
	}
	if (XP >= _XPrequired[_level-1]) {
		_level++;
		this->levelUp(_level);
		return "Ganaste " + std::to_string(XP) + " puntos de experiencia. Subiste a nivel " + std::to_string(_level);
	}
	else {
		return "Ganaste " + std::to_string(XP) + " puntos de experiencia.";
	}
}

void DyvirFight::levelUp(int level)
{
	switch (level) {
	//BASE -> setStats(1000, 500, 150, 50, 50, 50, _XP);
	//Enemies -> _enemy->setStats(700, 200, 35, 35, 30, 30, Air, 100);
	case 2: setStats(1200, 600, 50, 50, 25, 25, _XP);
		break;
		//Boss 1|lvl 3 -> _enemy->setStats(1000, 500, 100, 100, 50, 50, Fire, 100);
	case 3: setStats(1500, 800, 100, 50, 50, 50, _XP);
		break;
		//Enemies -> _enemy->setStats(1100, 600, 80, 80, 50, 50, Earth, 150);
	case 4: setStats(1800, 1000, 100, 50, 50, 50, _XP);
		break;
	case 5: setStats(1800, 1000, 100, 50, 50, 50, _XP);
		break;
		//Boss 2|lvl 6 -> _enemy->setStats(1500, 700, 150, 150, 120, 100, Air, 300);
	case 6: setStats(1800, 1000, 150, 150, 120, 100, _XP);
		break;
	case 7:
		break;
	case 8:
		break;
	case 9:
		break;
	case 10:
		break;
	case 11:
		break;
	case 12:
		break;
	case 13:
		break;
	case 14:
		break;
	case 15:
		break;
	case 16:
		break;
	case 17:
		break;
	case 18:
		break;
	case 19:
		break;
	case 20:
		break;
	}
}

void DyvirFight::setStats(int HP, int MP, int physicalDamage, int magicDamage, int physicalDefense, int magicResist, int XP) {
	_HPbase = HP;
	_MPbase = MP;
	_physicalDamagebase = physicalDamage;
	_magicalDamagebase = magicDamage;
	_physicalDefensebase = _physicalDefense;
	_magicResistbase = _magicResist;
}

void DyvirFight::restoreLife() {
	_HP = _HPbase;
	_MP = _MPbase;
}


std::string DyvirFight::setAbilityEquipedElement(int i, int ability) {
	{
		if (ability < _abilityInventory.size()) {
			_ability[i] = _abilityInventory[ability];
			return _ability[i].getName();
		}
		else return _ability[i].getName();
	}
}

void DyvirFight::setAbilityEquiped(Ability ability[]) {
	for (int i = 0; i < 3; i++) {
		_ability[i] = ability[i];
	}
}

std::string DyvirFight::getInventoryElementName(int i) {
	if (i >= _abilityInventory.size()) {
		return "Empty";
	}
	else return _abilityInventory[i].getName();
}

bool DyvirFight::craftAbility(std::string ab1, std::string ab2, int indexAb1, int indexAb2) {
	if (_abilityFactory.craftAbility(ab1, ab2) != CraftError) {
		if (indexAb1 < indexAb2) {
			_abilityInventory.erase(_abilityInventory.begin() + indexAb1);
			_abilityInventory.erase(_abilityInventory.begin() + indexAb2 - 1);
		}
		else {
			_abilityInventory.erase(_abilityInventory.begin() + indexAb2);
			_abilityInventory.erase(_abilityInventory.begin() + indexAb1 - 1);
		}
		_abilityInventory.push_back(_abilityFactory.createAbility(_abilityFactory.craftAbility(ab1, ab2)));
		return true;
	}
	else{ return false; }
}

void DyvirFight::setFightSprite() {
	_texture.loadFromFile("./Textures/Characters/spritesheets/DyvirFight.png");
	_sprite.setTexture(_texture);
	_sprite.setTextureRect({ 0,0,260,230 });
	_sprite.setScale(0.5, 0.5);
	_sprite.setPosition(85, 480 - _sprite.getGlobalBounds().height);
	_flagWin = true;
}
