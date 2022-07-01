#ifndef BRICKTILES_H
#define BRICKTILES_H

#include "Collision.h"

class BrickTiles : public sf::Drawable, public Collision
{
    public:
        BrickTiles();
        void update(int, int, int, int);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        sf::FloatRect getBounds() const override;
    private:
        sf::Texture _texture;
        sf::Sprite _sprite;
        int _top, _left, _right, _bottom;
};

#endif