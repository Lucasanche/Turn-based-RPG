#pragma once
#include <SFML/Graphics.hpp>

class Cursor : public sf::Drawable
{
private:
	sf::Texture _texture;
	sf::Sprite _sprite;
	sf::Vector2f _position;
public:
	Cursor();
	void setPosition(sf::Vector2f);
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::Sprite getSprite(){return _sprite;}
};

