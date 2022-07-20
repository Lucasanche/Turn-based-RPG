#include "stdafx.h"
#include "Game.h"

Game::Game() : _window(sf::VideoMode(800, 700), "Proyectazo"), _mainMenu(float(_window.getSize().x), float(_window.getSize().y)), _map(_window) {
	_window.setFramerateLimit(60);
	_background.setTextureRect({ 0,0,800,700 });
	_option = 0;
}

void Game::Play() {
	while (_window.isOpen()) {
		while (_window.pollEvent(event)) {
			_window.clear();
			if (event.type == sf::Event::Closed) {
				_window.close();
			}
		}
		_window.clear();
		switch (_option) {
		case 0:
			_mainMenu.update();
			_backgroundTexture.loadFromFile("./Textures/Backgrounds/MenuInicio.jpg");
			_background.setTexture(_backgroundTexture);
			_window.draw(_background);
			_window.draw(_mainMenu);
			_option = _mainMenu.getOption();
			break;
		case 1:
			_map.update(_dyvirMap, _window);
			break;
		case 2:
			break;
		case 3:
			_window.close();
			break;
		}
		_window.display();
	}
}

Game::~Game() {
	std::cout << "Gracias por jugar a nuestro juego\n";
	std::cin;
}
