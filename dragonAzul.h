#pragma once
#include "Dragon.h"
class dragonAzul : public Dragon
{
private:
	int _frameY;

public:
	dragonAzul();
	void update() override;
	void damageTaken(int) override;
	int doDamage() override;
	void Die() override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void Reset();
};

