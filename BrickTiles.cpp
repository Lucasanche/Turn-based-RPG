#include "BrickTiles.h"

BrickTilesq::BrickTilesq()
{
    _texture.loadFromFile("Tilesheet.png");
    _sprite.setTexture(_texture);
}

void BrickTilesq::update(int j, int i, int x, int y)
{
    _sprite.setPosition(j*35, i*35);
    _sprite.setTextureRect(sf::IntRect(x*35, y*35, 35, 35));
    left=_sprite.getPosition().x;
    right=_sprite.getPosition().x + _sprite.getGlobalBounds().width;
    top=_sprite.getPosition().y;
    bottom=_sprite.getPosition().y + _sprite.getGlobalBounds().height;
}

void BrickTilesq::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

sf::FloatRect BrickTilesq::getBounds() const {

    return _sprite.getGlobalBounds();

}
