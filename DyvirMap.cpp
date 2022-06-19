#include "DyvirMap.h"


DyvirMap::DyvirMap()
{

    _texture.loadFromFile("dyvirMap.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({ 0, 0, 183, 169 });
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
    _sprite.setScale(0.5, 0.5);
    _sprite.setPosition(85, 480 - _sprite.getGlobalBounds().height);
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
    _sprite.setTextureRect({ int(_frame) * 222, 0, 183, 169 });


    /// MOV
    _velocity = { 0, 0 };
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        _velocity.y = -5;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        _velocity.y = 5;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        _velocity.x = -5;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        _velocity.x = 5;
    }

    ///EVITAR QUE SALGA DE LA PANTALLA!!!!!!!!!!!!!!;;;


    ///QUE MIRE A LOS LADOS
    _sprite.move(_velocity);
    if (_velocity.x < 0) {
        _sprite.setScale(-0.5, 0.5);
    }
    if(_velocity.x > 0) {
        _sprite.setScale(0.5, 0.5);
    }

    ///EVITAR QUE SALGA DE LA PANTALLA;;;
    if(_sprite.getGlobalBounds().left<0){
            _sprite.setPosition(0 + _sprite.getGlobalBounds().width/2, _sprite.getPosition().y);
            std::cout << _sprite.getGlobalBounds().width << std::endl;
        }
    if(_sprite.getGlobalBounds().top<0){
            _sprite.setPosition(_sprite.getPosition().x, 0 + _sprite.getGlobalBounds().height);
        }

    if(_sprite.getGlobalBounds().left+_sprite.getGlobalBounds().width>1400){
            _sprite.setPosition(1400 - _sprite.getGlobalBounds().width/2, _sprite.getPosition().y);
        }
    if(_sprite.getGlobalBounds().top+_sprite.getGlobalBounds().height>1400){
            _sprite.setPosition(_sprite.getPosition().x,1400);
            std::cout << _sprite.getGlobalBounds().height << std::endl;
        }
}