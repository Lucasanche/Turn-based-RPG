#include "stdafx.h"
#include "mainMenu.h"


mainMenu::mainMenu(float width, float height) : _menu(3) {
	_flag = true;
	_option = 0;
	if (!_font.loadFromFile("./Fonts/Nostalgia.ttf")) {
		std::cout << "No se pudo cargar archivo ./Fonts/Nostalgia.ttf" << std::endl;
	}
	for (int i = 0; i < _menu.size(); i++) {
		_menu[i].setFont(_font);
		_menu[i].setPosition(sf::Vector2f(width / 2, height / (_menu.size() + 1) * (1+i)));
		_menu[i].setFillColor(sf::Color::White);
	}
	_menu[0].setFillColor(sf::Color::Red);
	_menu[0].setString("Play");
	_menu[1].setString("Load Game");
	_menu[2].setString("Exit");
	selectedItemIndex = 0;
}

void mainMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (int i = 0; i < _menu.size(); i++) {
		target.draw(_menu[i], states);
	}
}

mainMenu::~mainMenu() {
	std::cout << "Se eliminó el mainMenu" << std::endl << std::endl;
}

void mainMenu::MoveUp() {
	if (selectedItemIndex - 1 >= 0) {
		_menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		_menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void mainMenu::MoveDown() {
	if (selectedItemIndex + 1 < _menu.size()) {
		_menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		_menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
//TODO: loadgame - Lucas
void mainMenu::update() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (_flag) {
			this->MoveUp();
			_flag = false;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (_flag) {
			this->MoveDown();
			_flag = false;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
		switch (this->GetPressedItem()) {
		case 0:
			std::cout << "Se presionó el botón PLAY" << std::endl;
			_option = 1;
			break;
		case 1:
			std::cout << "Se presionó el botón LOAD GAME" << std::endl;
			_option = 2;
			break;
		case 2:
			std::cout << "Se presionó el botón EXIT" << std::endl;
			_option = 3;
			break;
		}
		_flag = false;
	}
	else {
		_flag = true;
	}
}
