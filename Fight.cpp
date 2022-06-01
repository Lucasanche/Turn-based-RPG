#include <SFML/Graphics.hpp>
#include "Fight.h" 

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
   
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        dyvir.damageTaken(enemy.getBaseDamage());
    }
    dyvir.update();
    enemy.update();
}