#pragma once
#ifndef DYVIRFIGHT_H
#define DYVIRFIGHT_H

#include "Dragon.h"
#include "Inventory.h"
#include "Ability.h"


class DyvirFight : public Dragon
{
private:
	int _wins;
	bool _flagWin;
	std::vector <Ability> _abilityEquipment;
public:
	DyvirFight();
	void update(bool) override;
	void Die() override;
	void Win();
	void setStats() { /*completar*/ }
	int getWins() { return _wins; }
	void setWins() { _wins++; }
	int getInventorySize() { return _abilityEquipment.size(); }
	Ability getAbilityInv(int i) { return _abilityEquipment[i]; }
	std::string getAbilityInvName(int i);

	void setFightSprite();
	void restoreLife();
};

#endif
