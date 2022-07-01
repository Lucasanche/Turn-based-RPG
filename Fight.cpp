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
/// implementacion original del enemigo
//EnemyFactory create;
//Enemy* enemy;
//enemy = create.getEnemy(win);

int Fight::update(DyvirFight& dyvir, sf::RenderWindow& window)
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
        switch (_menu->update(dyvir.getHP(), _enemy->getHP())) {
        case 1: //Atacar
            _enemy->damageTaken(dyvir.doDamage(_enemy->getPD()));
            _turn = false;
            std::cout << "Hiciste " << dyvir.doDamage(_enemy->getPD()) << " puntos de daño" << std::endl << std::endl;
            _menu->setOption(0);
            break;
        case 2: //Magic 1

            //dyvir.useAbility1(*_enemy);


            break;
        case 3: //Magic 2
            break;
        }
    }
    else {
        dyvir.damageTaken(_enemy->doDamage(_enemy->getPD()));
        std::cout << "Te hicieron " << _enemy->getBaseDamage() << " puntos de daño" << std::endl << std::endl;
        _turn = true;
    }
    window.setView(view);
    dyvir.update();
    _enemy->update();
    window.draw(_backSprite);
    window.draw(*_menu);
    window.draw(dyvir);
    window.draw(*_enemy);

    return 1;
}

void Fight::setBoss(int winCheck)
{
    _enemy = _enemyFactory.getBoss(winCheck);
}

void Fight::deleteBoss() {
    delete _enemy;
    _enemy = nullptr;
    if (_enemy != nullptr) {
        std::cout << "no se borró el chobi hefe" << std::endl;
    }
    else {
        std::cout << "sise murió el chobi hefe" << std::endl;
    }
}

bool Fight::getEnemyIsAlive()
{
    return _enemy->getIsAlive();
}
