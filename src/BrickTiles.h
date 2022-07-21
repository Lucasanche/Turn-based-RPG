#ifndef BRICKTILES_H
#define BRICKTILES_H

#include "Collision.h"


class BrickTiles : public sf::Drawable, public Collision
{
public:
	BrickTiles();
	void update(int, int, int, int, int);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::FloatRect getBounds() const override;
private:
	sf::Texture _texture;
	sf::Sprite _sprite;
	sf::Texture _texture2;
	sf::Sprite _sprite2;
	float _frameVortex;
	float _frameVortex2;
};

#endif