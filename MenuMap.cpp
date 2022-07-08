#include "stdafx.h"
#include "MenuMap.h"

MenuMap::MenuMap(float width, float height, DyvirFight dyvir)
{
	sizeOfMenu = 3;
	sizeOfList = dyvir.getAbilityAmount();
	_menu = new sf::Text[sizeOfMenu];
	_names = new sf::Text[sizeOfMenu];
    _inventoryList = new sf::Text[sizeOfList];
	_flag = false;
	_flagSubmenu = false;
	_option = 0;
	if (!_font.loadFromFile("Nostalgia.ttf"))
	{
		std::cout<<"No se pudo cargar el archivo Nostalgia.ttf";
	}

	if (!_backMenuTexture.loadFromFile("interface/mFightPrincipal.png")) {
		std::cout << "No se pudo cargar mFightPrincipal.png" << std::endl;
	}

	_backMenu.setTexture(_backMenuTexture);
	_backMenu.setPosition(0, height/2 - _backMenu.getGlobalBounds().height);
	_selectedItemIndex = 0;
	_posIniMenu=height/2 - _backMenu.getGlobalBounds().height+25;

	_posMaxMenu = 120;
	// Setea el largo del relleno del HP
	_menu[0].setCharacterSize(25);
	_menu[0].setFont(_font);
	_menu[0].setFillColor(sf::Color::Red);
	_menu[0].setString("Habilidad 1");
	_menu[0].setPosition({ 35, _posIniMenu});

    _names[0].setCharacterSize(20);
	_names[0].setFont(_font);
	_names[0].setFillColor(sf::Color::White);
	_names[0].setString(dyvir.getAbility(0).getName());
	_names[0].setPosition( 35,_posIniMenu + (_posMaxMenu * 1 / 6));

	_menu[1].setCharacterSize(25);
	_menu[1].setFont(_font);
	_menu[1].setFillColor(sf::Color::White);
	_menu[1].setString("Habilidad 2");
	_menu[1].setPosition(35, _posIniMenu + (_posMaxMenu * 2 / 6));

    _names[1].setCharacterSize(20);
	_names[1].setFont(_font);
	_names[1].setFillColor(sf::Color::White);
	_names[1].setString(dyvir.getAbility(1).getName());
	_names[1].setPosition( 35,_posIniMenu + (_posMaxMenu * 3 / 6));

	_menu[2].setCharacterSize(25);
	_menu[2].setFont(_font);
	_menu[2].setFillColor(sf::Color::White);
	_menu[2].setString("Habilidad 3");
	_menu[2].setPosition(35, _posIniMenu + (_posMaxMenu * 4 / 6));

    _names[2].setCharacterSize(20);
	_names[2].setFont(_font);
	_names[2].setFillColor(sf::Color::White);
	_names[2].setString(dyvir.getAbility(2).getName());
	_names[2].setPosition( 35,_posIniMenu + (_posMaxMenu * 5 / 6));


	for(int i=0; i < sizeOfList; i++){

        _inventoryList[i].setCharacterSize(20);
        _inventoryList[i].setFont(_font);
        _inventoryList[i].setFillColor(sf::Color::White);
        _inventoryList[i].setString(dyvir.getAbilityInv(i).getName());
        _inventoryList[i].setPosition( 300,_posIniMenu + (_posMaxMenu * i / sizeOfList));

	}


	_cursor.setPosition({ _menu[0].getPosition().x + 10 + _menu[0].getGlobalBounds().width,_menu[0].getPosition().y + _menu[0].getGlobalBounds().height / 2 });
}

void MenuMap::setOption(int option) {
	_option = option;
}

void MenuMap::update()
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
				std::cout << "Se presionó el botón H1" << std::endl << std::endl;
				break;
			case 1:
				std::cout << "Se presionó el botón H2" << std::endl << std::endl;
				_option = 2;
				break;
			case 2:
				std::cout << "Se presionó el botón H3" << std::endl << std::endl;
				_option = 3;
				break;
			}
			_flagSubmenu = !_flagSubmenu;
			this->changeMenu();
			_flag = false;
		}
	}
	else {
		_flag = true;
		_option = 0;
	}
}

