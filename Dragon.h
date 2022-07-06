#pragma once
#ifndef DRAGON_H
#define DRAGON_H
#include "Ability.h"

class Dragon : public sf::Drawable
{
protected:
	///AbilityMagic resources
	bool negativeStates[6];
	bool positiveStates[10];

	bool _stuned,
		_PDreduced,
		_MRreduced,
		_attReduced,
		_burnsed,
		_poisoned;
	bool _PDincreased,
		_MRincreased,
		_MDincreased,
		_waterResistant,
		_airResistant,
		_earthResistant,
		_fireResistant,
		_healed,
		_restored,
		_dotoned;
	unsigned short  _burnedCount,
		_stunedCount,
		_reducedPDCount,
		_reducedMRCount,
		_reducedAttCount;
	///AbilitySupport resources
	int _healingCount;
	

	///GENERAL
	int _HP;
	int _HPMax;
	int _physicalDamage;
	int _magicalDamage;
	int _physicalDefense;
	int _magicResist;
	bool _fireResist;
	bool _waterResist;
	bool _earthResist;
	bool _airResist;
	
	elements _elementWeak;
	float _frame;
	sf::Texture _texture;
	sf::Sprite _sprite;
	bool _isAlive;
	bool _flagDie;
	int _backGround;
	int _rectWidth;
	int _rectHeight;
	int _totalFrames;
	Ability _ability[3];

public:
	Dragon();
	//Gets()
	int getHP() { return _HP; }
	int getBaseDamage() { return _physicalDamage; }
	int getBack() { return _backGround; }
	bool getIsAlive() { return _isAlive; }
	elements getElementWeak() { return _elementWeak; }
	float getMR();
	float getPD();
	//Sets()
	void setHP(int hp) { _HP = hp; }
	void setAbility(Ability ability, int i) { _ability[i] = ability; }
	Ability getAbility(int i) { return _ability[i]; }

	void useAbility(Dragon &dragon, int i);

	//Virtual
	virtual void Die() = 0;
	virtual void update() = 0;

	//Funciones pa todos
	void checkStates(bool&);
	void clearState(alteredState);
	int doDamage(int);
	void damageTaken(int);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


	//Sets() AbilityMagic
	void setBurns(bool burnsed) { _burnsed = burnsed; }
	void setPoison() { _poisoned = true; }
	void setStun() { _stuned = true; }
	void setAttReduce() { _attReduced = true; }
	void setPDreduce() { _PDreduced = true; }
	void setMRreduce() { _MRreduced = true; }
	
	void setIsAlive(bool isAlive) { _isAlive = isAlive; }
	//Sets() AbilitySupport
	void setIncreasePD() { _PDincreased = true; }
	void setIncreaseMR() { _MRincreased = true; }
	void setIncreaseMD() { _MDincreased = true; }
	void setHeal(bool healed) { _healed = healed; }
	void setDoton() { _dotoned = true; }



};

#endif