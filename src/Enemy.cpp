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

	///States sprites
	_textureStates.loadFromFile("./Textures/Interface/states.png");

	_spriteStunEnemy.setTexture(_textureStates);
	_spriteStunEnemy.setScale(0.6, 0.6);
	_spriteStunEnemy.setPosition(610, 68);
	_spriteStunEnemy.setTextureRect(sf::IntRect(0, 0, 50, 50));

	_spriteBurnsEnemy.setTexture(_textureStates);
	_spriteBurnsEnemy.setScale(0.6, 0.6);
	_spriteBurnsEnemy.setPosition(650, 75);
	_spriteBurnsEnemy.setTextureRect(sf::IntRect(100, 0, 50, 50));

	_spritePoisonedEnemy.setTexture(_textureStates);
	_spritePoisonedEnemy.setScale(0.6, 0.6);
	_spritePoisonedEnemy.setPosition(685, 75);
	_spritePoisonedEnemy.setTextureRect(sf::IntRect(150, 0, 50, 50));

	_spriteMRincreaseEnemy.setTexture(_textureStates);
	_spriteMRincreaseEnemy.setScale(0.6, 0.6);
	_spriteMRincreaseEnemy.setPosition(720, 75);
	_spriteMRincreaseEnemy.setTextureRect(sf::IntRect(500, 0, 50, 50));

	_spriteMDincreaseEnemy.setTexture(_textureStates);
	_spriteMDincreaseEnemy.setScale(0.6, 0.6);
	_spriteMDincreaseEnemy.setPosition(755, 75);
	_spriteMDincreaseEnemy.setTextureRect(sf::IntRect(450, 0, 50, 50));

	_spritePDincreaseEnemy.setTexture(_textureStates);
	_spritePDincreaseEnemy.setScale(0.6, 0.6);
	_spritePDincreaseEnemy.setPosition(615, 95);
	_spritePDincreaseEnemy.setTextureRect(sf::IntRect(400, 0, 50, 50));

	_spritePRincreaseEnemy.setTexture(_textureStates);
	_spritePRincreaseEnemy.setScale(0.6, 0.6);
	_spritePRincreaseEnemy.setPosition(650, 110);
	_spritePRincreaseEnemy.setTextureRect(sf::IntRect(550, 0, 50, 50));

	_spritePDdecreaseEnemy.setTexture(_textureStates);
	_spritePDdecreaseEnemy.setScale(0.6, 0.6);
	_spritePDdecreaseEnemy.setPosition(685, 110);
	_spritePDdecreaseEnemy.setTextureRect(sf::IntRect(300, 0, 50, 50));

	_spriteMDdecreaseEnemy.setTexture(_textureStates);
	_spriteMDdecreaseEnemy.setScale(0.6, 0.6);
	_spriteMDdecreaseEnemy.setPosition(720, 110);
	_spriteMDdecreaseEnemy.setTextureRect(sf::IntRect(250, 0, 50, 50));

	_spritePRdecreaseEnemy.setTexture(_textureStates);
	_spritePRdecreaseEnemy.setScale(0.6, 0.6);
	_spritePRdecreaseEnemy.setPosition(755, 110);
	_spritePRdecreaseEnemy.setTextureRect(sf::IntRect(200, 0, 50, 50));

	_spriteMRdecreaseEnemy.setTexture(_textureStates);
	_spriteMRdecreaseEnemy.setScale(0.6, 0.6);
	_spriteMRdecreaseEnemy.setPosition(615, 125);
	_spriteMRdecreaseEnemy.setTextureRect(sf::IntRect(350, 0, 50, 50));

	_spriteDamageMultiplierEnemy.setTexture(_textureStates);
	_spriteDamageMultiplierEnemy.setScale(0.6, 0.6);
	_spriteDamageMultiplierEnemy.setPosition(615, 510);
	_spriteDamageMultiplierEnemy.setTextureRect(sf::IntRect(600, 0, 50, 50));

	_spriteBleedingEnemy.setTexture(_textureStates);
	_spriteBleedingEnemy.setScale(0.5, 0.5);
	_spriteBleedingEnemy.setPosition(650, 510);
	_spriteBleedingEnemy.setTextureRect(sf::IntRect(50, 0, 50, 50));
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