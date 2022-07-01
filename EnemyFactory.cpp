#include "stdafx.h"
#include "EnemyFactory.h"

Enemy* EnemyFactory::getBoss(int wins)
{
    switch(wins){

    case 0:
        _enemy= new Enemy("dragonAzul.png", 96, 82, 4);
        _enemy->setStats(100, 10, Air, 0, 0);
        break;
    case 1:
        _enemy= new Enemy("Boss1.png", 680, 556, 11);
        break;
    case 2:
        _enemy= new Enemy("Boss2.png", 500, 310, 12);
        break;
    case 3:
        _enemy= new Enemy("Enemy9.png", 500, 380, 14);
        break;
    case 4:
        _enemy= new Enemy("enemy8.png", 174, 103, 4);
        break;
    }
    return _enemy;
}

