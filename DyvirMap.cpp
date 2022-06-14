#include "DyvirMap.h"

void DyvirMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

void DyvirMap::update()
{
    _frame += 0.075;
    if (_frame >= 5) {
        _frame = 0;
    }
    _sprite.setTextureRect({ int(_frame) * 222, 0, 222, 169 });
}

DyvirMap::DyvirMap()
{
    _texture.loadFromFile("dyvirMap.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({ 0, 0, 222, 169 });
    _sprite.setScale(0.5, 0.5);
    _sprite.setPosition(1, 1 - _sprite.getGlobalBounds().height);

    _frame = 0;

}
