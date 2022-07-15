#include "stdafx.h"
#include "DyvirFight.h"
#include "AbilityFactory.h" //TODO: ver como implementar AbilityFactory dentro del menuMap - Giuli

DyvirFight::DyvirFight() : _abilityEquipment(0) {
	AbilityFactory _factory;
	_ability[0] = _factory.createTest();
	_ability[1] = _factory.createTest();
	_ability[2] = _factory.createTest();

	Ability _ability3[4];
	_ability3[0] = _factory.createTest();
	_ability3[1] = _factory.createTest();
	_ability3[2] = _factory.createEarthArmor();
	_ability3[3] = _factory.createEarthArmor();

	_abilityEquipment.push_back(_ability3[0]);
	_abilityEquipment.push_back(_ability3[1]);
	_abilityEquipment.push_back(_ability3[2]);
	_abilityEquipment.push_back(_ability3[3]);



	//TODO: Implementar leveo, subida de stats, etc.  DEJAR!!!!!!!!!!!!!!!!!!!!!!!!!
	_HPbase = 100;
	_HP = _HPbase;
	_MPbase = 100;
	_physicalDamagebase = 30;
	_physicalDamage = _physicalDamagebase;
	_physicalDefensebase = 10;
	_magicalDamagebase = 10;
	_magicResistbase = 10;
	this->setFightSprite();
	_isAlive = true;
	_wins = 0;

	//Variables útiles para los sprites
	_flagDie = true; // Usar para reproducir la animación de muerte
	_flagWin = true;
	_frame = 0;
}

void DyvirFight::update(bool enemyIsAlive) {
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
		this->Win();
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

void DyvirFight::Win() {
	if (_flagWin) {
		_frame = 0;
		_texture.loadFromFile("./Textures/Characters/spritesheets/DyvirWin 110x200.png");
		_sprite.setTexture(_texture);
		_sprite.setScale(0.5, 0.5);
		_flagWin = false;
	}
	_frame += 0.15;
	if (_frame >= 5) {
		_frame = 0;
	}
	//TODO: arreglar el sprite de victoria de Dyvir - Juli
	_sprite.setTextureRect({ int(_frame) * 170, 0, 170, 110 });
}
void DyvirFight::restoreLife() {
	_HP = _HPbase;
	_MP = _MPbase;
}

std::string DyvirFight::getAbilityInvName(int i) {
	if (i >= _abilityEquipment.size()) {
		return "Empty";
	}
	else return _abilityEquipment[i].getName();
}

void DyvirFight::setFightSprite() {
	_texture.loadFromFile("./Textures/Characters/spritesheets/DyvirFight.png");
	_sprite.setTexture(_texture);
	_sprite.setTextureRect({ 0,0,260,230 });
	_sprite.setScale(0.5, 0.5);
	_sprite.setPosition(85, 480 - _sprite.getGlobalBounds().height);
}
