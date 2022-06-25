#pragma once
#ifndef FIGHT_H
#define FIGHT_H

#include "DyvirFight.h"
#include "dragonAzul.h"
#include "Boss1.h"
#include "MenuFight.h"
#include "DragonRojo.h"

class Fight
{
private:
    MenuFight* _menu;
    bool _turn;
    bool _music;
    bool _backFlag;
    sf::Texture _backTexture;
    sf::SoundBuffer bufferPelea;
    sf::Sound musicaPelea;
    
public:
    Fight();
    int update(sf::Sprite&, DyvirFight&, Dragon&, sf::RenderWindow& window);
};

#endif