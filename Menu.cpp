
#include "Menu.h"

Menu::Menu(float width, float height)
{
	_flag = true;
	_option = 0;
	if (!font.loadFromFile("Nostalgia.ttf"))
	{
		// handle error
	}
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Options");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}

//void Menu::draw(sf::RenderWindow& window)
//{
//	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
//	{
//		window.draw(menu[i]);
//	}
//}
void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
		{
		target.draw(menu[i], states);
		}
}

Menu::~Menu()
{
	std::cout << "se murió";
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}




void Menu::update()
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
			std::cout << "Se presionó el botón PLAY" << std::endl;
			_option = 1;
			break;
		case 1:
			std::cout << "Se presionó el botón OPTIONS" << std::endl;
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

	//	switch (event.key.code){
	//	case sf::Keyboard::Up:
	//		this->MoveUp();
	//		break;
	//	case sf::Keyboard::Down:
	//		this->MoveDown();
	//		break;
	//	case sf::Keyboard::Return:
	//		std::cout << "presionaste enter";
	//		switch (this->GetPressedItem()) {
	//		case 0:
	//			std::cout << "Play button has been pressed" << std::endl;
	//			_option = 1;
	//			break;
	//		case 1:
	//			std::cout << "Option button has been pressed" << std::endl;
	//			_option = 2;
	//			break;
	//		case 2:
	//			std::cout << "Exit button has been pressed" << std::endl;
	//			_option = 3;
	//			break;
	//		}
	//		break;
	//
	//	}
	//	std::cout << this->GetPressedItem();
	//	_flag = false;
	//}
	//if (event.type == sf::Event::KeyReleased) {
	//	_flag = true;
	//}
}


