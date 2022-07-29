#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include <string>
#include "Enemy.h"


class EnemyFactory
{
public:
	EnemyFactory() {
		_enemy = nullptr;
	}
	Enemy* getBoss(int);
	Enemy* getEnemy(int);

private:
	Enemy* _enemy;
};
#endif // ENEMYFACTORY_H