#include "stdafx.h"
#include "BrickTiles.h"

BrickTiles::BrickTiles()
{
    _texture.loadFromFile("Tilesheet.png");
    _sprite.setTexture(_texture);
}

void BrickTiles::update(int j, int i, int x, int y)
{
    _sprite.setPosition(j*35, i*35);
    _sprite.setTextureRect(sf::IntRect(x*35, y*35, 35, 35));
    _left = _sprite.getPosition().x;
    _right = _sprite.getPosition().x + _sprite.getGlobalBounds().width;
    _top = _sprite.getPosition().y;
    _bottom = _sprite.getPosition().y + _sprite.getGlobalBounds().height;
}

void BrickTiles::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

sf::FloatRect BrickTiles::getBounds() const 
{
    return _sprite.getGlobalBounds();
}