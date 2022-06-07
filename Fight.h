#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "DyvirFight.h"
#include "dragonAzul.h"
#include <iostream>

class Fight
{
private:
    bool _turn;
    bool _music;
    sf::SoundBuffer bufferPelea;
    sf::Sound musicaPelea;
public:
    Fight();
    int update(sf::Texture&, DyvirFight&, dragonAzul&, int option);
    //void setOption(int option);
};



