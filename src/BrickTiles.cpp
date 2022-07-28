#include "stdafx.h"
#include "BrickTiles.h"


BrickTiles::BrickTiles() {
	_texture.loadFromFile("./Textures/Backgrounds/Tilesheet2.png");
	_sprite.setTexture(_texture);
	_frameVortex = 1;
	_frameCheckpoint = 10;
	_sprite.setTextureRect(sf::IntRect(0, 0, 35, 35));
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
}

void BrickTiles::update(int j, int i, char x, int wins) {

	wins += 2;
	
	if (x == '1') {
		_sprite.setTextureRect(sf::IntRect(0, 0, 35, 35));
		_sprite.setPosition(j * 35, i * 35);
	}
	else if (x=='2')
	{	_frameCheckpoint += 0.05;
		if (_frameCheckpoint >= 35) {
			_frameCheckpoint = 10;
		}
		_sprite.setTextureRect(sf::IntRect(int(_frameCheckpoint) * 35, 0, 35, 35));
		_sprite.setPosition(j * 35, i * 35);
	}
	else if (wins < x - '0') {
		_frameVortex += 0.05;
		if (_frameVortex >= 10) {
			_frameVortex = 1;
		}
		_sprite.setTextureRect(sf::IntRect(int(_frameVortex) * 35, 0, 35, 35));
		_sprite.setPosition(j * 35, i * 35);
	}
}

void BrickTiles::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_sprite, states);
}
