#include "stdafx.h"
#include "EnemyFactory.h"


Enemy* EnemyFactory::getBoss(int wins) {
	//TODO: Arreglar tamaños de los sprites - Juli
	switch (wins) {
	case 0:
		_enemy = new Enemy("./Textures/Characters/spritesheets/Enemy1.png", 96, 82, 4);
		if (_enemy == NULL) {
			std::cout << "no se pudo crear al enemigo" << std::endl;
		}
		_enemy->setStats(100, 100, 10, 10, 0, 0, Air);
		break;
	case 1:
		_enemy = new Enemy("./Textures/Characters/spritesheets/boss1 680x556.png", 680, 556, 11);
		break;
	case 2:
		_enemy = new Enemy("./Textures/Characters/spritesheets/boss2 500x310.png", 500, 310, 12);
		break;
	case 3:
		_enemy = new Enemy("./Textures/Characters/spritesheets/enemy9 500x380.png", 500, 380, 14);
		break;
	case 4:
		_enemy = new Enemy("./Textures/Characters/spritesheets/enemy8 174x103.png", 174, 103, 4);
		break;
	}
	return _enemy;
}

Enemy* EnemyFactory::getEnemy(int wins) {
	srand(time(0));
	int numerito = rand() % (wins + 1);
	std::cout << numerito << std::endl;

	switch (numerito) {
	case 0:
		_enemy = new Enemy("./Textures/Characters/spritesheets/Enemy1.png", 96, 82, 4);
		if (_enemy == nullptr) {
			std::cout << "no se pudo crear al enemigo en EnemyFactory" << std::endl;
		}
		_enemy->setStats(100, 100, 10, 10, 0, 0, Air);
		break;
	}

	return _enemy;
}

