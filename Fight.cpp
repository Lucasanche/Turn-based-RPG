#include <SFML/Graphics.hpp>
#include "Fight.h"

Fight::Fight() {
    _turn = true;
}

void Fight::update(sf::Texture& backTexture, DyvirFight& dyvir, dragonAzul& enemy)
{
    // cargar textura del background bruh
    switch (enemy.getBack())
    {
    case 1:
        backTexture.loadFromFile("fondo.png");
    default:
        break;
    }

    if (_turn) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            enemy.damageTaken(dyvir.doDamage());
            _turn = false;
        }
    }
    else {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            dyvir.damageTaken(enemy.doDamage());
            _turn = true;
        }
    }
   
    
    



    dyvir.update();
    enemy.update();
}
