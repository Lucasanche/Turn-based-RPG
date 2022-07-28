#ifndef BRICKTILES_H
#define BRICKTILES_H

#include "Collision.h"


class BrickTiles : public sf::Drawable
{
private:
	sf::Texture _texture;
	sf::Sprite _sprite;
	float _frameVortex;
	float _frameCheckpoint;
public:
	BrickTiles();
	void update(int, int, char, int);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	Collision getCollidable() { return Collision(_sprite); }

};

#endif