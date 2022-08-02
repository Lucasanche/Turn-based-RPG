#pragma once
#ifndef MAP_H
#define MAP_H

#include "DyvirMap.h"
#include "BrickTiles.h"
#include "Dyvirfight.h"
#include "Fight.h"
#include "Enemy.h"
#include "MenuMap.h"


class Map
{
private:
	bool _music;
	float _elapsedTime;
	sf::SoundBuffer bufferPelea;
	sf::Sound musicaPelea;
	sf::View _view;
	std::vector<std::vector<char>>map;
	BrickTiles tile;
	DyvirFight _dyvirFight;
	DyvirMap _dyvirMap;
	Fight fight;
	MenuMap menuMap;
	int _option;
	bool _gameLoaded;
	bool _saveGameFlag;
	bool _enemyTypeFlag;
	char _mapValue[3];
public:
	Map(sf::RenderWindow& window);
	int update(sf::RenderWindow& window, int loadGameOption, sf::Time &delta_time);
};

#endif

