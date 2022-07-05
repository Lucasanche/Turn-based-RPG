#include "stdafx.h"
#include "Fight.h"


Fight::Fight() : _backTexture(), _view(sf::FloatRect(0, 0, 800, 700))
{
    _menu = nullptr;
    _turn = 0;
    _music = true;
    _backFlag = true;
    bufferPelea.loadFromFile("musicaPelea.wav");
    musicaPelea.setBuffer(bufferPelea);
    musicaPelea.setVolume(30);
    _turnTime = true;
    _optionEnemy = 0;
}
/// implementacion original del enemigo
//EnemyFactory create;
//Enemy* enemy;
//enemy = create.getEnemy(win);

int Fight::update(DyvirFight& dyvir, sf::RenderWindow& window, sf::Clock& clock)
{
    _time = clock.getElapsedTime();
    if (_backFlag) {
        this->setBoss(dyvir.getWins());
        /*switch (enemy.getBack())*/
        switch (1)
        {
        case 1:
            _backTexture.loadFromFile("fondo.png");
            _backSprite.setTexture(_backTexture);
            _menu = new MenuFight(float(window.getSize().x), float(window.getSize().y));
            clock.restart();
            _backFlag = false;
        default:
            break;
        }
    }
    _menu->update(dyvir.getHP(), _enemy->getHP(), _turnTime);
    switch (_turn) {
    case 0:
        _turn = _menu->update(dyvir.getHP(), _enemy->getHP(), _turnTime);
        break;
    case 1: //Atacar
        _enemy->damageTaken(dyvir.doDamage(_enemy->getPD()));
        std::cout << "Hiciste " << dyvir.doDamage(_enemy->getPD()) << " puntos de daño" << std::endl << std::endl;
        _turn = 5;
        clock.restart();
        _menu->setOption(0);
        _turnTime = false;
        break;
    case 2: //Magic 1

        //dyvir.useAbility1(*_enemy);


        break;
    case 3: //Magic 2
        break;
    case 4: //Magic 3
        break;
    case 5:
        if (_time.asSeconds() > 1.5) {
        if (_enemy->getHP() <= 0) {
            _turn = 0;
            break;
        }
            std::cout << "Turno del enemigo" << std::endl << std::endl;
            _turn = 6;
            clock.restart();
        }
        break;
    case 6:
        dyvir.damageTaken(_enemy->doDamage(_enemy->getPD()));
        _turn += 1;
        clock.restart();
        break;
    case 7:
        if (_time.asSeconds() > 1.5) {
            std::cout << "Te hicieron " << _enemy->getBaseDamage() << " puntos de daño" << std::endl << std::endl;
            _turn += 1;
            clock.restart();
        }
        break;
    case 8:
        if (_time.asSeconds() > 1) {
            std::cout << "Tu turno" << std::endl << std::endl;
            _turn = 0;
            _turnTime = true;
        }
        break;
    }




    //if (_turn) {
    //    switch (_menu->update(dyvir.getHP(), _enemy->getHP())) {
    //    case 0:
    //        if (_turnTime && _time.asSeconds()>1.5) {
    //            _turnTime = !_turnTime;

    //            _turn = !_turn;
    //            std::cout << "Turno del enemigo" << std::endl << std::endl;
    //            clock.restart();
    //        }
    //        break;
    //    case 1: //Atacar
    //        _enemy->damageTaken(dyvir.doDamage(_enemy->getPD()));
    //        std::cout << "Hiciste " << dyvir.doDamage(_enemy->getPD()) << " puntos de daño" << std::endl << std::endl;
    //        _menu->setOption(0);
    //        _turnTime = true;
    //        clock.restart();
    //        
    //        break;
    //    case 2: //Magic 1

    //        //dyvir.useAbility1(*_enemy);


    //        break;
    //    case 3: //Magic 2
    //        break;
    //    }

    //}
    //else {
    //    switch (_optionEnemy) {
    //    case 0:
    //        dyvir.damageTaken(_enemy->doDamage(_enemy->getPD()));
    //        std::cout << "Te hicieron " << _enemy->getBaseDamage() << " puntos de daño" << std::endl << std::endl;
    //        _optionEnemy = 1;
    //        clock.restart();
    //        break;
    //    case 1:
    //        if (_time.asSeconds() > 1.5) {
    //            std::cout << "tu turno pete" << std::endl << std::endl;
    //            _turn = !_turn;
    //            _optionEnemy = 0;
    //        }
    //        break;
    //    }
    //}
    window.setView(_view);
    dyvir.update();
    _enemy->update();
    window.draw(_backSprite);
    window.draw(*_menu);
    window.draw(dyvir);
    window.draw(*_enemy);

    return 1;
}

void Fight::setBackFlag() {
    _backFlag = true;
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
