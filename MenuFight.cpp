#include "MenuFight.h"
#include <iostream>



MenuFight::MenuFight(float width, float height)
{
	_flag = false;
	_option = 0;
	if (!font.loadFromFile("Nostalgia.ttf"))
	{
		std::cout<<"a casa por feo";
	}

    menu[0].setCharacterSize(25);
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Attack");
	menu[0].setPosition(sf::Vector2f(width+cursor.getSprite().getGlobalBounds().width, (height/3)*0+height*2/3));

    menu[1].setCharacterSize(25);
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Special");
	menu[1].setPosition(sf::Vector2f(width+cursor.getSprite().getGlobalBounds().width, (height/3)*1/3+height*2/3));

    menu[2].setCharacterSize(25);
	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Escape");
	menu[2].setPosition(sf::Vector2f(width+cursor.getSprite().getGlobalBounds().width, (height/3)*2/3+height*2/3));

	selectedItemIndex = 0;

	cursor.setPosition({0,menu[0].getPosition().y});
}

void MenuFight::setOption(int option) {
	_option = option;
}

void MenuFight::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
		{
		target.draw(menu[i], states);
		}
		target.draw(cursor, states);
}

MenuFight::~MenuFight()
{
	std::cout << "se murió" << std::endl << std::endl;
}

void MenuFight::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
		cursor.setPosition({0, menu[selectedItemIndex].getPosition().y});
	}
}

void MenuFight::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
		cursor.setPosition({0, menu[selectedItemIndex].getPosition().y});
	}
}




int MenuFight::update()
{
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
		if (_flag) {
			switch (this->GetPressedItem()) {
			case 0:
				std::cout << "Se presionó el botón ATACK" << std::endl << std::endl;
				_option = 1;
				break;
			case 1:
				std::cout << "Se presionó el botón SPECIAL" << std::endl << std::endl;
				_option = 2;
				break;
			case 2:
				std::cout << "Se presionó el botón ESCAPE" << std::endl << std::endl;
				_option = 3;
				break;
			}
			_flag = false;
		}
		
		
	}
	else {
		_flag = true;
		_option = 0;
	}
	return _option;
}
