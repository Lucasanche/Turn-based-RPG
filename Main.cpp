#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "DyvirFight.h"
#include "dragonAzul.h"
#include "Fight.h"
#include "Cursor.h"
#include "Menu.h"
#include "iostream"


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Proyectazo");
    window.setFramerateLimit(60);
    sf::Texture backTexture;
    sf::Sprite background;
    background.setTextureRect({ 0,0,800,600 });

    //menu inicio
    Menu menu(window.getSize().x, window.getSize().y);

    Fight fight;
    Cursor cursorFight;
    dragonAzul enemy;
    DyvirFight dyvir;
    sf::Event event;
    int option = 0;

    while (window.isOpen())
    {
        window.clear();
        while (window.pollEvent(event))
        {
            //window.clear();
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
            switch (option) {
            case 0:
                menu.update(event);
                backTexture.loadFromFile("menuInicio.jpg");
                background.setTexture(backTexture);
                window.draw(background);
                window.draw(menu);
                option = menu.getOption();
                

                
                break;

            case 1:
                fight.update(backTexture, dyvir, enemy);
                if (!dyvir.getIsAlive()) {
                    dyvir.Die();

                }
                background.setTexture(backTexture);
                cursorFight.update();
                window.draw(background);
                window.draw(cursorFight);
                window.draw(enemy);
                window.draw(dyvir);
                window.display();
                break;

            case 2:
                break;

            case 3:
                window.close();
            }


            //if (!juan.getIsAlive()) {
                //FUNCION DE GANASTE Y KABOOM
            //}
            //david.setHP(0);
            //if (!david.getIsAlive()) {
                ///FUNCION DE PERDISTE
            //}
            //window.display();
            window.display();
    }
    return 0;
}


