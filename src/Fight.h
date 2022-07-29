#pragma once
#ifndef FIGHT_H
#define FIGHT_H

#include "DyvirFight.h"
#include "MenuFight.h"
#include "Enemy.h"
#include "EnemyFactory.h"


class Fight
{
private:
	MenuFight* _menu;
	turns _turn;
	bool _music;
	bool _backFlag;
	sf::Time _time;
	sf::Time _timeAux;
	sf::Clock _clock;
	sf::Texture _backTexture;
	sf::Sprite _backSprite;
	sf::SoundBuffer bufferPelea;
	sf::Sound musicaPelea;
	EnemyFactory _enemyFactory;
	Enemy* _enemy;
	sf::View _view;
public:
	Fight();
	int update(DyvirFight&, sf::RenderWindow& window, sf::Clock& clock, bool enemyType);
	void setBoss(int);
	void setEnemy(int);
	void deleteBoss();
	bool getEnemyIsAlive();
	void setBackFlag() { _backFlag = true; }
};

#endif