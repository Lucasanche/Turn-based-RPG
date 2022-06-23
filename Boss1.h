#pragma once
#include "Dragon.h"
class Boss1 : public Dragon
{
private:
	int _frameY;

public:
	Boss1();
	void update() override;
	void damageTaken(int) override;
	int doDamage() override;
	void Die();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

