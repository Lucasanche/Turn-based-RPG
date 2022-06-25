#pragma once
#ifndef DRAGON_H
#define DRAGON_H
#include "AbilityMagic.h"

class Dragon : public sf::Drawable
{
protected:
	int _HP;
	int _BaseDamage;
	/*int BaseDefense;
	int ElectricDamage;
	int FireDamage;*/
	float _frame;
	sf::Texture _texture;
	sf::Sprite _sprite;
	bool _isAlive;
	bool _flagDie;
	int _backGround;

public:
	//Gets()
	int getHP() { return _HP; }
	int getBaseDamage() { return _BaseDamage; }
	bool getIsAlive() { return _isAlive; }
	//Sets()
	void setHP(int hp) { _HP = hp; }
	void setIsAlive(bool isAlive) { _isAlive = isAlive; }
	int getBack() { return _backGround; }
	virtual void Die() = 0;
	virtual void update() = 0;
	virtual int doDamage() = 0;
	virtual void damageTaken(int) = 0;
};

#endif