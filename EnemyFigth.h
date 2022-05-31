#pragma once
#include <SFML/Graphics.hpp>
class EnemyFight : public sf::Drawable
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
	int _backGround;
public:
	EnemyFight();
	void update();
	bool damageTaken(int);
	int doDamage();
	int getBack() { return _backGround; }

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

