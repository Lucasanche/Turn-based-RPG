#include "stdafx.h"
#include "DyvirFight.h"
#include "Fight.h"
#include "Cursor.h"
#include "Menu.h"
#include "Map.h"
#include "DyvirMap.h"
#include "EnemyFactory.h"



int main()
{
    setlocale(LC_CTYPE, "Spanish");
    sf::RenderWindow window(sf::VideoMode(800, 700), "Proyectazo");
    window.setFramerateLimit(60);
    sf::Texture backTexture;
    sf::Sprite background;
    background.setTextureRect({ 0,0,800,700 });

    //menu inicio
    Menu* menu = new Menu(float(window.getSize().x), float(window.getSize().y));
    EnemyFactory create;
    DyvirFight dyvir;
    Enemy *enemy;
    Map map;
    DyvirMap dyvirMap;
    sf::Event event;
    int option = 0;
    int optionFight = 0;
    int win = 0;
    enemy = create.getEnemy(win);

    while (window.isOpen())
    {

        while (window.pollEvent(event))
        {
            window.clear();
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
            window.clear();
            switch (option) {
                case 0:
                    menu->update();
                    backTexture.loadFromFile("menuInicio.jpg");
                    background.setTexture(backTexture);
                    window.draw(background);
                    window.draw(*menu);
                    option = menu->getOption();
                    if (option != 0) {
                        delete menu;
                        menu = nullptr;
                    }
                    break;

                case 1:
                    map.update(dyvirMap, window, dyvir, *enemy);
                    break;

                case 2:
                    break;

                case 3:
                    window.close();
                    break;
            }

            if (!enemy->getIsAlive()) {

                    sf::Texture Texture;
                    sf::Sprite Win;
                    Texture.loadFromFile("win.png");
                    Win.setTexture(Texture);
                    Win.setPosition(800 - Win.getGlobalBounds().width, 380 - Win.getGlobalBounds().height);
                    Win.setScale(1, 1);
                    //ground.setPosition(ground.getPosition().x - ground.getGlobalBounds().width / 400, ground.getPosition().y - ground.getGlobalBounds().height / 400);
                    window.draw(Win);

                }
            else if(enemy->getIsAlive() && !dyvir.getIsAlive())

            {   sf::Texture TextureLoss;
                sf::Sprite Loss;
                TextureLoss.loadFromFile("loss.png");
                Loss.setTexture(TextureLoss);
                Loss.setPosition(560 - Loss.getGlobalBounds().width, 300 - Loss.getGlobalBounds().height);
                Loss.setScale(1, 1);
                window.draw(Loss);

            }

                //FUNCION DE GANASTE Y KABOOM
            //}
            //david.setHP(0);
            //if (!david.getIsAlive()) {
                ///FUNCION DE PERDISTE
            //}
            window.display();
    }
    return 0;
}


