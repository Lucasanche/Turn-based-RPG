#include "MenuFight.h"
#include <iostream>


MenuFight::MenuFight(float width, float height)
{
	_flag = true;
	_option = 0;
	if (!font.loadFromFile("Nostalgia.ttf"))
	{
		std::cout<<"a casa por feo";
	}

    menu[0].setCharacterSize(25);
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Attack");
	menu[0].setPosition(sf::Vector2f(width+cursed.getSprite().getGlobalBounds().width, (height/3)*0+height*2/3));
	//menu[0].setPosition(sf::Vector2f(width, (height/3) / (MAX_NUMBER_OF_ITEMS) * 1 + height*2/3))

    menu[1].setCharacterSize(25);
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Special");
	menu[1].setPosition(sf::Vector2f(width+cursed.getSprite().getGlobalBounds().width, (height/3)*1/3+height*2/3));
	//menu[1].setPosition(sf::Vector2f(width, (height/3) / (MAX_NUMBER_OF_ITEMS) * 2 + height*2/3));

    menu[2].setCharacterSize(25);
	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width+cursed.getSprite().getGlobalBounds().width, (height/3)*2/3+height*2/3));
	//menu[2].setPosition(sf::Vector2f(width, (height/3) / (MAX_NUMBER_OF_ITEMS)  * 3 + height*2/3));

	selectedItemIndex = 0;

	cursed.setPosition({0,menu[0].getPosition().y});
}

//void Menu::draw(sf::RenderWindow& window)
//{
//	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
//	{
//		window.draw(menu[i]);
//	}
//}
void MenuFight::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
		{
		target.draw(menu[i], states);
		}
		target.draw(cursed, states);
}

MenuFight::~MenuFight()
{
	//std::cout << "se murió";
}

void MenuFight::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
		cursed.setPosition({0, menu[selectedItemIndex].getPosition().y});
	}
}

void MenuFight::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
		cursed.setPosition({0, menu[selectedItemIndex].getPosition().y});
	}
}




void MenuFight::update(sf::Event& event)
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
		switch (this->GetPressedItem()) {
		case 0:
			std::cout << "Play button has been pressed" << std::endl;
			_option = 1;
			break;
		case 1:
			std::cout << "Option button has been pressed" << std::endl;
			_option = 2;
			break;
		case 2:
			std::cout << "Exit button has been pressed" << std::endl;
			_option = 3;
			break;
		}
	}
	else {
		_flag = true;
	}
}
