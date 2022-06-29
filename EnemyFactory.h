#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H
#include <string>
#include "Enemy.h"

class EnemyFactory
{
    public:
        Enemy *getEnemy(int);

    private:
        Enemy* enemy;

#endif // ENEMYFACTORY_H
