#include "stdafx.h"
#include "EnemyFactory.h"

///TODO: Revisar MPCost de habilidades
Enemy* EnemyFactory::getBoss(int wins) {
	switch (wins) {
	case 0:
		_enemy = new Enemy("./Textures/Characters/spritesheets/boss1 512x512-10.png", 512, 512, 10, 0.7,1); //Earth
		if (_enemy == NULL) {
			std::cout << "no se pudo crear al enemigo" << std::endl;
		}
		_enemy->setStats(1000, 500, 100, 100, 50, 50, Fire, 100);
		_enemy->setAbilityFromInventory(0, SabakuKyu);
		_enemy->setAbilityFromInventory(1, Earthquake);
		break;
	case 1:
		_enemy = new Enemy("./Textures/Characters/spritesheets/boss2 500x310.png", 500, 310, 12, 0.8, 1); //Water
		if (_enemy == NULL) {
			std::cout << "no se pudo crear al enemigo" << std::endl;
		}
		_enemy->setStats(1500, 700, 150, 150, 120, 100, Air, 300);
		_enemy->setAbilityFromInventory(0, PoisonGas);
		_enemy->setAbilityFromInventory(1, Tsunami);
		break;
	case 2:
		_enemy = new Enemy("./Textures/Characters/spritesheets/boss3 582x268-19-2.png", 582, 268, 19, 1, 2); //Fire
		if (_enemy == NULL) {
			std::cout << "no se pudo crear al enemigo" << std::endl;
		}
		_enemy->setStats(2500, 800, 200, 250, 150, 150, Water, 450);
		_enemy->setAbilityFromInventory(0, Inferno);
		_enemy->setAbilityFromInventory(1, HotVampire);
		break;
	case 3:
		_enemy = new Enemy("./Textures/Characters/spritesheets/boss4 680x556-11.png", 680, 556, 11, 0.45, 1); 
		_enemy->setStats(3500, 1000, 300, 400, 200, 300, Water, 800);
		_enemy->setAbilityFromInventory(0, MagmaWave);
		_enemy->setAbilityFromInventory(1, FireTornado);
		break;
	case 4:///TODO: HACER A KLOSTER. -> Hermano de lucas? | 3 habilidades? 
		_enemy = new Enemy("./Textures/Characters/spritesheets/KLOSTER", 174, 103, 4, 1, 1);
		_enemy->setStats(5000, 2000, 800, 800, 500, 500, Water, 1500);
		break;
	}
	return _enemy;
}

Enemy* EnemyFactory::getEnemy(int wins) {
	int _num = rand() % (wins + 2);
	std::cout << _num << std::endl;
	switch (_num) {
///BASE ENEMIES -> wins = 0 --------------------------------------------------------------------------------------------------------------------------------------
	case 0:
		_enemy = new Enemy("./Textures/Characters/spritesheets/enemy1 96x95-4.png", 96, 95, 4, 2.3, 1); //Water
		if (_enemy == nullptr) {
			std::cout << "no se pudo crear al enemigo en EnemyFactory" << std::endl;
		}				
		_enemy->setStats(700, 200, 35, 35, 30, 30, Air, 100); 
		_enemy->setAbilityFromInventory(0, Bubble);
		_enemy->setAbilityFromInventory(1, Mirror);
		break;
	case 1:
		_enemy = new Enemy("./Textures/Characters/spritesheets/enemy2 500x455-2.png", 500, 455, 2, 0.6, 1); //Air
		if (_enemy == nullptr) {
			std::cout << "no se pudo crear al enemigo en EnemyFactory" << std::endl;
		}				
		_enemy->setStats(600, 250, 50, 50, 10, 10, Earth, 100); 
		_enemy->setAbilityFromInventory(0, PoisonGas);
		_enemy->setAbilityFromInventory(1, WindBlow);
		break;
///POWER UP -> wins = 1 --------------------------------------------------------------------------------------------------------------------------------------
	case 2:
		_enemy = new Enemy("./Textures/Characters/spritesheets/enemy3 350x321-9 .png", 350, 321, 9, 0.8, 1); //Water
		if (_enemy == nullptr) {
			std::cout << "no se pudo crear al enemigo en EnemyFactory" << std::endl;
		}//(int HP, int MP, int physicalDamage, int magicDamage, int physicalDefense, int magicResist, elements elementWeak)
		_enemy->setStats(1100, 500, 80, 80, 50, 50, Earth, 200); 
		_enemy->setAbilityFromInventory(0, Bubble);
		_enemy->setAbilityFromInventory(1, WindBlow);
		break;
	case 3:
		_enemy = new Enemy("./Textures/Characters/spritesheets/enemy4 540x540-2.png", 540, 540, 2, 0.5, 1); //Air
		if (_enemy == nullptr) {
			std::cout << "no se pudo crear al enemigo en EnemyFactory" << std::endl;
		}
		_enemy->setStats(1100, 600, 80, 80, 50, 50, Earth, 150);
		_enemy->setAbilityFromInventory(0, Heal);
		_enemy->setAbilityFromInventory(1, WindBlow);
		break;
///POWER UP -> wins = 2 --------------------------------------------------------------------------------------------------------------------------------------
	case 4:
		_enemy = new Enemy("./Textures/Characters/spritesheets/enemy5 256x256-5.png", 256, 256, 5, 1, 1); //Water
		if (_enemy == nullptr) {
			std::cout << "no se pudo crear al enemigo en EnemyFactory" << std::endl;
		}//(int HP, int MP, int physicalDamage, int magicDamage, int physicalDefense, int magicResist, elements elementWeak)
		_enemy->setStats(1700, 700, 150, 80, 80, 100, Air, 300);  
		_enemy->setAbilityFromInventory(0, Bubble);
		_enemy->setAbilityFromInventory(1, Barrier);
		break;
	case 5: 
		_enemy = new Enemy("./Textures/Characters/spritesheets/enemy6 805x805-11.png", 805, 805, 11, 0.35, 1); //Fire
		if (_enemy == nullptr) {
			std::cout << "no se pudo crear al enemigo en EnemyFactory" << std::endl;
		}
		_enemy->setStats(2000, 700, 80, 100, 100, 100, Water, 350); 
		_enemy->setAbilityFromInventory(0, Fireball);
		_enemy->setAbilityFromInventory(1, FireBarrier);
		break;
///POWER UP -> wins = 3 --------------------------------------------------------------------------------------------------------------------------------------
	case 6:
		_enemy = new Enemy("./Textures/Characters/spritesheets/enemy7 174x103-4.png", 174, 103, 4, 1.5, 1); //Earth
		if (_enemy == nullptr) {
			std::cout << "no se pudo crear al enemigo en EnemyFactory" << std::endl;
		}
		_enemy->setStats(3000, 700, 150, 150, 500, 300, Fire, 500);
		_enemy->setAbilityFromInventory(0, EarthArmor);
		_enemy->setAbilityFromInventory(1, EarthBarrier);
		break;
	case 7: 
		_enemy = new Enemy("./Textures/Characters/spritesheets/enemy8 250x150-4.png", 250, 150, 4, 1, 1); //Fire
		if (_enemy == nullptr) {
			std::cout << "no se pudo crear al enemigo en EnemyFactory" << std::endl;
		}
		_enemy->setStats(2800, 800, 250, 250, 200, 200, Water, 500);
		_enemy->setAbilityFromInventory(0, Fireball);
		_enemy->setAbilityFromInventory(1, Inferno);
		break;
///POWER UP -> wins=4 --------------------------------------------------------------------------------------------------------------------------------------
	case 8: 
		_enemy = new Enemy("./Textures/Characters/spritesheets/enemy9 403x324-14.png", 403, 324, 14, 0.7, 1); //Earth
		if (_enemy == nullptr) {
			std::cout << "no se pudo crear al enemigo en EnemyFactory" << std::endl;
		}
		_enemy->setStats(3500, 1000, 400, 300, 300, 250, Fire, 650);
		_enemy->setAbilityFromInventory(0, Heal);
		_enemy->setAbilityFromInventory(1, Doton);
		break;
	case 9:
		_enemy = new Enemy("./Textures/Characters/spritesheets/enemy10 484x372-8 .png", 484, 372, 8, 0.6, 1); //Air
		if (_enemy == nullptr) {
			std::cout << "no se pudo crear al enemigo en EnemyFactory" << std::endl;
		}
		_enemy->setStats(3500, 1000, 300, 250, 500, 300, Air, 600);
		_enemy->setAbilityFromInventory(0, Restore);
		_enemy->setAbilityFromInventory(1, Swirl);
		break;
	}
	return _enemy;
}

