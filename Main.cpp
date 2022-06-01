#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "DyvirFight.h"
#include "dragonAzul.h"
#include "Fight.h"
#include <iostream>
#include "Menu.h"



int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 400), "THE DRAGON LORD!");

	Menu menu(window.getSize().x, window.getSize().y);

	sf::RectangleShape background2;
	background2.setSize(sf::Vector2f(800, 600));
	sf::Texture MenuInicio;
	MenuInicio.loadFromFile("menuInicio.jpg");
	background2.setTexture(&MenuInicio);

	
	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
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

			}
		}

		window.clear();
		window.draw(background2);
		menu.draw(window);
	
		window.display();
	}
    
   
    //sf::RenderWindow window(sf::VideoMode(800, 600), "Proyectazo");
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


