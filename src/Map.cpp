#include "stdafx.h"
#include "Map.h"


Map::Map(sf::RenderWindow& window) : _view(sf::FloatRect(200, 300, 300, 250)), menuMap(window.getSize().x, window.getSize().y, _dyvirFight) {
	_music = true;
	_gameLoaded = false;
	_saveGameFlag = false;
	_enemyTypeFlag = false;
	_elapsedTime = 0;

	/*bufferPelea.loadFromFile("./Sounds/FightMusic.wav");
	musicaPelea.setBuffer(bufferPelea);*/
	/*musicaPelea.setVolume(30);*/
	//_backTexture.setColor
	_option = 0;
	std::ifstream openfile("./Docs/Mapa mejorado.txt");
	if (openfile.is_open()) {
		std::vector<char>tempMap;
		char aux;
		while (!openfile.eof()) {
			for (int i = 0; i < 3; i++) {
				openfile >> aux;
				tempMap.push_back(aux);
			}

			if (openfile.peek() == '\n') {
				map.push_back(tempMap);
				tempMap.clear();
			}
		}
		map.push_back(tempMap);
	}
}

int Map::update(sf::RenderWindow& window, int loadGameOption, sf::Time& delta_time) {
	_elapsedTime += delta_time.asSeconds();
	if (!_gameLoaded && loadGameOption != 0) {
		SaveGame _loadGame;
		if (!_loadGame.loadGame(_dyvirMap, _dyvirFight, loadGameOption)) {
			return 4;
		}
		else {
			_gameLoaded = true;
		}
	}

	switch (_option) {
	case 0:
		if (_dyvirMap.update(delta_time)) {
			_option = 1;
			_enemyTypeFlag = false;
		}
		for (int i = 0; i < map.size(); i++) {
			int k = 0;
			for (int j = 0; j < map[i].size(); j++) {
				if (k < 2) {
					_mapValue[k] = map[i][j];
					k++;
				}
				else {
					_mapValue[k] = map[i][j];
					k = 0;
					tile.update(j/3, i, _mapValue, _dyvirFight.getWins(), delta_time, window);
					//window.draw(tile);
					if (_dyvirMap.getCollidable().CheckCollision(tile.getCollidable(), 0.0f)) {
						/*if (map[i][j] > '2') {
							_option = 1;
							_enemyTypeFlag = true;
							fight.setBoss(_dyvirFight.getWins());
							window.clear();
						}
						else if (map[i][j] == '2') {
							_option = 2;
							_saveGameFlag = true;
						}*/
					}
				}
				
			}
		}
		_view.setCenter(_dyvirMap.getPosition());
		window.setView(_view);

		window.draw(_dyvirMap);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
			_option = 2;
			_saveGameFlag = false;
			window.setView(window.getDefaultView());
		}
		break;
	case 1:
		fight.update(_dyvirFight, window, delta_time, _enemyTypeFlag);
		if (_elapsedTime > 3) {
			if (!fight.getEnemyIsAlive()) {
				_elapsedTime = 0;
				fight.deleteBoss();
				_dyvirFight.setFightSprite();
				_option = 0;
			}
			else if (!_dyvirFight.getIsAlive()) {
				window.close();
				std::cout << "Moriste, juego cerrado";
				system("pause");
				_option = 0;
			}
		}
		break;
	case 2:
		menuMap.update(_dyvirFight, _saveGameFlag, _dyvirMap);
		window.setView(window.getDefaultView());
		window.draw(menuMap);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			_option = 0;
			window.setView(_view);
		}
		break;
	}
	return 1;
}
