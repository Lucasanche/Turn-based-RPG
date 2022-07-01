#pragma once
#ifndef FIGHT_H
#define FIGHT_H

#include "DyvirFight.h"
#include "MenuFight.h"
#include "Enemy.h"
#include "EnemyFactory.h"

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
    EnemyFactory _enemyFactory;
    Enemy* _enemy;
public:
    Fight();
    int update(DyvirFight&, sf::RenderWindow& window);
    void setBoss(int);
    void deleteBoss();
    bool getEnemyIsAlive();
};

#endif