#pragma once
#include "Dragon.h"
class dragonAzul : public sf::Drawable, public Dragon
{
private:
	int _backGround;
	int _frameY;

public:
	dragonAzul();
	void update();
	bool damageTaken(int);
	int doDamage();
    void updateSpriteHP();
	int getBack() { return _backGround; }
	void Die();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

