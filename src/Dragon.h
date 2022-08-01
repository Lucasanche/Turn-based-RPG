#pragma once
#ifndef DRAGON_H
#define DRAGON_H

#include "Ability.h"
#include "AbilityFactory.h"


class Dragon : public sf::Drawable
{
protected:
	///AbilityMagic resources
	std::vector<bool>_negativeStates;
	std::vector<bool>_positiveStates;
	unsigned short  _burnedCount,
		_stunedCount,
		_reducedPDCount,
		_reducedPRCount,
		_reducedMRCount,
		_reducedAttCount,
		_reducedMDCount,
		_healingCount,
		_increasedAttCount,
		_increasedPDCount,
		_increasedMRCount,
		_increasedMDCount,
		_increasedPRCount;

	///GENERAL
	int _HP;
	int _HPbase;
	int _MP;
	int _MPbase;
	short _physicalDamage;
	short _physicalDamagebase;
	short _magicDamage;
	short _magicDamagebase;
	short _physicalResistance;
	short _physicalResistancebase;
	short _magicResistance;
	short _magicResistancebase;
	unsigned int _XP;
	Ability _ability[3];
	AbilityFactory _abilityFactory;
	elements _elementWeak;
	elements _elementResist;
	bool _isAlive;
	sf::Texture _texture;
	sf::Sprite _sprite;
	float _frame;
	bool _flagDie;
	bool _flagWin;
	unsigned short _backGround;
	int _rectWidth;
	int _rectHeight;
	unsigned short _totalFrames;
	sf::Texture _textureStates;
	//States Sprites
	sf::Sprite _spriteStates;
	sf::Vector2f _spriteStatesPosition;

public:
	Dragon();
	//Gets()
	int getHP() { return _HP; }
	int getHPbase() { return _HPbase; }
	int getMP() { return _MP; }
	int getMPbase() { return _MPbase; }
	int getPhysicalDamage() { return _physicalDamage; }
	int getMagicDamage() { return _magicDamage; }
	int getPhysicalResistance() { return _physicalResistance; }
	int getMagicResistance() { return _magicResistance; }
	int getPhysicalDamageBase() { return _physicalDamagebase; }
	int getMagicDamageBase() { return _magicDamagebase; }
	int getPhysicalResistanceBase() { return _physicalResistancebase; }
	int getMagicResistanceBase() { return _magicResistancebase; }
	int getXP() { return _XP; }
	int getBack() { return _backGround; }
	bool getIsAlive() { return _isAlive; }
	elements getElementWeak() { return _elementWeak; }
	elements getElementResist() { return _elementResist; }
	float getMRmultiplier();
	float getPRmultiplier();
	float getMDmultiplier();
	Ability getAbility(int i) { return _ability[i]; }

	//Estados positivos
	bool getIncreasePD() { return _positiveStates[increasePD]; }
	bool getIncreaseMR() { return _positiveStates[increaseMR]; }
	bool getIncreasePR() { return _positiveStates[increasePR]; }
	bool getIncreaseMD() { return _positiveStates[increaseMD]; }
	bool getHeal() { return _positiveStates[heal]; }
	bool getRestore() { return _positiveStates[restore]; }
	bool getDoton() { return _positiveStates[doton]; }
	bool getWaterResist() { return _positiveStates[waterResist]; }
	bool getFireResist() { return _positiveStates[fireResist]; }
	bool getAirResist() { return _positiveStates[airResist]; }
	bool getEarthResist() { return _positiveStates[earthResist]; }
	bool getDamageMultiplier() { return _positiveStates[damageMultiplier]; }
	bool getTrueDamage() { return _positiveStates[trueDamage]; }

	//Estados negativos
	bool getVampireishon() { return _negativeStates[vampireishon]; }
	bool getStun() { return _negativeStates[stun]; }
	bool getBurns() { return _negativeStates[burns]; }
	bool getPoison() { return _negativeStates[poison]; }
	bool getReducePD() { return _negativeStates[reducePD]; }
	bool getReducePR() { return _negativeStates[reducePR]; }
	bool getReduceMR() { return _negativeStates[reduceMR]; }
	bool getReduceMD() { return _negativeStates[reduceMD]; }
	bool getReduceAtt() { return _negativeStates[reduceAtt]; }

	//Sets()
	void setIsAlive(bool isAlive) { _isAlive = isAlive; }
	void setHP(int HP) { _HP = HP; }
	void setHPMax(int HPMax) { _HPbase = HPMax; }
	void setMP(int MP) { _MP = MP; }
	void setMPMax(int MPMax) { _MPbase = MPMax; }
	void setPhysicalDamage(int physicalDamage) { _physicalDamage = physicalDamage; }
	void setMagicDamage(int magicDamage) { _magicDamage = magicDamage; }
	void setPhysicalResistance(int physicalResistance) { _physicalResistance = _physicalResistance; }
	void setMagicResistance(int magicResistance) { _magicResistance = magicResistance; }
	void setElementResist(elements elementResist) { _elementResist = elementResist; }
	void setAbilityFromInventory(int abilityNumber, abilityName abName);
	void setXP(int XP) { _XP = XP; }

	//Estados positivos
	void setIncreasePD() { _positiveStates[increasePD] = true; }
	void setIncreasePR() { _positiveStates[increasePR] = true; }
	void setIncreaseMR() { _positiveStates[increaseMR] = true; }
	void setIncreaseMD() { _positiveStates[increaseMD] = true; }
	void setHeal() { _positiveStates[heal] = true; }
	void setRestore() { _positiveStates[restore] = true; }
	void setDoton() { _positiveStates[doton] = true; }
	void setWaterResist() { _positiveStates[waterResist] = true; }
	void setFireResist() { _positiveStates[fireResist] = true; }
	void setAirResist() { _positiveStates[airResist] = true; }
	void setEarthResist() { _positiveStates[earthResist] = true; }
	void setEamageMultiplier() { _positiveStates[damageMultiplier] = true; }
	void setTrueDamage() { _positiveStates[trueDamage] = true; }

	//Estados negativos
	void setVampireishon() { _negativeStates[vampireishon] = true; }
	void setStun() { _negativeStates[stun] = true; }
	void setBurns() { _negativeStates[burns] = true; }
	void setPoison() { _negativeStates[poison] = true; }
	void setReducePD() { _negativeStates[reducePD] = true; }
	void setReduceMR() { _negativeStates[reduceMR] = true; }
	void setReduceAtt() { _negativeStates[reduceAtt] = true; }
	void setReduceMD() { _negativeStates[reduceMD] = true; }

	//Virtual
	virtual void Die() = 0;
	virtual void update(bool, int) = 0;

	//Functions
	void checkHP();
	void useAbility(Dragon& dragon, int index, int& damage);
	void clearStates() { std::replace(_negativeStates.begin(), _negativeStates.end(), true, false); }
	std::vector <bool> checkNegativeStates(turns& turn);
	std::vector <bool> checkPositiveStates();
	virtual void updateSpriteStates(sf::RenderWindow& window) = 0;
	int	doDamage(int);
	void resetStats();
	int damageTaken(int);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif