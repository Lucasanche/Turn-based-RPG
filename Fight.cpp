#include "Fight.h"


Fight::Fight() {
    _backTexture = new sf::Texture;
    _menu = nullptr;
    _turn = true;
    _music = true;
    _backFlag = true;
    bufferPelea.loadFromFile("musicaPelea.wav");
    musicaPelea.setBuffer(bufferPelea);
    musicaPelea.setVolume(30);

}
// Prueba modificaciones Git

int Fight::update(sf::Sprite& background, DyvirFight& dyvir, DragonRojo& enemy, sf::RenderWindow& window)
{
    if (_backFlag) {
        switch (enemy.getBack())
        {
        case 1:
            _backTexture->loadFromFile("fondo.png");
            background.setTexture(*_backTexture);
            _menu = new MenuFight(window.getSize().x, window.getSize().y);
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
            std::cout << "Hiciste " << dyvir.doDamage() << " puntos de da�o" << std::endl << std::endl;
            _menu->setOption(0);
        }
    }
    else {
        dyvir.damageTaken(enemy.doDamage());
        std::cout << "Te hicieron " << enemy.getBaseDamage() << " puntos de da�o" << std::endl << std::endl;
        _turn = true;
       
    }
    dyvir.update();
    enemy.update();
    window.draw(background);
    window.draw(*_menu);
    
    window.draw(dyvir);
    window.draw(enemy);
    
    
    return 1;
}
