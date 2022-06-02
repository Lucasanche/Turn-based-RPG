#pragma once
#include <SFML/Graphics.hpp>
#include "DyvirFight.h"
#include "dragonAzul.h"

class Fight
{
private:
    bool _turn;
public:
    Fight();
    void update(sf::Texture&, DyvirFight&, dragonAzul&);
};



