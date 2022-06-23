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
	_sprite.setPosition(85, 480 - _sprite.getGlobalBounds().height);
    _isAlive = true;

    /////Variables útiles para los sprites
    _flagDie = true; // Usar para reproducir la animación de muerte
    _frame = 0;
}

void DyvirFight::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
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
    if (_isAlive) {
        _frame += 0.15;
        if (_frame >= 8 && _isAlive) {
            _frame = 0;
        }
        _sprite.setTextureRect({ int(_frame) * 260, 0, 260, 230 });
    }
    else {
        this->Die();
    }
    
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

    _sprite.setPosition(85, 480 - _sprite.getGlobalBounds().height);
}

int DyvirFight::doDamage(/*AbilityMagic& ability*/) // tiene sentido? 
{
    ///METER TODAS LAS SINERGIAS ACA. 
    int finalDamage;
    finalDamage = _BaseDamage;
    return finalDamage;
}