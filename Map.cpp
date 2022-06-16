#include "Map.h"

Map::Map()
{
    _backTexture = new sf::Texture;
    _music = true;
    bufferPelea.loadFromFile("musicaMap.wav");
    musicaPelea.setBuffer(bufferPelea);
    musicaPelea.setVolume(30);
    _backTexture->loadFromFile("map.png");
}

int Map::update(sf::Sprite& background, DyvirMap& DyvirMap, sf::RenderWindow& window)
{
    background.setTexture(*_backTexture);
    background.setScale(2, 2);
    DyvirMap.update();
    window.draw(background);
    window.draw(DyvirMap);

    return 1;
}





