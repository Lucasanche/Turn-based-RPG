#include "stdafx.h"
#include "Enemy.h"
#include "AbilityFactory.h"


Enemy::Enemy(std::string path, int rectWidth, int rectHeight, int totalFrames, float scale, int filas) {
	//TODO: Implementar dropeo de habilidades para cada enemigo   !!!!!!!!!!!! DEJAR!
	_filas = filas;
	_flagDie = true;
	_frameY = 0;
	_texture.loadFromFile(path);
	_sprite.setTexture(_texture);
	_totalFrames = totalFrames;
	_rectWidth = rectWidth;
	_rectHeight = rectHeight;
	_sprite.setTextureRect({ int(_frame) * _rectWidth, 0, _rectHeight, _rectWidth });
	_sprite.setTextureRect({ int(_frame) * 100, int(_frameY) * 100, 100, 100 });
	_sprite.setScale(scale, scale);
	_sprite.setPosition(750 - _sprite.getGlobalBounds().width, 480 - _sprite.getGlobalBounds().height);
	std::cout << _sprite.getGlobalBounds().height << std::endl;
}

void Enemy::setStats(int HP, int MP, int physicalDamage, int magicDamage, int physicalDefense, int magicResist, elements elementWeak, int XP) {
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
	_XP = XP;
}


void Enemy::Die() {
	if (_flagDie) {
		_frame = 0;
		_frameY=0;
		_flagDie = false;
		_texture.loadFromFile("./Textures/Characters/spritesheets/EnemyDeath.png");
		_sprite.setTexture(_texture);
		_sprite.setScale(4, 4);
		_sprite.setPosition(400, 150);
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

void Enemy::update(bool dyvirIsAlive, int XP) {
	if (dyvirIsAlive) {
		if (_isAlive) {
			if (_filas == 1) {
				_frame += 0.15;
				if (_frame >= _totalFrames && _isAlive) {
					_frame = 0;
				}
				_sprite.setTextureRect({ int(_frame) * _rectWidth, 0, _rectWidth, _rectHeight });
			}
			if (_filas > 1) {
				_frame += 0.15;
				if (_frame >= _totalFrames && _isAlive) {
					_frame = 0;
					std::cout << _frameY << std::endl;
					_frameY++;
					if (_frameY >= _filas) {
						_frameY =0;
						_frame = 0;
					}
				}
				_sprite.setTextureRect({ int(_frame) * _rectWidth, int(_frameY) * _rectHeight, _rectWidth, _rectHeight });
			}
			_sprite.setPosition(750 - _sprite.getGlobalBounds().width, 480 - _sprite.getGlobalBounds().height);
		}
		else {
			this->Die();
		}
	}
}

//UPDATE VIEJO
/*void Enemy::update(bool dyvirIsAlive) {
	if (dyvirIsAlive) {
		if (_isAlive) {
			_frame += 0.15;
			if (_frame >= _totalFrames && _isAlive) {
				_frame = 0;
			}
			_sprite.setPosition(750 - _sprite.getGlobalBounds().width, 480 - _sprite.getGlobalBounds().height);
			_sprite.setTextureRect({ int(_frame) * _rectWidth, 0, _rectWidth, _rectHeight });
		}
		else {
			this->Die();
		}
	}
}*/