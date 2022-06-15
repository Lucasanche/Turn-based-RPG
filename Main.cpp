#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "iostream"
#include "DyvirFight.h"
#include "dragonAzul.h"
#include "Fight.h"
#include "Cursor.h"
#include "Menu.h"
#include "Map.h"
#include "DyvirMap.h"




int main()
{
    setlocale(LC_CTYPE, "Spanish");
    sf::RenderWindow window(sf::VideoMode(800, 700), "Proyectazo");
    window.setFramerateLimit(60);
    sf::Texture backTexture;
    sf::Sprite background;
    background.setTextureRect({ 0,0,800,700 });

    //menu inicio
    Menu *menu = new Menu(window.getSize().x, window.getSize().y);
    Fight fight;
    dragonAzul enemy;
    DyvirFight dyvir;
    Map map;
    DyvirMap dyvirMap;
    sf::Event event;
    int option = 0, dead=60;
    int optionFight = 0;

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
                    
                   fight.update(background, dyvir, enemy, window);
                    //if (!dyvir.getIsAlive()) {
                    //        dyvir.Die();
                    //}
                    /*if (!enemy.getIsAlive()) {
                        enemy.Die();
                    }*/
                    //background.setTexture(backTexture);
                    /*window.draw(background);
                    window.draw(enemy);
                    window.draw(dyvir);*/
                    //window.draw(m);


                    break;

                case 2:
                    map.update(background, dyvirMap, window);
                    break;

                case 3:
                    window.close();
                    break;
            }

            //if (!juan.getIsAlive()) {
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


