#pragma once
#ifndef DYVIRMAP_H
#define DYVIRMAP_H
#include "Collision.h"
#include "BrickTiles.h"


class DyvirMap : public sf::Drawable, public Collision
{
private:
	float _frame;
	sf::Texture _texture;
	sf::Sprite _sprite;
	bool Collide;
	sf::Vector2f _newPos;
	int _speedX, _speedY;
public:
	//Functions
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	bool update();
	DyvirMap();
	sf::Vector2f getPosition() { return _sprite.getPosition(); }
	void setPosition(sf::Vector2f position) { _sprite.setPosition(position); }
	sf::Vector2f _velocity = { 0, 0 };
	sf::FloatRect getBounds() const override;
	void setCollide();
};

#endif