void MenuMap::changeMenu() {
	if (_flagSubmenu) {
		_selectedItemAux = _selectedItemIndex;
		_selectedItemIndex = 0;
		for (int i = 1; i < sizeOfList; i++) {
			_inventoryList[i].setFillColor(sf::Color::White);
		}
		_inventoryList[_selectedItemIndex].setFillColor(sf::Color::Red);
		_cursor.setPosition({ _inventoryList[_selectedItemIndex].getPosition().x + 10 + _inventoryList[_selectedItemIndex].getGlobalBounds().width, _inventoryList[_selectedItemIndex].getPosition().y + _inventoryList[_selectedItemIndex].getGlobalBounds().height / 2 });
	}
	else {
		_names[_selectedItemAux].setString(_inventoryList[_selectedItemIndex].getString());
		_selectedItemIndex = _selectedItemAux;
		_menu[_selectedItemIndex].setFillColor(sf::Color::Red);
		_cursor.setPosition({ _menu[_selectedItemIndex].getPosition().x + 10 + _menu[_selectedItemIndex].getGlobalBounds().width, _menu[_selectedItemIndex].getPosition().y + _menu[_selectedItemIndex].getGlobalBounds().height / 2 });
	}
}

void MenuMap::MoveUp()
{
    if(_flagSubmenu){
        if(_selectedItemIndex-1>=0){
            _inventoryList[_selectedItemIndex].setFillColor(sf::Color::White);
            _selectedItemIndex--;
            _inventoryList[_selectedItemIndex].setFillColor(sf::Color::Red);
            _cursor.setPosition({ _inventoryList[_selectedItemIndex].getPosition().x + 10 + _inventoryList[_selectedItemIndex].getGlobalBounds().width, _inventoryList[_selectedItemIndex].getPosition().y + _inventoryList[_selectedItemIndex].getGlobalBounds().height / 2 });
        }
    }
	else if (_selectedItemIndex - 1 >= 0)
	{
		_menu[_selectedItemIndex].setFillColor(sf::Color::White);
		_selectedItemIndex--;
		_menu[_selectedItemIndex].setFillColor(sf::Color::Red);
		_cursor.setPosition({ _menu[_selectedItemIndex].getPosition().x + 10 + _menu[_selectedItemIndex].getGlobalBounds().width, _menu[_selectedItemIndex].getPosition().y + _menu[_selectedItemIndex].getGlobalBounds().height / 2 });
	}
}

void MenuMap::MoveDown()
{
    if (_flagSubmenu){
        	if (_selectedItemIndex + 1 < 6)
			{
				_inventoryList[_selectedItemIndex].setFillColor(sf::Color::White);
				_selectedItemIndex++;
				_inventoryList[_selectedItemIndex].setFillColor(sf::Color::Red);
				_cursor.setPosition({ _inventoryList	[_selectedItemIndex].getPosition	().x + 10  + _inventoryList [_selectedItemIndex].getGlobalBounds ().width, _inventoryList[_selectedItemIndex].getPosition().y + _inventoryList [_selectedItemIndex].getGlobalBounds().height / 2 });
			}
}


	else if (_selectedItemIndex + 1 < sizeOfMenu)
	{
		_menu[_selectedItemIndex].setFillColor(sf::Color::White);
		_selectedItemIndex++;
		_menu[_selectedItemIndex].setFillColor(sf::Color::Red);
		_cursor.setPosition({ _menu[_selectedItemIndex].getPosition().x + 10  + _menu[_selectedItemIndex].getGlobalBounds().width, _menu[_selectedItemIndex].getPosition().y + _menu[_selectedItemIndex].getGlobalBounds().height / 2 });
	}
}

void MenuMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_backMenu);

	for (int i = 0; i < sizeOfMenu; i++)
		{
		target.draw(_menu[i], states);
		}
	for (int i = 0; i < 3; i++)
	{
		target.draw(_names[i], states);
	}
	target.draw(_cursor, states);

	if (_flagSubmenu){

       	for (int i = 0; i < 6; i++)
		{
		target.draw(_inventoryList[i], states);
		}

	}
}

MenuMap::~MenuMap()
{
	std::cout << "se murióx2" << std::endl << std::endl;
}


