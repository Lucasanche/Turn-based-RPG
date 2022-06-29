#include "stdafx.h"
#include "Fight.h"


Fight::Fight() : _backTexture()
{
    _menu = nullptr;
    _turn = true;
    _music = true;
    _backFlag = true;
    bufferPelea.loadFromFile("musicaPelea.wav");
    musicaPelea.setBuffer(bufferPelea);
    musicaPelea.setVolume(30);
}

int Fight::update(DyvirFight& dyvir, Dragon& enemy, sf::RenderWindow& window)
{
    sf::View view(sf::FloatRect(0, 0, 800, 700));
    if (_backFlag) {
        /*switch (enemy.getBack())*/
        switch (1)
        {
        case 1:
            _backTexture.loadFromFile("fondo.png");
            _backSprite.setTexture(_backTexture);
            _menu = new MenuFight(float(window.getSize().x), float(window.getSize().y));
            _backFlag = false;
        default:
            break;
        }
    }

    if (_turn) {
        switch (_menu->update(dyvir.getHP(), enemy.getHP())) {
        case 1:
            enemy.damageTaken(dyvir.doDamage());
            _turn = false;
            std::cout << "Hiciste " << dyvir.doDamage() << " puntos de daño" << std::endl << std::endl;
            _menu->setOption(0);
        }
    }
    else {
        dyvir.damageTaken(enemy.doDamage());
        std::cout << "Te hicieron " << enemy.getBaseDamage() << " puntos de daño" << std::endl << std::endl;
        _turn = true;

    }
    window.setView(view);
    dyvir.update();
    enemy.update();
    window.draw(_backSprite);
    window.draw(*_menu);
    window.draw(dyvir);
    window.draw(enemy);


    return 1;
}
