#pragma once
#ifndef DYVIRFIGHT_H
#define DYVIRFIGHT_H

#include "Dragon.h"
#include "Ability.h"


class DyvirFight : public Dragon
{
private:
	unsigned short _wins;
	bool _flagWin;
	std::vector <Ability> _abilityInventory;
	unsigned short _level;
	unsigned int _XPrequired[20] = {200, 500, 900, 1400, 2000, 2800, 3800, 5100, 6700, 8700, 11100, 13900, 17400, 21400, 25900, 31100, 37100, 44300, 52700, 62700 };
public:
	DyvirFight();

	//Gets
	unsigned short getWins() { return _wins; }
	unsigned short getLevel() { return _level; }
	int getInventorySize() { return _abilityInventory.size(); }
	Ability getInventoryElement(int i) { return _abilityInventory[i]; }
	std::string getInventoryElementName(int i);
	std::vector<Ability> getInventory() { return _abilityInventory; }

	//Sets
	void setWins(int wins) { _wins = wins; }
	void setStats(int HP, int MP, int physicalDamage, int magicDamage, int physicalResistance, int magicResist, int XP);
	void setLevel(unsigned short level) { _level = level; }
	std::string setAbilityEquipedElement(int i, int ability);
	void setAbilityEquiped(Ability ability[]);
	void setInventory(std::vector <Ability> abilityInventory) { _abilityInventory = abilityInventory; }
	void setFightSprite();

	//Functions
	void increaseWins() { _wins++; }
	bool craftAbility(std::string, std::string, int, int);
	void update(bool, int) override;
	void Die() override;
	void Win(int enemyXP);
	std::string increaseXP(int XP);
	void levelUp(int level);
	void restoreLife();
	
};

#endif
