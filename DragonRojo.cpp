#include "stdafx.h"
#include "DragonRojo.h"

DragonRojo::DragonRojo()
{
///Stats
_HP = 100;
_physicalDamage = 10;
_isAlive = true;
_frameY = 0;


///Sprite
_texture.loadFromFile("dragonRojo.png");
_sprite.setTexture(_texture);
_sprite.setTextureRect({ 0,0,95,59 });
_sprite.setScale(2, 2);
_sprite.setPosition(750 - _sprite.getGlobalBounds().width, 480 - _sprite.getGlobalBounds().height);


///Variables útiles para los sprites
_flagDie = true; // Usar para reproducir la animación de muerte
_frame = 0;
_backGround = 1; // Setea el background que se va a cargar
}
void DragonRojo::update()
{
    if (_isAlive) {
        _frame += 0.15;
        if (_frame >= 4 && _isAlive) {
            _frame = 0;
        }
        _sprite.setTextureRect({ int(_frame) * 100, 0, 100, 100 });
    }
    else {
        this->Die();
    }

}

void DragonRojo::damageTaken(int damageTaken)
{
    _HP -= damageTaken;
    if (_HP <= 0) {
        _HP = 0;
        _isAlive = false;
    }
}
int DragonRojo::doDamage()
{
    int finalDamage = _physicalDamage;
    return finalDamage;
}
void DragonRojo::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}


void DragonRojo::Die()
{
    if (_flagDie) {
        _frame = 0;
        _flagDie = false;
        _texture.loadFromFile("kaboom.png");
        _sprite.setTexture(_texture);
        _sprite.setScale(3.5, 3.5);
        _sprite.setPosition(_sprite.getPosition().x - _sprite.getGlobalBounds().width / 4, _sprite.getPosition().y - _sprite.getGlobalBounds().height / 4);

    }
    _frame += 0.5;
    if (_frame >= 8) {
        _frame = 0;
        _frameY++;
        if (_frameY >= 9) {
            _frameY = 9;
            _frame = 9;
        }
    }
    _sprite.setTextureRect({ int(_frame) * 100, int(_frameY) * 100, 100, 100 });
}
