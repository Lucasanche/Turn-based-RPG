#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "DyvirFight.h"
#include "dragonAzul.h"
#include "Fight.h"
#include "Cursor.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Proyectazo");
    window.setFramerateLimit(60);
    sf::Texture backTexture;
    //backTexture.loadFromFile("fondo.png");
    sf::Sprite background;


    Fight prototype;
    Cursor cursorFight;
    dragonAzul juan;
    DyvirFight david;
    bool bpelea = true;
    sf::SoundBuffer bufferPelea;
    bufferPelea.loadFromFile("musicaPelea.wav");
    sf::Sound musicaPelea;
    musicaPelea.setBuffer(bufferPelea);
    musicaPelea.setVolume(30);
    int timer = 60 * 10;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        /*    if (timer < 0) {
                if (pelea) {
                    musicaPelea.play();
                    pelea = false;
                    timer = 60 * 24;
                }
            }*/

        window.clear();

        prototype.update(backTexture, david, juan);
        background.setTexture(backTexture);
        cursorFight.update();
        //musicaPelea.play();
        //bpelea = false;

        window.draw(background);

        if (david.getIsAlive() || juan.getIsAlive()) {

            window.draw(cursorFight);
            
            window.draw(david);
            window.draw(juan);

            if (juan.getHP() == 0) {
                david.setIsAlive(false);
            }
            if (juan.getHP() == 0) {
                david.setIsAlive(false);
            }
            window.display();
        }
        
            if (!juan.getIsAlive()) {
                //FUNCION DE GANASTE Y KABOOM
            }
            david.setHP(0);
            if (!david.getIsAlive()) {
                ///FUNCION DE PERDISTE
            }
            window.display();
        
    }
    return 0;
}


