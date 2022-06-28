#pragma once
#ifndef DRAGONROJO_H
#define DRAGONROJO_H
#include "Enemy.h"
class DragonRojo : public Enemy
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