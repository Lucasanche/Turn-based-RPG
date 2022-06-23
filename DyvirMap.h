#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class DyvirMap : public sf::Drawable
{
private:
	float _frame;
	sf::Vector2f _velocity = {0, 0};
	sf::Texture _texture;
	sf::Sprite _sprite;
public:
	//Functions
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void update();
	DyvirMap();
	//sf::Vector2f setVelocity(sf::Vector2f vel) { _velocity = vel; }
	sf::Vector2f getPosition() { return sf::Vector2f(_sprite.getPosition()); }
};


