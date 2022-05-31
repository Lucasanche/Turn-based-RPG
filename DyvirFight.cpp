#include "DyvirFight.h"

DyvirFight::DyvirFight()
{
	_HP = 100;
	_isAlive = true;
	_BaseDamage = 10;
	_texture.loadFromFile("dyvir.png");
	_sprite.setTexture(_texture);
	_sprite.setTextureRect({ 0,0,260,230 });
	_sprite.setScale(0.5, 0.5);
	_sprite.setPosition(50, 500 - _sprite.getGlobalBounds().height);
	_frame = 0;
}

void DyvirFight::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}

void DyvirFight::update()
{
	_frame += 0.075;
	if (_frame >= 8) {
		_frame = 0;
	}
	_sprite.setTextureRect({ int(_frame) * 260, 0, 260, 230 });
}

