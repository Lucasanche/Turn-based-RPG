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
    DyvirFight dyvir;
    Map map(window);
    DyvirMap dyvirMap;
    sf::Event event;
    int option = 0;
    int optionFight = 0;
    int win = 0;

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
                    map.update(dyvirMap, window, dyvir);
                    break;

                case 2:
                    break;
                case 3:
                    window.close();
                    break;
            }
            window.display();
    }
    return 0;
}


