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
	_frame = 0;
    _isAlive = true;

    //Barra de vida
    _textureHP.loadFromFile("HP100.png");
    _spriteHP.setTexture(_textureHP);
    _spriteHP.setPosition(20, 460 - _sprite.getGlobalBounds().height);

}

void DyvirFight::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
    target.draw(_spriteHP, states);
}
void DyvirFight::damageTaken(int damageTaken)
{
    _HP -= damageTaken;
    if (_HP <= 0) {
        _HP = 0;
        _isAlive = false;
    }
    //return _isAlive;
}



void DyvirFight::update()
{
    _frame += 0.075;	if (_frame >= 8) {
        _frame = 0;
    }
    this->updateSpriteHP();
    _sprite.setTextureRect({ int(_frame) * 260, 0, 260, 230 });
}


///CREO QUE TENDRIAMOS QUE USAR LA FUNCION DIE Y CAMBIAR LOS ESTADOS CON EL SETISALIVE.
//bool DyvirFight::changeStatus() {
//
//    if (_isAlive) {
//        _texture.loadFromFile("dyvir.png");
//        _sprite.setTexture(_texture);
//        _sprite.setTextureRect({ 0,0,170,110 });
//        _sprite.setScale(0.5, 0.5);
//        _sprite.setPosition(50, 500 - _sprite.getGlobalBounds().height);
//        _frame = 0;
//
//        _isAlive = false;
//        return _isAlive;
//
//    }
//
//    else {
//        _texture.loadFromFile("dyvir_dead.png");
//        _sprite.setTexture(_texture);
//        _sprite.setTextureRect({ 0,0,102,67 });
//        ///_sprite.setScale(1.5, 1.5);
//        _sprite.setPosition(85, 500 - _sprite.getGlobalBounds().height);
//        _frame = 0;;
//
//        _isAlive = true;
//        return _isAlive;
//    }
//
//}

void DyvirFight::Die()
{
    _frame += 0.15;
    if (_frame >= 10) {
        _frame = 0;
        //return;
    }

    _texture.loadFromFile("Dyvir_dead.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({ int(_frame) * 170, 0, 170, 110 });
    _sprite.setScale(1, 1);
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
