#include "stdafx.h"
#include "Fight.h"

Fight::Fight() : _backTexture(), _view(sf::FloatRect(0, 0, 800, 700))
{
    srand(unsigned(time(0)));
    _menu = nullptr;
    _turn = start;
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
            _menu = new MenuFight(float(window.getSize().x), float(window.getSize().y), dyvir);
            clock.restart();
            _backFlag = false;
        default:
            break;
        }
    }
    _menu->update(dyvir.getHP(), _enemy->getHP(), _turnTime);
    switch (_turn) {
    case wait:
        _turn = turns(_menu->update(dyvir.getHP(), _enemy->getHP(), _turnTime));
        break;
    case attack: //Atacar
        _enemy->damageTaken(dyvir.doDamage(_enemy->getPD()));
        clock.restart();
        _turn = enemyUpdateText;
        _turnTime = false;
        break;
    case ability1: //Magic 1
        //dyvir.useAbility1(*_enemy);
        _turn = enemyUpdateText;
        break;
    case ability2: //Magic 2
        _turn = enemyUpdateText;
        break;
    case ability3: //Magic 3
        break;
    case enemyUpdateText:
        _menu->setOption(0);
        std::cout << "Hiciste " << dyvir.doDamage(_enemy->getPD()) << " puntos de daño" << std::endl << std::endl;
        _turn = enemyWait;
        break;
    case enemyWait:
        if (_time.asSeconds() > 1.5) {
            if (_enemy->getHP() <= 0) {
                _turn = start;
                break;
            }
            else {
                std::cout << "Turno del enemigo" << std::endl << std::endl;
                unsigned int random = rand() % 3;
                switch (rand() % 3) {
                case 1:
                    dyvir.damageTaken(_enemy->doDamage(_enemy->getPD()));
                    break;
                case 2:
                    //ability 1
                    break;
                case 3:
                    //ability 2
                    break;
                }
                _turn = updateText;
                clock.restart();
            }
            break;
    case updateText:
        if (_time.asSeconds() > 1.5) {
            std::cout << "Te hicieron " << _enemy->getPhysicalDamage() << " puntos de daño" << std::endl << std::endl;
            _turn = wait;
            clock.restart();
        }
        break;
        }
        window.setView(_view);
        dyvir.update();
        _enemy->update();
        window.draw(_backSprite);
        window.draw(*_menu);
        window.draw(dyvir);
        window.draw(*_enemy);

        return 1;
    }
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
