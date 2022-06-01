#pragma once
#include <SFML/Graphics.hpp>

class DyvirFight : public sf::Drawable
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
	DyvirFight();
	/// Getters
	int getHP() { return _HP; }
	int getBaseDamage() { return _BaseDamage; }
	bool getIsAlive() { return _isAlive; }

	void update();
	void changeStatus();
	int doDamage();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


