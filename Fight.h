#pragma once
#ifndef FIGHT_H
#define FIGHT_H

#include "DyvirFight.h"
#include "MenuFight.h"

class Fight
{
private:
    MenuFight* _menu;
    bool _turn;
    bool _music;
    bool _backFlag;
    sf::Texture _backTexture;
    sf::Sprite _backSprite;
    sf::SoundBuffer bufferPelea;
    sf::Sound musicaPelea;


public:
    Fight();
    int update(DyvirFight&, Dragon&, sf::RenderWindow& window);
};

#endif