#pragma once
#ifndef ABILITY_H
#define ABILITY_H


class Ability
{
private:
	sf::String _name;
	sf::String _description;
	elements _element1;
	elements _element2;
	unsigned int _mpCost;
	std::vector<bool>_negativeStates;
	std::vector<bool>_positiveStates;
	unsigned short _magicDamage;
	abilityName _ID;
public:
	Ability();
	void reset();

	//Sets()
	void setName(sf::String name) { _name = name; }
	void setDescription(sf::String description) { _description = description; }
	void setMagicDamage(int magicDamage) { _magicDamage = magicDamage; }
	void setMpCost(int mpCost) { _mpCost = mpCost; }
	void setElements(elements element1, elements element2);
	void setID(abilityName ID) { _ID = ID; }

	//Estados positivos
	void setIncreasePD() { _positiveStates[increasePD] = true; }
	void setIncreasePR() { _positiveStates[increasePR] = true; }
	void setIncreaseMR() { _positiveStates[increaseMR] = true; }
	void setIncreaseMD() { _positiveStates[increaseMD] = true; }
	void setIncreaseATT() { _positiveStates[increaseATT] = true; }
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
	void setReducePR() { _negativeStates[reducePR] = true; }
	void setReduceMR() { _negativeStates[reduceMR] = true; }
	void setReduceMD() { _negativeStates[reduceMD] = true; }
	void setReduceAtt() { _negativeStates[reduceAtt] = true; }

	//Gets()
	bool getNegativeStates(int i) { return _negativeStates[i]; }
	bool getPositiveStates(int i) { return _positiveStates[i]; }
	abilityName getID() { return _ID; }
	const sf::String getName() { return _name; }
	sf::String getDescription() { return _description; }
	int getMagicDamage() { return _magicDamage; }
	int getMpCost() { return _mpCost; }
	elements getElement1() { return _element1; }
	elements getElement2() { return _element2; }

	//Estados positivos
	bool getIncreasePD() { return _positiveStates[increasePD]; }
	bool getIncreaseMR() { return _positiveStates[increaseMR]; }
	bool getIncreaseMD() { return _positiveStates[increaseMD]; }
	bool getIncreasePR() { return _positiveStates[increasePR]; }
	bool getIncreaseATT() { return _positiveStates[increaseATT]; }
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

	virtual ~Ability() {};
};

#endif
