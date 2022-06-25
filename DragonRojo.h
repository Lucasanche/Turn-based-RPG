#pragma once
#ifndef DRAGONROJO_H
#define DRAGONROJO_H
#include "Dragon.h"
class DragonRojo : public Dragon
{
private:
	int _frameY;

public:
	DragonRojo();
	void update() override;
	void damageTaken(int) override;
	int doDamage() override;
	void Die() override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif