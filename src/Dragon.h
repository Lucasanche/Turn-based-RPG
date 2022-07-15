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
		_reducedMRCount,
		_reducedAttCount,
		_healingCount,
		_increasedAttCount,
		_increasedPDCount,
		_increasedMRCount,
		_increasedMDCount;

	///GENERAL
	int _HP;
	int _HPbase;
	int _MP;
	int _MPbase;
	int _physicalDamage;
	int _physicalDamagebase;
	int _magicalDamage;
	int _magicalDamagebase;
	int _physicalDefense;
	int _physicalDefensebase;
	int _magicResist;
	int _magicResistbase;
	bool _fireResist;
	bool _waterResist;
	bool _earthResist;
	bool _airResist;
	Ability _ability[3];
	elements _elementWeak;
	bool _isAlive;

	sf::Texture _texture;
	sf::Sprite _sprite;
	float _frame;
	bool _flagDie;
	int _backGround;
	int _rectWidth;
	int _rectHeight;
	int _totalFrames;

public:
	Dragon();

	//Gets()
	int getHP() { return _HP; }
	int getHPbase() { return _HPbase; }
	int getMP() { return _MP; }
	int getMPbase() { return _MPbase; }
	int getPhysicalDamage() { return _physicalDamage; }
	int getMagicalDamage() { return _magicalDamage; }
	int getPhysicalDefense() { return _physicalDefense; }
	int getMagicResist() { return _magicResist; }


	int getBack() { return _backGround; }
	bool getIsAlive() { return _isAlive; }
	elements getElementWeak() { return _elementWeak; }
	float getMR();
	float getPD();
	Ability getAbility(int i) { return _ability[i]; }

	//Estados positivos
	bool getIncreasePD() { return _positiveStates[increasePD]; }
	bool getIncreaseMR() { return _positiveStates[increaseMR]; }
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
	bool getReduceMR() { return _negativeStates[reduceMR]; }
	bool getReduceAtt() { return _negativeStates[reduceAtt]; }

	//Sets()
	void setIsAlive(bool isAlive) { _isAlive = isAlive; }
	void setHP(int HP) { _HP = HP; }
	void setHPMax(int HPMax) { _HPbase = HPMax; }
	void setMP(int MP) { _MP = MP; }
	void setMPMax(int MPMax) { _MPbase = MPMax; }
	void setPhysicalDamage(int physicalDamage) { _physicalDamage = physicalDamage; }
	void setMagicalDamage(int magicalDamage) { _magicalDamage = magicalDamage; }
	void setPhysicalDefense(int physicalDefense) { _physicalDefense = _physicalDefense; }
	void setMagicResist(int magicResist) { _magicResist = magicResist; }
	void setFireResist(bool fireResist) { _fireResist = fireResist; }
	void setWaterResist(bool waterResist) { _waterResist = waterResist; }
	void setEarthResist(bool earthResist) { _earthResist = earthResist; }
	void setAirResist(bool airResist) { _airResist = airResist; }
	void setAbility(int abilityNumber, abilityName abName);

	//Estados positivos
	void setIncreasePD() { _positiveStates[increasePD] = true; }
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

	//Virtual
	virtual void Die() = 0;
	virtual void update(bool) = 0;

	//Functions
	void useAbility(Dragon& dragon, int i);
	void clearStates() { std::replace(_negativeStates.begin(), _negativeStates.end(), true, false); }
	void checkStates(turns& turn);
	int	doDamage(int);
	void resetStats();
	int damageTaken(int);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif