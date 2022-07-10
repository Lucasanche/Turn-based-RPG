#include "stdafx.h"
#include "Cursor.h"


Cursor::Cursor() {
	_texture.loadFromFile("./Textures/Interface/Cursor.png");
	_sprite.setTexture(_texture);
	_sprite.setOrigin(0, 0);
}

void Cursor::setPosition(sf::Vector2f pos) {
	_sprite.setPosition(pos);
}

void Cursor::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_sprite, states);
}
