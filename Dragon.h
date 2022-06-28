#pragma once
#ifndef DRAGON_H
#define DRAGON_H

enum elements
{
	Neutral = 0,
	Fire,
	Water,
	Air,
	Earth
};
enum abilityName {
	Fireball = 0,
	Bubble,
	WindBlow,
	EarthArmor,
	Barrier,
	Heal,
	Restore,
	EarthBarrier,
	WindBarrier,
	WaterBarrier,
	FireBarrier,
	Mirror,
	Tsunami,
	FireTornado,
	VampireFire,
	Earthquake,
	Geiser,
	PoisonGas,
	MagmaWave,
	Inferno,
	Swirl,
	SabakuKyu,
	Doton
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
	unsigned short  _burnedCount,
		_stunedCount,
		_reducedPDCount,
		_reducedMRCount,
		_reducedAttCount;
	int _HP;
	int _HPMax;
	int _physicalDamage;
	elements _elementWeak;
	int _physicalDefense;
	int _magicResist;
	float _frame;
	sf::Texture _texture;
	sf::Sprite _sprite;
	bool _isAlive;
	bool _flagDie;
	int _backGround;
	int _rectWidth;
	int _rectHeight;
	int _totalFrames;

public:
	
	
	Dragon();
	void checkStates(bool&);
	//Gets()
	int getHP() { return _HP; }
	int getBaseDamage() { return _physicalDamage; }
	bool getIsAlive() { return _isAlive; }
	elements getElementWeak() { return _elementWeak; }


	//Sets()
	void setHP(int hp) { _HP = hp; }
	void setIsAlive(bool isAlive) { _isAlive = isAlive; }
	int getBack() { return _backGround; }
	virtual void setStats() = 0;
	virtual void Die() = 0;
	virtual void update() = 0;
	virtual int doDamage() = 0;
	virtual void damageTaken(int) = 0;
	void setBurns() {  _burnsed = true; }
	void setPoison() { _poisoned = true; }
	void setStun() { _stuned = true; }
	void setAttReduce() { _attReduced = true; }
	void setPDreduce() { _PDreduced = true; }
	void setMRreduce() { _MRreduced = true; }
	float getMR();
};

#endif