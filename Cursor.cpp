#include "Cursor.h"

Cursor::Cursor()
{
    _texture.loadFromFile("cursor.png");
    _sprite.setTexture(_texture);
    _sprite.setPosition(0,0);
}

void Cursor::setPosition(sf::Vector2f pos)
{
	_sprite.setPosition(pos);
}

void Cursor::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
       // if (_key) {
            _sprite.move(0, 15);
           // _key = false;
        //}
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      //  if (_key) {
            _sprite.move(0, -15);
            //_key = false;
       // }
    }
    _key = true;


}

void Cursor::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}
