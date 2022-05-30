#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "DyvirFight.h"
#include "dragonAzul.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Proyectazo");
	window.setFramerateLimit(60);

	
	dragonAzul juan;
	DyvirFight david;

	sf::SoundBuffer bufferPelea;
	bufferPelea.loadFromFile("musicaPelea.wav");
	sf::Sound musicaPelea;
	musicaPelea.setBuffer(bufferPelea);
	musicaPelea.setVolume(30);
	bool pelea = true;
	int timer = 60 * 10;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		timer--;
		if (timer < 0) {
			if (pelea) {
				musicaPelea.play();
				pelea = false;
				timer = 60 * 24;
			}
		}
		


		juan.update();
		david.update();
		window.clear();
		//window.draw(background);
		window.draw(david);
		window.draw(juan);
		window.display();
	}

	return 0;
}