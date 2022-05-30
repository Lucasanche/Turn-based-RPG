#pragma once
#include <SFML/Graphics.hpp>
class dragonAzul : public sf::Drawable
{
private:
	int _HP;
	int _BaseDamage;
	/*int BaseDefense;
	int ElectricDamage;
	int FireDamage;*/
	bool _isAlive;
	sf::Texture _texture;
	sf::Sprite _sprite;
	float _frame;
public:
	dragonAzul();
	void update();
	bool damageTaken(int);
	int doDamage();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

