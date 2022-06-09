#include "Cursor.h"

Cursor::Cursor()
{
    _texture.loadFromFile("cursor.png");
    _sprite.setTexture(_texture);
    _sprite.setPosition(0,500);


}

void Cursor::setPosition(sf::Vector2f pos)
{
	_sprite.setPosition(pos);
}

void Cursor::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            _sprite.move(0, 50);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            _sprite.move(0, -50);
    }

    if(_sprite.getGlobalBounds().top<500){
            _sprite.setPosition(0, 500);
        }

    if(_sprite.getGlobalBounds().top+_sprite.getGlobalBounds().height>600){
            _sprite.setPosition(_sprite.getPosition().x,600+(_sprite.getOrigin().y-_sprite.getGlobalBounds().height));



    }
}

void Cursor::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}
