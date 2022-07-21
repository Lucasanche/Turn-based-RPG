#include "stdafx.h"
#include "Map.h"


Map::Map(sf::RenderWindow& window) : _view(sf::FloatRect(200, 300, 300, 250)), menuMap(window.getSize().x, window.getSize().y, _dyvirFight) {
	_music = true;
	_gameLoaded = false;
	bufferPelea.loadFromFile("./Sounds/FightMusic.wav");
	musicaPelea.setBuffer(bufferPelea);
	musicaPelea.setVolume(30);
	_backTexture.loadFromFile("./Textures/Backgrounds/Dungeon.png");
	x = iaux = jaux = win = 0;
	std::ifstream openfile("./Docs/Mapa.txt");
	_option = 0;
	
	if (openfile.is_open()) {
		std::vector<sf::Vector2i>tempMap;
		while (!openfile.eof()) {
			std::string str;
			openfile >> str;
			char x = str[0], y = str[2];
			tempMap.push_back(sf::Vector2i(x - '0', y - '0'));
			if (openfile.peek() == '\n') {
				map.push_back(tempMap);
				tempMap.clear();
			}
		}
		map.push_back(tempMap);
	}
}

int Map::update(sf::RenderWindow& window, int loadGameOption) {
	if (!_gameLoaded && loadGameOption != 0) {
		SaveGame _loadGame;
		if (!_loadGame.loadGame(_dyvirMap, _dyvirFight, loadGameOption)) {
			return 0;
		}
	}
	switch (_option) {
	case 0:
		if (_dyvirMap.update()) {
			_option = 0;
		}
		for (int i = 0; i < map.size(); i++) {
			for (int j = 0; j < map[i].size(); j++) {
				if (map[i][j].x == 0 || map[i][j].y == 0) {
					tile.update(j, i, map[i][j].x, map[i][j].y);
					window.draw(tile);
					if (_dyvirMap.isCollision(tile)) {
						_dyvirMap.setCollide();
						if (map[i][j].x == 1) {
							_option = 2;
							fight.setBoss(_dyvirFight.getWins());
							window.clear();
						}
						else if (map[i][j].x == 2) {
							_option = 6;
						}
						iaux = i;
						jaux = j;
					}
				}
			}
		}
		_view.setCenter(_dyvirMap.getPosition());
		window.setView(_view);
		window.draw(_dyvirMap);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
			_option = 2;
			window.setView(window.getDefaultView());
			//_view.setSize(window.getSize().x, window.getSize().y);
		}
		break;
	case 1:
		fight.update(_dyvirFight, window, _clock, true);
		if (!fight.getEnemyIsAlive()) {
			_clock.restart();
			_option = 2;
		}
		else if (!_dyvirFight.getIsAlive()) {
			_option = 2;
		}
		break;
	case 2:
		fight.update(_dyvirFight, window, _clock, true);
		if (_clock.getElapsedTime().asSeconds() > 3) {
			if (!fight.getEnemyIsAlive()) {
				//TODO: debe tomar la cantidad de wins para cambiar el tile especial
				map[iaux][jaux].x = 9;
				map[iaux][jaux].y = 9;
				x = 9;
				//_taux = tile;
				_dyvirFight.increaseWins();
				_option = 0;
				_dyvirFight.setFightSprite();
				fight.setBackFlag();
				fight.deleteBoss();
			}
			if (!_dyvirFight.getIsAlive()) {
				window.close();
				std::cout << "Cagaste fuego";
				system("pause");
				_option = 0;
			}
		}
		break;
	case 3:
		fight.update(_dyvirFight, window, _clock, false);
		if (!fight.getEnemyIsAlive()) {
			_clock.restart();
			_option = 4;
		}
		else if (!_dyvirFight.getIsAlive()) {
			_option = 4;
		}
		break;
	case 4:
		fight.update(_dyvirFight, window, _clock, true);
		if (_clock.getElapsedTime().asSeconds() > 3) {
			if (!fight.getEnemyIsAlive()) {
				_option = 0;
				_dyvirFight.setFightSprite();
				fight.setBackFlag();
				fight.deleteBoss();
			}
			if (!_dyvirFight.getIsAlive()) {
				window.close();
				std::cout << "Cagaste fuego";
				system("pause");
				_option = 0;
			}
		}
		break;
	case 5:
		menuMap.update(_dyvirFight, false, _dyvirMap);
		window.draw(menuMap);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			_option = 0;
			window.setView(_view);
			//_view.setSize(window.getSize().x, window.getSize().y);
		}
		break;
	case 6:
		window.setView(window.getDefaultView());
		menuMap.update(_dyvirFight, true, _dyvirMap);
		window.draw(menuMap);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			_option = 0;
			window.setView(_view);
			//_view.setSize(window.getSize().x, window.getSize().y);
		}
		break;
	}
	return 2;
}
