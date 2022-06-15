#pragma once
#include <SFML/Graphics.hpp>

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
};


