#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "DyvirMap.h"
#include "BrickTiles.h"
#include<string>
#include<fstream>


class Map
{
private:
    bool _music;
    sf::Texture _backTexture;
    sf::SoundBuffer bufferPelea;
    sf::Sound musicaPelea;
    sf::View _view;
    std::vector<std::vector<sf::Vector2i>>map;
    std::vector<sf::Vector2i>tempMap;
    BrickTilesq tile;

public:
    Map();
    int update(DyvirMap&, sf::RenderWindow& window);
};


