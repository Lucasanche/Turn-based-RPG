#include "stdafx.h"
#include "Enemy.h"
#include "AbilityFactory.h"


Enemy::Enemy(sf::String path, int rectWidth, int rectHeight, int totalFrames, float scale, int filas) {
	_filas = filas;
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

	//Posición inicial de los sprites de estados
	_spriteStatesPosition={ 610, 57 };
}

void Enemy::setStats(int HP, int MP, int physicalDamage, int magicDamage, int physicalResistance, int magicResistance, elements elementWeak, elements elementResist, int XP) {
	_HP = HP;
	_HPbase = _HP;
	_MP = MP;
	_MPbase = _MP;
	_physicalDamage = physicalDamage;
	_physicalDamagebase = _physicalDamage;
	_magicDamage = magicDamage;
	_magicDamagebase = _magicDamage;
	_physicalResistance = physicalResistance;
	_physicalResistancebase = _physicalResistance;
	_magicResistance = magicResistance;
	_magicResistancebase = _magicResistance;
	_elementWeak = elementWeak;
	_elementResist = elementResist;
	_XP = XP;
}


void Enemy::Die() {
	if (_flagDie) {
		_frame = 0;
		_frameY = 0;
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
						_frameY = 0;
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

void Enemy::updateSpriteStates(sf::RenderWindow& window) {
	short icount = 0;
	short ypos = 0;
	_spriteStatesPosition = { 610, 57 };

	if (_negativeStates[stun]) {
		_spriteStates.setTextureRect({ 0, 0, 50, 50 });
		_spriteStates.setPosition(_spriteStatesPosition);
		window.draw(_spriteStates);
		icount++;
	}
	if (_negativeStates[burns]) {
		_spriteStates.setTextureRect({ 100, 0, 50, 50 });
		_spriteStates.setPosition({ _spriteStates.getPosition().x + 35, _spriteStates.getPosition().y });
		window.draw(_spriteStates);
		icount++;
	}
	if (_negativeStates[poison]) {
		_spriteStates.setPosition({ _spriteStates.getPosition().x + 35, _spriteStates.getPosition().y });
		_spriteStates.setTextureRect({ 150, 0, 50, 50 });
		window.draw(_spriteStates);
		icount++;
	}
	if (_negativeStates[reducePR]) {
		_spriteStates.setTextureRect({ 200, 0, 50, 50 });
		_spriteStates.setPosition({ _spriteStates.getPosition().x + 35, _spriteStates.getPosition().y });
		window.draw(_spriteStates);
		icount++;
	}
	if (_negativeStates[reduceMR]) {
		_spriteStates.setTextureRect({ 350, 0, 50, 50 });
		_spriteStates.setPosition({ _spriteStates.getPosition().x + 35, _spriteStates.getPosition().y });
		window.draw(_spriteStates);
		icount++;
	}
	if (_negativeStates[reducePD]) {
		ypos = (icount == 5 ? 34 : 0);
		_spriteStatesPosition.x = (icount == 5 ? _spriteStatesPosition.x : _spriteStates.getPosition().x+35);
		_spriteStates.setTextureRect({ 300, 0, 50, 50 });
		_spriteStates.setPosition({ _spriteStatesPosition.x, _spriteStates.getPosition().y + ypos });
		window.draw(_spriteStates);
		icount++;
		
	}
	if (_negativeStates[reduceMD]) {
		ypos = (icount == 5 ? 34 : 0);
		_spriteStatesPosition.x = (icount == 5 ? _spriteStatesPosition.x : _spriteStates.getPosition().x + 35);
		_spriteStates.setTextureRect({ 250, 0, 50, 50 });
		_spriteStates.setPosition({ _spriteStatesPosition.x, _spriteStates.getPosition().y + ypos });
		window.draw(_spriteStates);
		icount++;
	}
	//positive states
	if (_positiveStates[increasePR]) {
		ypos = (icount == 5 ? 34 : 0);
		_spriteStatesPosition.x = (icount == 5 ? _spriteStatesPosition.x : _spriteStates.getPosition().x + 35);
		_spriteStates.setTextureRect({ 550, 0, 50, 50 });
		_spriteStates.setPosition({ _spriteStatesPosition.x, _spriteStates.getPosition().y + ypos });
		window.draw(_spriteStates);
		icount++;
	}
	if (_positiveStates[increaseMR]) {
		ypos = (icount == 5 ? 34 : 0);
		_spriteStatesPosition.x = (icount == 5 ? _spriteStatesPosition.x : _spriteStates.getPosition().x + 35);
		//_spriteStatesPosition.x = (icount == 5 ? _spriteStatesPosition.x : _spriteStates.getPosition().x);
		_spriteStates.setTextureRect({ 500, 0, 50, 50 });
		_spriteStates.setPosition({ _spriteStatesPosition.x, _spriteStates.getPosition().y + ypos });
		window.draw(_spriteStates);
		icount++;
	}
	if (_positiveStates[increasePD]) {
		ypos = (icount == 5 ? 34 : 0);
		_spriteStatesPosition.x = (icount == 5 ? _spriteStatesPosition.x : _spriteStates.getPosition().x + 35);
		_spriteStates.setTextureRect({ 400, 0, 50, 50 });
		_spriteStates.setPosition({ _spriteStatesPosition.x, _spriteStates.getPosition().y + ypos });
		window.draw(_spriteStates);
		icount++;
	}
	if (_positiveStates[increaseMD]) {
		ypos = (icount == 5 || icount == 10 ? 34 : 0);
		_spriteStatesPosition.x = (icount == 5 || icount == 10 ? 610 : _spriteStates.getPosition().x + 35);
		_spriteStates.setTextureRect({ 450, 0, 50, 50 });
		_spriteStates.setPosition({ _spriteStatesPosition.x, _spriteStates.getPosition().y + ypos});
		window.draw(_spriteStates);
	}
}