#include <SFML/Graphics.hpp>
#include "Fight.h"

Fight::Fight() {
    _turn = true;
    _music = true;
    bufferPelea.loadFromFile("musicaPelea.wav");
    musicaPelea.setBuffer(bufferPelea);
    musicaPelea.setVolume(30);

}

void Fight::update(sf::Texture& backTexture, DyvirFight& dyvir, dragonAzul& enemy)
{
    if (_music) {
        musicaPelea.play();
        _music = false;
    }

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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            dyvir.damageTaken(enemy.doDamage());
            _turn = true;
        }
    }

   
    
    



    dyvir.update();
    enemy.update();
}
