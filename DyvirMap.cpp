#include "DyvirMap.h"


DyvirMap::DyvirMap()
{
    _texture.loadFromFile("dyvirMap.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({ 0, 0, 222, 169 });
    _sprite.setScale(0.5, 0.5);
    _sprite.setPosition(85, 480 - _sprite.getGlobalBounds().height);
    _sprite.setOrigin(_sprite.getLocalBounds().width/2, 0);
    _frame = 0;

}


void DyvirMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

void DyvirMap::update()
{
    _frame += 0.3;
    if (_frame >= 5) {
        _frame = 0;
    }
    _sprite.setTextureRect({ int(_frame) * 222, 0, 222, 169 });



    /// MOV
    _velocity = { 0, 0 };
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        _velocity.y = -4;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        _velocity.y = 4;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        _velocity.x = -4;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _velocity.x = 4;
    }

    ///EVITAR QUE SALGA DE LA PANTALLA;;;
    if (_sprite.getPosition().x < 0) {
        _sprite.setPosition(0, _sprite.getPosition().y);
    }

    if (_sprite.getPosition().y < 0) {
        _sprite.setPosition(_sprite.getPosition().x, 0);
    }

    if (_sprite.getPosition().x > 800) {
        _sprite.setPosition(700, _sprite.getPosition().y);
    }

    if (_sprite.getPosition().y + _sprite.getGlobalBounds().height > 700) {
        _sprite.setPosition(_sprite.getPosition().x, 700 - _sprite.getGlobalBounds().height);
    }
   
    ///QUE MIRE A LOS LADOS
    _sprite.move(_velocity); 
    if (_velocity.x < 0) {
        _sprite.setScale(-0.5, 0.5);
    }
    if(_velocity.x > 0) {
        _sprite.setScale(0.5, 0.5);
    }

    if (_sprite.getGlobalBounds().left < 0) {
        _sprite.setPosition(_sprite.getOrigin().x, _sprite.getPosition().y);
    }

    if (_sprite.getGlobalBounds().top < 0) {
        _sprite.setPosition(_sprite.getPosition().x, _sprite.getPosition().y);
    }

    if (_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width > 800) {
        _sprite.setPosition(800 - (_sprite.getGlobalBounds().width - _sprite.getOrigin().x), _sprite.getPosition().y);
    }

    if (_sprite.getGlobalBounds().top + _sprite.getGlobalBounds().height > 800) {
        _sprite.setPosition(_sprite.getPosition().x, 800 + (_sprite.getGlobalBounds().height - _sprite.getOrigin().y));
    }




}



