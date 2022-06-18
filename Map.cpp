#include "Map.h"

Map::Map() : _view(sf::FloatRect(200, 200, 800, 700))
{
    _music = true;
    bufferPelea.loadFromFile("musicaMap.wav");
    musicaPelea.setBuffer(bufferPelea);
    musicaPelea.setVolume(30);
    _backTexture.loadFromFile("map.png");
}

int Map::update(sf::Sprite& background, DyvirMap& DyvirMap, sf::RenderWindow& window)
{
    DyvirMap.update();
    _view.setCenter(DyvirMap.getPosition());
    window.setView(_view);
    background.setTexture(_backTexture);
    background.setScale(2, 2);
    window.draw(background);
    window.draw(DyvirMap);
 


    return 1;
}





