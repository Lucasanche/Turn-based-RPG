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
		_menu[i].setPosition(sf::Vector2f(width / 2, height / (_menu.size() + 1) * (1 + i)));
		_menu[i].setFillColor(sf::Color::White);
	}
	this->setMainMenu();
	_menu[0].setFillColor(sf::Color::Red);
	selectedItemIndex = 0;
}

void mainMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (int i = 0; i < _menu.size(); i++) {
		target.draw(_menu[i], states);
	}
}

void mainMenu::MoveUp() {
	if (_option != 4) {
		if (selectedItemIndex - 1 >= 0) {
			_menu[selectedItemIndex].setFillColor(sf::Color::White);
			selectedItemIndex--;
			_menu[selectedItemIndex].setFillColor(sf::Color::Red);
		}
	}

}

void mainMenu::MoveDown() {
	if (_option != 4) {
		if (selectedItemIndex + 1 < _menu.size()) {
			_menu[selectedItemIndex].setFillColor(sf::Color::White);
			selectedItemIndex++;
			_menu[selectedItemIndex].setFillColor(sf::Color::Red);
		}
	}
}
//TODO: loadgame - Lucas
int mainMenu::update() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (_flag && _option != 4) {
			this->MoveUp();
			_flag = false;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (_flag && _option != 4) {
			this->MoveDown();
			_flag = false;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
		if (_flag) {
			switch (_option) {
			case 0:
				switch (this->GetPressedItem()) {
				case 0:
					_option = 1;
					break;
				case 1:
					_option = 2;
					_menu[0].setString("Partida 1");
					_menu[1].setString("Partida 2");
					_menu[2].setString("Partida 3");
					this->resetIndex();
					break;
				case 2:
					_option = 3;
					break;
				}
				break;
			case 2:
				_option = 1;
				break;
			case 4:
				this->resetIndex();
				this->setMainMenu();
				_option = 0;
				break;
			}
			_flag = false;
		}
	}
	else {
		_flag = true;
	}
	return _option;
}

void mainMenu::setMainMenu() {
	_menu[0].setString("Nuevo juego");
	_menu[1].setString("Cargar partida");
	_menu[2].setString("Salir");
}

void mainMenu::setErrorLoadGame() {
	for (int i = 0; i < 3; i++) {
		_menu[i].setFillColor(sf::Color::Transparent);
	}
	_menu[1].setFillColor(sf::Color::White);
	_menu[1].setString("No se pudo cargar la partida");
}

void mainMenu::resetIndex() {
	selectedItemIndex = 0;
	_menu[0].setFillColor(sf::Color::Red);
	_menu[1].setFillColor(sf::Color::White);
	_menu[2].setFillColor(sf::Color::White);
}

mainMenu::~mainMenu() {
	std::cout << "Se eliminó el mainMenu" << std::endl << std::endl;
}
