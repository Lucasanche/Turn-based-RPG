#pragma once
#ifndef GAME_H
#define GAME_H

#include "DyvirFight.h"
#include "Fight.h"
#include "Cursor.h"
#include "mainMenu.h"
#include "Map.h"
#include "DyvirMap.h"
#include "EnemyFactory.h"

class Game
{
private:
	sf::RenderWindow _window;
	sf::Sprite _background;
	sf::Texture _backgroundTexture;
	mainMenu _mainMenu;
	Map _map;
	DyvirMap _dyvirMap;
	unsigned short _option;
	unsigned short _loadGameOption;
	sf::Clock _clock;
	sf::Time _delta_time;
public:
	Game();
	void Play();
	~Game();
	
};

#endif