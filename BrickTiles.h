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
        int getLeft(){return _left;}
        int getRight(){return _right;}
        int getBottom(){return _bottom;}
        int getTop(){return _top;}

    private:
        sf::Texture _texture;
        sf::Sprite _sprite;
        int _top;
        int _bottom;
        int _right;
        int _left;
};

#endif