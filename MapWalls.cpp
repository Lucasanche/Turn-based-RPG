#include "stdafx.h"
#include "MapWalls.h"

MapWalls::MapWalls(int x, int y)
{
    _texture.loadFromFile("castle.png");
    _sprite.setTexture(_texture);
    _sprite.setPosition(x, y);
}

void MapWalls::draw(sf::RenderTarget& target, sf::RenderStates states)const {

    target.draw(_sprite, states);


}

sf::FloatRect MapWalls::getBounds() const {

    return _sprite.getGlobalBounds();
}