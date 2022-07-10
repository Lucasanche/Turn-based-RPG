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
	int _abilityAmount;
	bool _flagWin;
	Ability _abilityInventory[10];
public:
	DyvirFight();
	void update() override;
	void Die() override;
	void setStats() { /*completar*/ }
	int getWins() { return _wins; }
	void setWins() { _wins++; }
	Ability getAbilityInv(int i) { return _abilityInventory[i]; }
};

#endif
