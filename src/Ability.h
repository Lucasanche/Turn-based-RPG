#pragma once
#ifndef ABILITY_H
#define ABILITY_H


class Ability
{
private:
	std::string _name;
	sf::Text _description;
	elements _element1;
	elements _element2;
	int _id;
	int _mpCost;
	std::vector<bool>_negativeStates;
	std::vector<bool>_positiveStates;
	int _magicDamage;
public:
	Ability();
	void reset();
	//Sets()
	void setName(std::string name) { _name=name; }
	void setDescription(sf::String description) { _description.setString(description); }
	void setMagicDamage(int magicDamage) { _magicDamage = magicDamage; }
	void setID(int id) { _id = id; }
	void setMpCost(int mpCost) { _mpCost = mpCost; }
	void setElements(elements element1, elements element2);

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

	//Gets()
	bool getNegativeStates(int i) { return _negativeStates[i]; }
	bool getPositiveStates(int i) { return _positiveStates[i]; }

	const std::string getName(){ return _name;}
	sf::String getDescription() { return _description.getString(); }
	int getMagicDamage() { return _magicDamage; }
	int getID() { return _id; }
	int getMpCost() { return _mpCost; }
	elements getElement1() { return _element1; }
	elements getElement2() { return _element2; }

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

	virtual ~Ability() {};
};

#endif
