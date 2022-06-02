#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "DyvirFight.h"
#include "dragonAzul.h"

class Fight
{
private:
    bool _turn;
    bool _music;
    sf::SoundBuffer bufferPelea;
    sf::Sound musicaPelea;
public:
    Fight();
    void update(sf::Texture&, DyvirFight&, dragonAzul&);
};



