#pragma once
#include "DyvirFight.h"
#include "Fight.h"
#include "Cursor.h"
#include "Menu.h"
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
	Menu _mainMenu;
	Map _map;
	DyvirMap _dyvirMap;
	sf::Event event;
	int _option;
public:
	Game();
	void Play();
	~Game();
	
};

