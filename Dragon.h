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
enum alteredState {
	All = 0,
	Poison,
	Burns,
	AttReduce,
	MRreduce,
	PDreduce,
	Stun
};

class Dragon : public sf::Drawable
{
protected:
	///AbilityMagic resources
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
	///AbilitySupport resources
	int _healingCount;
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
	Ability _ability1;
	Ability _ability2;
	Ability _ability3;

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
	void setAbility1(Ability ability) { _ability1 = ability; }
	void setAbility2(Ability ability) { _ability2 = ability; }
	void setAbility3(Ability ability) { _ability3 = ability; }
	Ability getAbility1() { return _ability1; }
	Ability getAbility2() { return _ability2; }
	Ability getAbility3() { return _ability3; }

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
	void setBurns() { _burnsed = true; }
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
	void setHeal() { _healed = true; }
	void setDoton() { _dotoned = true; }



};

#endif