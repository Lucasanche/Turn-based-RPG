#pragma once
#ifndef DYVIRFIGHT_H
#define DYVIRFIGHT_H
#include "Dragon.h"
#include "Inventory.h"

class DyvirFight : public Dragon
{
private:
	int _wins;
public:
	DyvirFight();
	void update() override;
	void Die() override;
	void setStats(){ /*completar*/ }
	int getWins() { return _wins; }
	void setWins() { _wins++; }
};

#endif
