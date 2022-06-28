#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy(std::string path, int rectWidth, int rectHeight, float frameMultiplier, int totalFrames)
{
	_texture.loadFromFile(path);
	_sprite.setTexture(_texture);
	_totalFrames = totalFrames;
	_rectWidth = rectWidth;
	_rectHeight = rectHeight;
	_totalFrames = totalFrames;
}

void Enemy::setStats(int HP, int physicalDamage, int elementWeak, int physicalDefense, int magicResist)
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
	switch (abName) {
	case Fireball:
		ability = *abilityFactory->createFireball();
		break;
	case Bubble:
		ability = *abilityFactory->createBubble();
		break;
	case WindBlow:
		ability = *abilityFactory->createWindBlow();
		break;
	case EarthArmor:
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
	case VampireFire:
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