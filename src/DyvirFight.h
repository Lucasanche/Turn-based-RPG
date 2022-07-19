#pragma once
#ifndef DYVIRFIGHT_H
#define DYVIRFIGHT_H

#include "Dragon.h"
#include "Inventory.h"
#include "Ability.h"


class DyvirFight : public Dragon
{
private:
	unsigned short _wins;
	bool _flagWin;
	std::vector <Ability> _abilityInventory;
	unsigned short _level;
	unsigned short _requiredExperience[3];
public:
	DyvirFight();
	void update(bool) override;
	void Die() override;
	void Win();
	void setStats() { /*completar*/ }
	void increaseXP(int XP);
	unsigned short getWins() { return _wins; }	
	void increaseWins() { _wins++; }
	void setWins(int wins) { _wins = wins; }
	std::string setAbilityEquiped(int i, int ability);
	int getInventorySize() { return _abilityInventory.size(); }
	Ability getInventoryElement(int i) { return _abilityInventory[i]; }
	std::string getInventoryElementName(int i);
	std::vector<Ability> getInventory() { return _abilityInventory; }
	void setInventory(std::vector<Ability> inventory) { _abilityInventory = inventory; }
	void setAbilityEquiped(Ability& ability, int i);
	bool craftAbility(std::string, std::string, int, int);
	void setFightSprite();
	void restoreLife();
};

#endif
