#pragma once
#ifndef ELEMENTS_H
#define ELEMENTS_H
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
	HotVampire,
	Earthquake,
	Geiser,
	PoisonGas,
	MagmaWave,
	Inferno,
	Swirl,
	SabakuKyu,
	Doton
};
enum alteredState {
	All = 0,
	Poison,
	Burns,
	AttReduce,
	MRreduce,
	PDreduce,
	Stun
};
#endif

#pragma once
#ifndef DRAGON_H
#define DRAGON_H
class Dragon : public sf::Drawable
{
protected:
	bool _stuned,
		_PDreduced,
		_MRreduced,
		_attReduced,
		_burnsed,
		_poisoned;
	unsigned short  _burnedCount,
		_stunedCount,
		_reducedPDCount,
		_reducedMRCount,
		_reducedAttCount;
	int _HP;
	int _HPMax;
	int _physicalDamage;
	int _magicResist;
	int _physicalDefense;
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
	void setBurns() { _burnsed = true; }
	void setPoison() { _poisoned = true; }
	void setStun() { _stuned = true; }
	void setAttReduce() { _attReduced = true; }
	void setPDreduce() { _PDreduced = true; }
	void setMRreduce() { _MRreduced = true; }
	void setHP(int hp) { _HP = hp; }
	void setIsAlive(bool isAlive) { _isAlive = isAlive; }


	//Virtual
	virtual void Die() = 0;
	virtual void update() = 0;
	
	//Funciones pa todos
	void checkStates(bool&);
	void clearState(alteredState);
	int doDamage(int);
	
	void damageTaken(int);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif