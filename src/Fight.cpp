#include "stdafx.h"
#include "Fight.h"


Fight::Fight() : _backTexture(), _view(sf::FloatRect(0, 0, 800, 700)) {
	srand(time(0));
	_menu = nullptr;
	_turn = wait;
	_music = true;
	_backFlag = true;
	bufferPelea.loadFromFile("./Sounds/FightMusic.wav");
	musicaPelea.setBuffer(bufferPelea);
	musicaPelea.setVolume(30);
	_turnTime = true;
	_optionEnemy = 0;
}
/// implementacion original del enemigo
//EnemyFactory create;
//Enemy* enemy;
//enemy = create.getEnemy(win);

int Fight::update(DyvirFight& dyvir, sf::RenderWindow& window, sf::Clock& clock, bool enemyType) {
	_time = clock.getElapsedTime();
	if (_backFlag) {
		if (enemyType) {
			this->setBoss(dyvir.getWins());
		}
		else {
			this->setEnemy(dyvir.getWins());
		}
		if (_enemy == nullptr) {
			std::cout << "no se pudo crear el enemigo" << std::endl;
		}
		/*switch (enemy.getBack())*/
		switch (1) {
		case 1:
			_backTexture.loadFromFile("./Textures/Backgrounds/FightBackground1.png");
			_backSprite.setTexture(_backTexture);
			_menu = new MenuFight(float(window.getSize().x), float(window.getSize().y), dyvir);
			if (_menu == NULL) {
				std::cout << "No se pudo cargar el menu" << std::endl;
			}
			clock.restart();
			_backFlag = false;
			break;
		default:
			break;
		}
	}
	_menu->update(dyvir, *_enemy);
	switch (_turn) {
	case start:
		//if (_time.asSeconds() > 1.5) {
		std::cout << "Tu turno" << std::endl;
		//	_turn = wait;
		//}
		_turn = check;
		break;
	case check:
		dyvir.checkNegativeStates(_turn);
		_turn = wait;
		break;
	case wait:
		_turn = _menu->update(dyvir, *_enemy);
		break;
	case attack: //Atacar
		std::cout << "Hiciste " << _enemy->damageTaken(dyvir.doDamage(_enemy->getPD())) << " puntos de daño"  << std::endl << std::endl;
		clock.restart();
		// dyvir.doDamage(_enemy->getPD()) << " puntos de daño" 
		_turn = enemyUpdateText;
		break;
	case ability1: //Magic 1
		dyvir.useAbility(*_enemy, 0);
		_turn = enemyUpdateText;
		break;
	case ability2: //Magic 2
		_turn = enemyUpdateText;
		break;
	case ability3: //Magic 3
		break;
	case enemyUpdateText:
		//_menu->setOption(enemyWait);
		
		_turn = enemyCheck;
		break;
	case enemyCheck:
		_enemy->checkNegativeStates(_turn);
		//_turn = enemyWait;
		break;
	case enemyWait:
		if (_time.asSeconds() > 1.5) {
			if (_enemy->getHP() <= 0) {
				_turn = wait;
				break;
			}
			else {
				std::cout << "Turno del enemigo" << std::endl << std::endl;
				unsigned int random = rand() % 3;
				switch (rand() % 2) {
				case 0:
					std::cout << "Te hicieron " << dyvir.damageTaken(_enemy->doDamage(_enemy->getPD()))<<  " puntos de daño" << std::endl << std::endl;
					break;
				case 1:
					std::cout << "Te hicieron " << dyvir.damageTaken(_enemy->doDamage(_enemy->getPD())) << " puntos de daño" << std::endl << std::endl;
					break;
				case 2:
					std::cout << "Te hicieron " << dyvir.damageTaken(_enemy->doDamage(_enemy->getPD())) << " puntos de daño" << std::endl << std::endl;
					break;
				}
				_turn = updateText;
				clock.restart();
			}
		}
		break;
	case updateText:
		_turn = start;
		clock.restart();
		break;
	}
	window.setView(_view);
	dyvir.update(_enemy->getIsAlive());
	_enemy->update(dyvir.getIsAlive());
	window.draw(_backSprite);
	window.draw(*_menu);
	window.draw(*_enemy);
	window.draw(dyvir);

	return 1;
}

void Fight::setBoss(int winCheck) {
	_enemy = _enemyFactory.getBoss(winCheck);
}

void Fight::setEnemy(int winCheck) {
	_enemy = _enemyFactory.getEnemy(winCheck);
}

void Fight::deleteBoss() {
	delete _enemy;
	_enemy = nullptr;
	if (_enemy != nullptr) {
		std::cout << "No se eliminó el Boss" << std::endl;
	}
	else {
		std::cout << "Se eliminó el Boss" << std::endl;
	}
}

bool Fight::getEnemyIsAlive() {
	return _enemy->getIsAlive();
}
