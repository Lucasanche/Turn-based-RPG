#include "dragonAzul.h"

dragonAzul::dragonAzul()
{
	_HP = 100;
	_isAlive = true;
	_BaseDamage = 10;
	_texture.loadFromFile("dragonAzul.png");
	_sprite.setTexture(_texture);
	_sprite.setTextureRect({ 0,0,92,92 });
	_sprite.setScale(2, 2);
	_sprite.setPosition(750 - _sprite.getGlobalBounds().width, 500 - _sprite.getGlobalBounds().height);
	_frame = 0;
	_backGround = 1;
}
void dragonAzul::update()
{
	_frame += 0.1;
	if (_frame >= 4) {
		_frame = 0;
	}
	_sprite.setTextureRect({ int(_frame) * 96, 0, 92, 92 });
}
bool dragonAzul::damageTaken(int damageTaken)
{
	_HP -= damageTaken;
	if (_HP <= 0) {
		_HP = 0;
		_isAlive = false;
	}
	return _isAlive;
}
int dragonAzul::doDamage()
{	
	int finalDamage = _BaseDamage;
	return finalDamage;
}
void dragonAzul::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}
