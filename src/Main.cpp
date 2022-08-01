#include "stdafx.h"
#include "Game.h"

int main() {
	Game game;
	srand(time(0));
	setlocale(LC_ALL, ".UTF8");
	game.Play();
	return 0;
}