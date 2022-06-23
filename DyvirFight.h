#pragma once
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
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


