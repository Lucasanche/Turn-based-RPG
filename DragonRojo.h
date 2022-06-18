#pragma once
#include "Dragon.h"
class DragonRojo : public sf::Drawable, public Dragon
{
private:
	int _backGround;
	int _frameY;

public:
	DragonRojo();
	void update();
	bool damageTaken(int);
	int doDamage();
	int getBack() { return _backGround; }
	void Die();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


