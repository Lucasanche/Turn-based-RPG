#include "stdafx.h"
#include "Game.h"

int main() {
	//Game game;
	srand(time(0));
	std::cout << "string " << sizeof(std::string) << "\n";
	std::cout << "text " << sizeof(sf::Text) << "\n";
	std::cout << "game " << sizeof(Game) << "\n";
	std::cout << "abilityname " << sizeof(MenuFight) << "\n";
	setlocale(LC_ALL, "Spanish");
	//game.Play();
	return 0;
}