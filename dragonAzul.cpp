#include "dragonAzul.h"

dragonAzul::dragonAzul()
{
	_HP = 100;
	_isAlive = true;
	_BaseDamage = 5;
	_texture.loadFromFile("dragonAzul.png");
	_sprite.setTexture(_texture);
	_sprite.setTextureRect({ 0,0,92,92 });
	_sprite.setScale(2, 2);
	_sprite.setPosition(750 - _sprite.getGlobalBounds().width, 500 - _sprite.getGlobalBounds().height);
	_frame = 0;
	_backGround = 1;
	_statusHP = 1;
	//Barra de vida
	_textureHP.loadFromFile("HP-bar.png");
	_spriteHP.setTexture(_textureHP);
	_spriteHP.setTextureRect({ 0,0,150,15 });
	_spriteHP.setPosition(750, 460 - _sprite.getGlobalBounds().height);
	_spriteHPFill.setTexture(_textureHP);
	_spriteHPFill.setTextureRect({ 0,15 * _statusHP,150,15 });
	_spriteHPFill.setPosition(_spriteHP.getPosition());
	_spriteHP.setScale(-1,1);
	_spriteHPFill.setScale(-1, 1);
}
void dragonAzul::update()
{
	_frame += 0.15;
	if (_frame >= 4) {
		_frame = 0;
	}

    this->updateSpriteHP();
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
	target.draw(_spriteHP, states);
	target.draw(_spriteHPFill, states);
}

void dragonAzul::updateSpriteHP()
{
	if (_HP < 80 && _HP > 60) {
		_statusHP = 2;
	}
	if (_HP <= 60 && _HP > 40) {
		_statusHP = 3;
	}
	if (_HP <= 40 && _HP > 20) {
		_statusHP = 4;
	}
	if (_HP <= 20 && _HP > 0) {
		_statusHP = 5;
	}
	if (_HP == 0) {
		_statusHP = 1;
	}
	_lenghtHP = _HP * 1.5;

	_spriteHPFill.setTextureRect({ 0,15 * _statusHP,_lenghtHP,15 });

}

