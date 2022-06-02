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

   /* while(wait){
        if (turno%2==0){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            dyvir.damageTaken(enemy.doDamage());
            wait = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        dyvir.damageTaken(enemy.doDamage());
        if ((turno%2!=0)) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            enemy.damageTaken(dyvir.doDamage());
            wait=false;
                }

            }
        }
        }*/
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            dyvir.damageTaken(enemy.doDamage());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            enemy.damageTaken(dyvir.doDamage());

        }



    dyvir.update();
    enemy.update();
}
