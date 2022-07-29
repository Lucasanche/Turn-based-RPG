#include "stdafx.h"
#include "Fight.h"


Fight::Fight() : _backTexture(), _view(sf::FloatRect(0, 0, 800, 700)), _enemyFactory() {
	_enemy = nullptr;
	_menu = nullptr;
	_turn = start;
	_music = true;
	_backFlag = true;
	bufferPelea.loadFromFile("./Sounds/FightMusic.wav");
	musicaPelea.setBuffer(bufferPelea);
	musicaPelea.setVolume(30);
}


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

		//Setea el background para la pelea 
		switch (1) {
		case 1:
			_backTexture.loadFromFile("./Textures/Backgrounds/FightBackground1.png");
			_backSprite.setTexture(_backTexture);
			_menu = new MenuFight(float(window.getSize().x), float(window.getSize().y), dyvir);
			if (_menu == NULL) {
				std::cout << "No se pudo cargar MenuFight" << std::endl;
			}
			clock.restart();
			_backFlag = false;
			break;
		default:
			break;
		}
	}
	else {
		window.draw(_backSprite);
		window.draw(*_menu);
	}
	//void updateSpriteStatesDyvir(std::vector <bool> _positiveStates, std::vector <bool> _negativeStates, sf::RenderTarget& target);

	_menu->update(dyvir, *_enemy);
	switch (_turn) {
	case start:
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
		_menu->setTextBoxString(_turn, _enemy->damageTaken(dyvir.doDamage(_enemy->getPRmultiplier())));
		clock.restart();
		_enemy->checkHP();
		_turn = enemyUpdateText;
		break;
	case ability1: //Magic 1
		dyvir.useAbility(*_enemy, 0);
		_turn = enemyUpdateText;
		_enemy->checkHP();
		break;
	case ability2: //Magic 2
		dyvir.useAbility(*_enemy, 1);
		_turn = enemyUpdateText;
		_enemy->checkHP();
		break;
	case ability3: //Magic 3
		dyvir.useAbility(*_enemy, 2);
		_enemy->checkHP();
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
		if (_time.asSeconds() > 1.5){
			if (_enemy->getHP() <= 0) {
				//_turn = endBattle;
				break;
			}
			else {
				std::cout << "Turno del enemigo" << std::endl << std::endl;
				unsigned int random = rand() % 3;
				switch (rand() % 2) {
				case 0:
					_turn = enemyAttack;
					_menu->setTextBoxString(_turn, dyvir.damageTaken(_enemy->doDamage(_enemy->getPRmultiplier())));
					dyvir.checkHP();
					break;
				case 1:
					_turn = ability1;
					//_menu->setTextBoxString();
					_enemy->useAbility(dyvir, 0);
					dyvir.checkHP();
					break;
				case 2:
					_turn = ability2;
					//_menu->setTextBoxString(_turn, dyvir.damageTaken(_enemy->doDamage(_enemy->getMRmultiplier())));
					_enemy->useAbility(dyvir, 1);
					dyvir.checkHP();
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
	dyvir.update(_enemy->getIsAlive(), _enemy->getXP());
	if (!_enemy->getIsAlive()) {
		if (rand() % 3 == 0) {
			dyvir.getAbilityDrop(_enemy->getAbility(0).getID());
		}
		_turn = start;
	}
	_enemy->update(dyvir.getIsAlive(), 1);
	dyvir.updateSpriteStates(window);
	_enemy->updateSpriteStates(window);
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

