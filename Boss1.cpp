#include "stdafx.h"
#include "Boss1.h"

Boss1::Boss1()
{///Stats
    _HP = 100;
    _BaseDamage = 10;
    _isAlive = true;
    _frameY = 0;


    ///Sprite
    _texture.loadFromFile("Boss1.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({ 0,0,92,92 });
    _sprite.setScale(2, 2);
    _sprite.setPosition(750 - _sprite.getGlobalBounds().width, 480 - _sprite.getGlobalBounds().height);


    ///Variables útiles para los sprites
    _flagDie = true; // Usar para reproducir la animación de muerte
    _frame = 0;
    _backGround = 1; // Setea el background que se va a cargar
}
void Boss1::update()
{
    if (_isAlive) {
        _frame += 0.15;
        if (_frame >= 11 && _isAlive) {
            _frame = 0;
        }
        _sprite.setTextureRect({ int(_frame) * 96, 0, 82, 92 });
    }
    else {
        this->Die();
    }

}

void Boss1::damageTaken(int damageTaken)
{
    _HP -= damageTaken;
    if (_HP <= 0) {
        _HP = 0;
        _isAlive = false;
    }
}
int Boss1::doDamage()
{
    int finalDamage = _BaseDamage;
    return finalDamage;
}
void Boss1::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}


void Boss1::Die()
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
