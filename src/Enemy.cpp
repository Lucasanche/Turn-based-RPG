#include "stdafx.h"
#include "Enemy.h"
#include "AbilityFactory.h"

Enemy::Enemy(std::string path, int rectWidth, int rectHeight, int totalFrames)
{
	//TODO: Implementar dropeo de habilidades para cada enemigo
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

void Enemy::setStats(int HP, int physicalDamage, elements elementWeak, int physicalDefense, int magicResist)
{
	_HP = HP;
	_physicalDamage = physicalDamage;
	_elementWeak = elementWeak;
	_physicalDefense = physicalDefense;
	_magicResist = magicResist;
}

void Enemy::setAbility1(abilityName abName)
{
	this -> setAbility(*_ability1, abName);
}

void Enemy::setAbility2(abilityName abName)
{
	this->setAbility(*_ability2, abName);
}

void Enemy::setAbility(Ability& ability, abilityName abName)
{
	AbilityFactory aux;
	switch (abName) {
	case Fireball:
		//ability = aux.createFireball();
		break;
	case Bubble:
		//ability = aux.createBubble();
		break;
	case WindBlow:
		//ability = aux.createWindBlow();
		break;
	case EarthArmor:
		ability = aux.createEarthArmor();
		break;
	case Barrier:
		break;
	case Heal:
		break;
	case Restore:
		break;
	case EarthBarrier:
		break;
	case WindBarrier:
		break;
	case WaterBarrier:
		break;
	case FireBarrier:
		break;
	case Mirror:
		break;
	case Tsunami:
		break;
	case FireTornado:
		break;
	case HotVampire:
		break;
	case Earthquake:
		break;
	case Geiser:
		break;
	case PoisonGas:
		break;
	case MagmaWave:
		break;
	case Inferno:
		break;
	case Swirl:
		break;
	case SabakuKyu:
		break;
	case Doton:
		break;
	}

}

void Enemy::update()
{
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

void Enemy::Die()
{
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