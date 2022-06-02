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
    //backTexture.loadFromFile("fondo.png");
    sf::Sprite background;
    int turno=0;

    //menu inicio
    Menu menu(window.getSize().x, window.getSize().y);
    sf::RectangleShape background2;
    background2.setSize(sf::Vector2f(800, 600));
    sf::Texture MenuInicio;
    MenuInicio.loadFromFile("menuInicio.jpg");
    background2.setTexture(&MenuInicio);

    Fight fight;
    Cursor cursorFight;
    dragonAzul enemy;
    DyvirFight dyvir;
    bool bpelea = true;
    sf::SoundBuffer bufferPelea;
    bufferPelea.loadFromFile("musicaPelea.wav");
    sf::Sound musicaPelea;
    musicaPelea.setBuffer(bufferPelea);
    musicaPelea.setVolume(30);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        switch (menu.getOption()) {
        case 0:
            
            window.clear();
            menu.update();
            window.draw(background2);
            window.draw(menu);
            window.display();
            break;

        case 1:
            window.clear();
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

            



           /* switch (event.type)
            {
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;

                case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;

                case sf::Keyboard::Return:
                    switch (menu.GetPressedItem())
                    {
                    case 0:
                        std::cout << "Play button has been pressed" << std::endl;
                        break;
                    case 1:
                        std::cout << "Option button has been pressed" << std::endl;
                        break;
                    case 2:
                        window.close();
                        break;
                    }

                    break;
                }

                break;
            case sf::Event::Closed:
                window.close();

                break;

            }*/

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


