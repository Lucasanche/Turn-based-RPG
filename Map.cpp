#include "Map.h"

Map::Map()
{
    _backTexture = new sf::Texture;
    _music = true;
    bufferPelea.loadFromFile("musicaMap.wav");
    musicaPelea.setBuffer(bufferPelea);
    musicaPelea.setVolume(30);
}

int Map::update(sf::Sprite& background, DyvirMap& DyvirMap, sf::RenderWindow& window)
{
    _backTexture->loadFromFile("fondoMapa.png");
    background.setTexture(*_backTexture);
    DyvirMap.update();
    window.draw(background);
    window.draw(DyvirMap);

    return 1;
}





