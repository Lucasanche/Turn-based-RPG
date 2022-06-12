#include "DyvirFight.h"

DyvirFight::DyvirFight()
{
	_HP = 100;
	//_isAlive = false;
	_BaseDamage = 10;
    _texture.loadFromFile("dyvir.png");
	_sprite.setTexture(_texture);
	_sprite.setTextureRect({ 0,0,260,230 });
	_sprite.setScale(0.5, 0.5);
	_sprite.setPosition(85, 500 - _sprite.getGlobalBounds().height);
    _isAlive = true;
    //Barra de vida
    _textureHP.loadFromFile("HP-bar.png");
    _spriteHP.setTexture(_textureHP);
    _spriteHP.setTextureRect({ 0,0,150,15});
    _spriteHP.setPosition(_sprite.getPosition().x, _sprite.getPosition().y - 30);
    _spriteHPFill.setTexture(_textureHP);
    _spriteHPFill.setTextureRect({ 0,15*_statusHP,150,15 });
    _spriteHPFill.setPosition(_spriteHP.getPosition());

    ///Variables útiles para los sprites
    _flagDie = true; // Usar para reproducir la animación de muerte
    _frame = 0;
    _statusHP = 1; // Setea el color de la barra de vida
    _lenghtHP = _spriteHP.getGlobalBounds().width; // Setea el largo del relleno del HP

}

void DyvirFight::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
    target.draw(_spriteHP, states);
    target.draw(_spriteHPFill, states);
}
void DyvirFight::damageTaken(int damageTaken)
{
    _HP -= damageTaken;
    if (_HP <= 0) {
        _HP = 0;
        _isAlive = false;
    }
}



void DyvirFight::update()
{
    _frame += 0.15;
    if (_frame >= 8 && _isAlive) {
        _frame = 0;
    }
    this->updateSpriteHP();
    _sprite.setTextureRect({ int(_frame) * 260, 0, 260, 230 });
}

void DyvirFight::Die()
{
    if (_flagDie) {
        _frame = 0;
        _flagDie = false;
        _texture.loadFromFile("Dyvir_dead.png");
        _sprite.setTexture(_texture);
        _sprite.setScale(1, 1);
    }
    _frame += 0.15;
    if (_frame >= 9) {
        _frame = 9;
    }
    _sprite.setTextureRect({ int(_frame) * 170, 0, 170, 110 });

    _sprite.setPosition(85, 500 - _sprite.getGlobalBounds().height);

}

int DyvirFight::doDamage()
{
    int finalDamage;
    finalDamage = _BaseDamage;
    return finalDamage;
}

void DyvirFight::updateSpriteHP()
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

    _spriteHPFill.setTextureRect({ 0,15 * _statusHP,_lenghtHP,15});
}
