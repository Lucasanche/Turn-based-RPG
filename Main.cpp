#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "DyvirFight.h"
#include "dragonAzul.h"
#include "Fight.h"



int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Proyectazo");
    window.setFramerateLimit(60);
    sf::Texture backTexture;
    //backTexture.loadFromFile("fondo.png");
    sf::Sprite background;


    Fight pelea;

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
        pelea.update(backTexture, david, juan);
        background.setTexture(backTexture);

        //musicaPelea.play();
        //bpelea = false;

        window.draw(background);
        window.draw(david);
        window.draw(juan);
        window.display();
    }
	return 0;
}


