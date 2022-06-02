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

	//Barra de vida
	_textureHP.loadFromFile("HP100.png");
	_spriteHP.setTexture(_textureHP);
	_spriteHP.setPosition(650, 280);
	_spriteHP.setOrigin(_spriteHP.getGlobalBounds().width/2,0);
	_spriteHP.setScale(-1,1);

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
}

void dragonAzul::updateSpriteHP()
{
    if (_HP < 100 && _HP > 90) {
        _textureHP.loadFromFile("HP90.png");
    }
    if (_HP <= 90 && _HP > 75) {
        _textureHP.loadFromFile("HP75.png");
    }
    if (_HP <= 75 && _HP > 50) {
        _textureHP.loadFromFile("HP50.png");
    }
    if (_HP <= 50 && _HP > 25) {
        _textureHP.loadFromFile("HP25.png");
    }
    if (_HP <= 25) {
        _textureHP.loadFromFile("HP10.png");
    }
    if (_HP == 0) {
        //_textureHP.loadFromFile("DyvirHP0.png");
    }
    _spriteHP.setTexture(_textureHP);

}

