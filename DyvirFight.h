#pragma once
#ifndef DYVIRFIGHT_H
#define DYVIRFIGHT_H
#include "Dragon.h"
#include "dragonAzul.h"
#include "Inventory.h"

class DyvirFight : public Dragon
{
public:
	DyvirFight();
	void update() override;
	void Die() override;
	int doDamage() override;
	void damageTaken(int) override;
	void setStats()override{}
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif
