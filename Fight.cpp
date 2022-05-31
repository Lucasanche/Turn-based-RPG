#include <SFML/Graphics.hpp>
#include "Fight.h"

void Fight::update(sf::Texture& backTexture, DyvirFight& dyvir, dragonAzul& enemigo)
{
	// cargar textura del background bruh
	switch (enemigo.getBack())
	{
	case 1:
	backTexture.loadFromFile("fondo.png");
	default:
		break;
	}
	dyvir.update();
	enemigo.update();
}
