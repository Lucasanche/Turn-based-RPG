#include <SFML/Graphics.hpp>
#include "Fight.h"


Fight::Fight() {
    _turn = true;
    _music = true;
    bufferPelea.loadFromFile("musicaPelea.wav");
    musicaPelea.setBuffer(bufferPelea);
    musicaPelea.setVolume(30);

}

//void Fight::setOption(int option) {
//    _option = option;
//}

int Fight::update(sf::Texture& backTexture, DyvirFight& dyvir, dragonAzul& enemy, int option)
{
    
    switch (enemy.getBack())
    {
    case 1:
        backTexture.loadFromFile("fondo.png");
    default:
        break;
    }
    if (_turn) {
        switch (option) {
        case 1:
            enemy.damageTaken(dyvir.doDamage());
            _turn = false;
            std::cout << "Hiciste " << dyvir.doDamage() << " puntos de daño" << std::endl << std::endl;
            option = 0;
        }
    }
    else {
        dyvir.damageTaken(enemy.doDamage());
        std::cout << "Te hicieron " << enemy.getBaseDamage() << " puntos de daño" << std::endl << std::endl;
        _turn = true;
       
    }
    

    if (_turn) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            
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
    return option;
}
