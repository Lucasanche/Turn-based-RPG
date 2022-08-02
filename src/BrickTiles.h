#ifndef BRICKTILES_H
#define BRICKTILES_H

#include "Collision.h"


class BrickTiles : public sf::Drawable
{
private:
	sf::Texture _texture;
	sf::Sprite _spriteCollision;
	sf::Sprite _spriteNoCollision;
	float _frameVortex;
	float _frameCheckpoint;
	float _frameWalls;
	bool _draw;
public:
	BrickTiles();
	void update(int, int, const char*, int, sf::Time&, sf::RenderWindow& window);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	Collision getCollidable() { return Collision(_spriteCollision); }

};

#endif