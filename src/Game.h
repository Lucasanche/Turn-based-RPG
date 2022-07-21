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
#include "SaveGame.h"

class Game
{
private:
	sf::RenderWindow _window;
	sf::Sprite _background;
	sf::Texture _backgroundTexture;
	mainMenu _mainMenu;
	Map _map;
	DyvirMap _dyvirMap;
	sf::Event event;
	unsigned short _option;
	unsigned short _loadGameOption;
	SaveGame _saveGame;
public:
	Game();
	void Play();
	~Game();
	
};

#endif