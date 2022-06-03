#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "DyvirFight.h"
#include "dragonAzul.h"
#include "Fight.h"
#include "Cursor.h"
#include "Menu.h"


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

    
    while (window.isOpen())
    {
        window.clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        switch (menu.getOption()) {
        case 0:
            menu.update();
            backTexture.loadFromFile("menuInicio.jpg");
            background.setTexture(backTexture);
            window.draw(background);
            window.draw(menu);
            window.display();
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
    }
    return 0;
}


