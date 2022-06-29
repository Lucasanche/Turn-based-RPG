#include "EnemyFactory.h"

Enemy* EnemyFactory::getEnemy(int wins)
{
    switch(wins){

    case 0:
        enemy= new Enemy("dragonAzul.png", 96, 82, 96, 4);
        break;
    case 1:
        enemy= new Enemy("Boss1.png", 680, 556, 680, 11);
        break;
    case 2:
        enemy= new Enemy("Boss2.png", 500, 310, 500, 12);
        break;
    case 3:
        enemy= new Enemy("Enemy9.png", 500, 380, 500, 14);
        break;
    case 4:
        enemy= new Enemy("enemy8.png", 174, 103, 174, 4);
        break;
    }

    return enemy;
}

