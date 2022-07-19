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
	std::vector <Ability> _abilityEquipment;
	int _level;
	unsigned int _XPrequired[20] = {200, 500, 900, 1400, 2000, 2800, 3800, 5100, 6700, 8700, 11100, 13900, 17400, 21400, 25900, 31100, 37100, 44300, 52700, 62700 };
public:
	DyvirFight();
	//Gets
	unsigned short getWins() { return _wins; }
	int getInventorySize() { return _abilityEquipment.size(); }
	Ability getAbilityInv(int i) { return _abilityEquipment[i]; }
	std::string getAbilityInvName(int i);
	//Sets
	void setWins() { _wins++; }
	void setStats(int HP, int MP, int physicalDamage, int magicDamage, int physicalDefense, int magicResist, int XP);
	std::string setAbilityEquiped(int i, int ability);
	void setFightSprite();

	void update(bool, int) override;
	void Die() override;
	void Win(int enemyXP);
	std::string increaseXP(int XP);
	bool craftAbility(std::string, std::string, int, int);
	void restoreLife();
	void levelUp(int level);
	
};

#endif
