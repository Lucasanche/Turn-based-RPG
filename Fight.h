#pragma once
#include <SFML/Graphics.hpp>
#include "EnemyFight.h"
#include "DyvirFight.h"
class Fight
{
public:
	void update(sf::Texture&, DyvirFight&, EnemyFight&);
};



