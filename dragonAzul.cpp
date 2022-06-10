#include "dragonAzul.h"

dragonAzul::dragonAzul()
{
    ///Stats
    _HP = 100;
    _BaseDamage = 10;
    _isAlive = true;


    ///Sprite
    _texture.loadFromFile("dragonAzul.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({ 0,0,92,92 });
    _sprite.setScale(2, 2);
    _sprite.setPosition(750 - _sprite.getGlobalBounds().width, 500 - _sprite.getGlobalBounds().height);


    ///Barra de vida
    //Base
    _textureHP.loadFromFile("HP-bar.png");
    //HP vacio
    _spriteHP.setTexture(_textureHP);
    _spriteHP.setTextureRect({ 0,0,150,15 });
    _spriteHP.setPosition(_sprite.getPosition().x + 30, _sprite.getPosition().y - 30);
    _spriteHP.setOrigin(_spriteHP.getGlobalBounds().width / 2, 0);

    //Relleno HP
    _spriteHPFill.setTexture(_textureHP);
    _spriteHPFill.setTextureRect({ 0,15 * _statusHP,150,15 });
    _spriteHPFill.setPosition(_spriteHP.getPosition());
    _spriteHPFill.setOrigin(_spriteHP.getOrigin());
    _spriteHPFill.setScale(_spriteHP.getScale());

    ///Variables útiles para los sprites
    _flagDie = true; // Usar para reproducir la animación de muerte
    _frame = 0;
    _statusHP = 1; // Setea el color de la barra de vida
    _backGround = 1; // Setea el background que se va a cargar
    _lenghtHP = _spriteHP.getGlobalBounds().width; // Setea el largo del relleno del HP
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
void dragonAzul::Die()
{
    if (_flagDie) {
        _frame = 0;
        _flagDie = false;
    }
    _frame += 0.15;
    if (_frame >= 3) {
        _frame = 3;
    }

    _texture.loadFromFile("1.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({ int(_frame) * 110, 0, 110, 170 });
    _sprite.setScale(1.4, 1.4);
    _sprite.setPosition(500, 560 - _sprite.getGlobalBounds().height);

}
