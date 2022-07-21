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
	sf::Clock _clock;
	sf::Texture _backTexture;
	sf::SoundBuffer bufferPelea;
	sf::Sound musicaPelea;
	sf::View _view;
	std::vector<std::vector<sf::Vector2i>>map;
	BrickTiles tile;
	BrickTiles _taux;
	DyvirFight _dyvirFight;
	DyvirMap _dyvirMap;
	Fight fight;
	MenuMap menuMap;
	int x, iaux, jaux, win, _option;
public:
	Map(sf::RenderWindow& window);
	void update(sf::RenderWindow& window);
};

#endif
