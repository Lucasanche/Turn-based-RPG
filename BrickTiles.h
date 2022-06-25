#ifndef BRICKTILES_H
#define BRICKTILES_H

#include "Collision.h"

class BrickTilesq : public sf::Drawable, public Collision
{
    public:
        BrickTilesq();
        void update(int, int, int, int);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        sf::FloatRect getBounds() const override;
        int getLeft(){return left;}
        int getRight(){return right;}
        int getBottom(){return bottom;}
        int getTop(){return top;}

    private:
        sf::Texture _texture;
        sf::Sprite _sprite;
        int top;
        int bottom;
        int right;
        int left;
};

#endif