#pragma once
#ifndef DRAGON_H
#define DRAGON_H

enum elements
{
	neutral = 0,
	fire,
	water,
	air,
	earth
};

class Dragon : public sf::Drawable
{
protected:
	bool _stuned,
		_PDreduced,
		_MRreduced,
		_burnsed,
		_poisoned,
		_attReduced;
	int _HP;
	int _BaseDamage;
	int _elementWeak;
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
	void checkStates();
	//Gets()
	int getHP() { return _HP; }
	int getBaseDamage() { return _BaseDamage; }
	bool getIsAlive() { return _isAlive; }
	int getElementWeak() { return int(_elementWeak); }


	//Sets()
	void setHP(int hp) { _HP = hp; }
	void setIsAlive(bool isAlive) { _isAlive = isAlive; }
	int getBack() { return _backGround; }
	virtual void Die() = 0;
	virtual void update() = 0;
	virtual int doDamage() = 0;
	virtual void damageTaken(int) = 0;
	void setPoison();
};

#endif