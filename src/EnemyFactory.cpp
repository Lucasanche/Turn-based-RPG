#include "stdafx.h"
#include "EnemyFactory.h"


Enemy* EnemyFactory::getBoss(int wins) {
	switch (wins) {
	case 0:
		_enemy = new Enemy("./Textures/Characters/spritesheets/boss1 512x512-10.png", 512, 512, 10, 0.7,1);
		if (_enemy == NULL) {
			std::cout << "no se pudo crear al enemigo" << std::endl;
		}
		_enemy->setStats(100, 100, 10, 10, 0, 0, Fire);
		break;
	case 1:
		_enemy = new Enemy("./Textures/Characters/spritesheets/boss2 500x310.png", 500, 310, 12, 0.8, 1);
		if (_enemy == NULL) {
			std::cout << "no se pudo crear al enemigo" << std::endl;
		}
		_enemy->setStats(100, 100, 10, 10, 0, 0, Air);
		break;
	case 2:
		_enemy = new Enemy("./Textures/Characters/spritesheets/boss3 582x268-19-2.png", 582, 268, 19, 1, 2);
		if (_enemy == NULL) {
			std::cout << "no se pudo crear al enemigo" << std::endl;
		}
		_enemy->setStats(100, 100, 10, 10, 0, 0, Water);
		break;
	case 3:
		_enemy = new Enemy("./Textures/Characters/spritesheets/boss4 680x556-11.png", 680, 556, 11, 0.45, 1);
		_enemy->setStats(100, 100, 10, 10, 0, 0, Water);
		break;
	case 4:///TODO: HACER A KLOSTER
		_enemy = new Enemy("./Textures/Characters/spritesheets/KLOSTER", 174, 103, 4, 1, 1);
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
		_enemy = new Enemy("./Textures/Characters/spritesheets/enemy1 96x95-4.png", 96, 95, 4, 2.3, 1); //Water
		if (_enemy == nullptr) {
			std::cout << "no se pudo crear al enemigo en EnemyFactory" << std::endl;
		}
		_enemy->setStats(100, 120, 10, 15, 0, 0, Air); 
		//_enemy->setAbilities()
		break;
	case 1:
		_enemy = new Enemy("./Textures/Characters/spritesheets/enemy2 500x455-2.png", 500, 455, 2, 0.6, 1); //Air
		if (_enemy == nullptr) {
			std::cout << "no se pudo crear al enemigo en EnemyFactory" << std::endl;
		}
		_enemy->setStats(100, 100, 10, 10, 0, 0, Earth); 
		break;
	case 2:
		_enemy = new Enemy("./Textures/Characters/spritesheets/enemy3 350x321-9 .png", 350, 321, 9, 0.8, 1); //Water
		if (_enemy == nullptr) {
			std::cout << "no se pudo crear al enemigo en EnemyFactory" << std::endl;
		}
		_enemy->setStats(100, 100, 10, 10, 0, 0, Earth); 
		break;
	case 3:
		_enemy = new Enemy("./Textures/Characters/spritesheets/enemy4 540x540-2.png", 540, 540, 2, 0.5, 1); //Air
		if (_enemy == nullptr) {
			std::cout << "no se pudo crear al enemigo en EnemyFactory" << std::endl;
		}
		_enemy->setStats(100, 100, 10, 10, 0, 0, Earth); 
		break;
	case 4:
		_enemy = new Enemy("./Textures/Characters/spritesheets/enemy5 256x256-5.png", 256, 256, 5, 1, 1); //Water
		if (_enemy == nullptr) {
			std::cout << "no se pudo crear al enemigo en EnemyFactory" << std::endl;
		}
		_enemy->setStats(100, 100, 10, 10, 0, 0, Air); 
		break;
	case 5: ///TODO: Mejorar imagen - Juli (NO IMPORTANTE)
		_enemy = new Enemy("./Textures/Characters/spritesheets/enemy6 805x805-11.png", 805, 805, 11, 0.35, 1); //Earth
		if (_enemy == nullptr) {
			std::cout << "no se pudo crear al enemigo en EnemyFactory" << std::endl;
		}
		_enemy->setStats(100, 100, 10, 10, 0, 0, Air); 
		break;
	case 6:
		_enemy = new Enemy("./Textures/Characters/spritesheets/enemy7 174x103-4.png", 174, 103, 4, 1.5, 1); //Fire
		if (_enemy == nullptr) {
			std::cout << "no se pudo crear al enemigo en EnemyFactory" << std::endl;
		}
		_enemy->setStats(100, 100, 10, 10, 0, 0, Air);
		break;
	case 7: ///TODO: Mejorar imagen - Juli (NO IMPORTANTE)
		_enemy = new Enemy("./Textures/Characters/spritesheets/enemy8 250x150-4.png", 250, 150, 4, 1, 1); //Fire
		if (_enemy == nullptr) {
			std::cout << "no se pudo crear al enemigo en EnemyFactory" << std::endl;
		}
		_enemy->setStats(100, 100, 10, 10, 0, 0, Air);
		break;
	case 8: 
		_enemy = new Enemy("./Textures/Characters/spritesheets/enemy9 403x324-14.png", 403, 324, 14, 0.7, 1); //Earth
		if (_enemy == nullptr) {
			std::cout << "no se pudo crear al enemigo en EnemyFactory" << std::endl;
		}
		_enemy->setStats(100, 100, 10, 10, 0, 0, Air);
		break;
	case 9:
		_enemy = new Enemy("./Textures/Characters/spritesheets/enemy10 484x372-8 .png", 484, 372, 8, 0.6, 1); //Air
		if (_enemy == nullptr) {
			std::cout << "no se pudo crear al enemigo en EnemyFactory" << std::endl;
		}
		_enemy->setStats(100, 100, 10, 10, 0, 0, Air);
		break;
	}

	return _enemy;
}

