#pragma once
#ifndef MAPWALLS_H
#define MAPWALLS_H
#include "Collision.h"
class MapWalls : public sf::Drawable, public Collision
{
	private:
		sf::Texture _texture;
		sf::Sprite _sprite;

	public:
		//Functions
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		MapWalls(int, int);
		sf::FloatRect getBounds() const override;
	};

#endif