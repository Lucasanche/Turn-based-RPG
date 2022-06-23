#pragma once
#include <SFML/Graphics.hpp>
#include "AbilityMagic.h"

class Dragon
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
	//AbilityMagic _ability1;

	////Barra de vida
	//sf::Texture _textureHP;
	//sf::Sprite _spriteHP;
	//sf::Sprite _spriteHPFill;
	//int _statusHP;
	//int _lenghtHP;

public:
	//Gets()
	int getHP() { return _HP; }
	int getBaseDamage() { return _BaseDamage; }
	bool getIsAlive() { return _isAlive; }
	void update(){}
	//Sets()
	void setHP(int hp) { _HP = hp; }
	void setIsAlive(bool isAlive) { _isAlive = isAlive; }

};

