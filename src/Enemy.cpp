#include "stdafx.h"
#include "Enemy.h"
#include "AbilityFactory.h"


Enemy::Enemy(std::string path, int rectWidth, int rectHeight, int totalFrames) {
	//TODO: Implementar dropeo de habilidades para cada enemigo   !!!!!!!!!!!! DEJAR!
	_flagDie = true;
	_frameY = 0;
	_texture.loadFromFile(path);
	_sprite.setTexture(_texture);
	_totalFrames = totalFrames;
	_rectWidth = rectWidth;
	_rectHeight = rectHeight;
	_sprite.setTextureRect({ int(_frame) * _rectWidth, 0, _rectHeight, _rectWidth });
	_sprite.setScale(2, 2);
	_sprite.setPosition(750 - _sprite.getGlobalBounds().width, 480 - _sprite.getGlobalBounds().height);
}

void Enemy::setStats(int HP, int MP, int physicalDamage, int magicDamage, int physicalDefense, int magicResist, elements elementWeak) {
	_HP = HP;
	_HPbase = _HP;
	_MP = MP;
	_MPbase = _MP;
	_physicalDamage = physicalDamage;
	_physicalDamagebase = _physicalDamage;
	_magicalDamage = magicDamage;
	_magicalDamagebase = _magicalDamage;
	_physicalDefense = physicalDefense;
	_physicalDefensebase = _physicalDefense;
	_magicResist = magicResist;
	_magicResistbase = _magicResist;
	_elementWeak = elementWeak;
}


void Enemy::update(bool dyvirIsAlive) {
	if (dyvirIsAlive) {
		if (_isAlive) {
			_frame += 0.15;
			if (_frame >= _totalFrames && _isAlive) {
				_frame = 0;
			}
			_sprite.setTextureRect({ int(_frame) * _rectWidth, 0, _rectHeight, _rectWidth });
		}
		else {
			this->Die();
		}
	}
}

void Enemy::Die() {
	if (_flagDie) {
		_frame = 0;
		_flagDie = false;
		_texture.loadFromFile("./Textures/Characters/spritesheets/EnemyDeath.png");
		_sprite.setTexture(_texture);
		_sprite.setScale(3.5, 3.5);
		_sprite.setPosition(_sprite.getPosition().x - _sprite.getGlobalBounds().width / 4, _sprite.getPosition().y - _sprite.getGlobalBounds().height / 4);
	}
	_frame += 0.5;
	if (_frame >= 8) {
		_frame = 0;
		_frameY++;
		if (_frameY >= 9) {
			_frameY = 9;
			_frame = 9;
		}
	}
	_sprite.setTextureRect({ int(_frame) * 100, int(_frameY) * 100, 100, 100 });
}