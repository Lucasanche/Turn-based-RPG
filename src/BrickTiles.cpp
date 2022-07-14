#include "stdafx.h"
#include "BrickTiles.h"


BrickTiles::BrickTiles() {
	_texture.loadFromFile("./Textures/Backgrounds/Tilesheet.png");
	_sprite.setTexture(_texture);
	_frameVortex = 1;
}

void BrickTiles::update(int j, int i, int x, int y) {
	_sprite.setPosition(j * 35, i * 35);
	if (x == 0) {
		_sprite.setTextureRect(sf::IntRect(x * 35, y * 35, 35, 35));
	}
	else
	{
		_frameVortex += 0.15;
		if (_frameVortex >= 10) {
			_frameVortex = 1;
		}
		_sprite.setTextureRect(sf::IntRect( int(_frameVortex) * 35, 0, 35, 35));

	}

}

void BrickTiles::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_sprite, states);
}

sf::FloatRect BrickTiles::getBounds() const {
	return _sprite.getGlobalBounds();
}