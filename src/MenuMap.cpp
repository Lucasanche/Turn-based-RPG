#include "stdafx.h"
#include "MenuMap.h"


MenuMap::MenuMap(float width, float height, DyvirFight& dyvir) : _inventoryList(15) {
	//TODO: completar el menu (crafteo, etc) !!!!!!!!!!!!!!!!!!!!!!!! Giuli
	//TODO: cargar las habilidades del menu en el equipo de Dyvir !!!!!!!!!!!! Giuli
	sizeOfMenu = 4;
	_page = 0;
	_menu = new sf::Text[sizeOfMenu];
	_names = new sf::Text[sizeOfMenu];
	_flag = false;
	_flagSubmenu = false;
	_optionAbility = 0;
	if (!_font.loadFromFile("./Fonts/Nostalgia.ttf")) {
		std::cout << "No se pudo cargar el archivo ./Fonts/Nostalgia.ttf";
	}
	if (!_backMenuTexture.loadFromFile("./Textures/Interface/mFightPrincipal.png")) {
		std::cout << "No se pudo cargar mFightPrincipal.png" << std::endl;
	}
	_backMenu.setTexture(_backMenuTexture);
	_backMenu.setPosition(0, height / 2 - _backMenu.getGlobalBounds().height);
	_selectedItemIndex = 0;
	_posIniMenu = height / 2 - _backMenu.getGlobalBounds().height + 25;

	_posMaxMenu = 120;
	// Setea el largo del relleno del HP
	for (int i = 0; i < sizeOfMenu; i++) {
		_menu[i].setCharacterSize(25);
		_menu[i].setFont(_font);
		_names[i].setCharacterSize(20);
		_names[i].setFont(_font);
		_menu[i].setPosition(35, _posIniMenu + (_posMaxMenu * (i * 2) / 7));
		_names[i].setPosition(35, _posIniMenu + (_posMaxMenu * ((i * 2) + 1) / 7));
	}

	_menu[0].setFillColor(sf::Color::Red);
	_menu[0].setString("Habilidad 1");
	//_menu[0].setPosition({ 35, _posIniMenu });


	_names[0].setFillColor(sf::Color::White);
	_names[0].setString(dyvir.getAbility(0).getName());
	//_names[0].setPosition(35, _posIniMenu + (_posMaxMenu * 1 / 6));

	_menu[1].setFillColor(sf::Color::White);
	_menu[1].setString("Habilidad 2");
	//_menu[1].setPosition(35, _posIniMenu + (_posMaxMenu * 2 / 6));

	_names[1].setFillColor(sf::Color::White);
	_names[1].setString(dyvir.getAbility(1).getName());
	//_names[1].setPosition(35, _posIniMenu + (_posMaxMenu * 3 / 6));

	_menu[2].setFillColor(sf::Color::White);
	_menu[2].setString("Habilidad 3");
	//_menu[2].setPosition(35, _posIniMenu + (_posMaxMenu * 4 / 6));

	_names[2].setFillColor(sf::Color::White);
	_names[2].setString(dyvir.getAbility(2).getName());
	//_names[2].setPosition(35, _posIniMenu + (_posMaxMenu * 5 / 6));

	_menu[3].setFillColor(sf::Color::White);
	_menu[3].setString("Craftear");
	//_menu[2].setPosition(35, _posIniMenu + (_posMaxMenu * 4 / 6));


	int pos = 0;
	int aux = 0;

	for (int i = 0; i < _inventoryList.size(); i++) {
		_inventoryList[i].setCharacterSize(20);
		_inventoryList[i].setFont(_font);
		_inventoryList[i].setFillColor(sf::Color::White);
		_inventoryList[i].setString("Empty");

		_inventoryList[i].setPosition(250 + (aux * 200), _posIniMenu + 30 * pos);

		pos++;
		if (pos == 5) {
			pos = 0;
			aux++;
		}
	}
	_cursor.setPosition({ _menu[0].getPosition().x + 10 + _menu[0].getGlobalBounds().width,_menu[0].getPosition().y + _menu[0].getGlobalBounds().height / 2 });
}

void MenuMap::setOption(int option) {
	_optionAbility = option;
}

void MenuMap::PageUp() {
	if (_page != 0) {
		_page -= 15;
	}
}


void MenuMap::PageDown() {
	_page += 15;
}

void MenuMap::update(DyvirFight& dyvir) {

	for (int i = 0; i < _inventoryList.size(); i++) {
		_inventoryList[i].setString(dyvir.getAbilityInvName(i + _page));
	}
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
			switch (_optionMenu) {
			case 0:
				switch (this->GetPressedItem()) {
				case 0:
					_optionAbility = 0;
					_optionMenu = 1;
					this->changeMenu();
					break;
				case 1:
					_optionAbility = 1;
					_optionMenu = 1;
					this->changeMenu();
					break;
				case 2:
					_optionAbility = 2;
					_optionMenu = 1;
					this->changeMenu();
					break;
				case 3:
					_optionMenu = 2;
					this->changeMenu();
					break;
				case 4:
					_optionMenu = 4;
					this->changeMenu();
					break;
				}
				break;
			case 1:
				_optionMenu = 0;
				_names[_optionAbility].setString(dyvir.setAbilityEquiped(_optionAbility, _selectedItemIndex + _page));
				this->changeMenu();
				_flag = false;
				break;
			case 2:
				this->changeMenu();
				break;
			case 3:
				this->changeMenu();
				break;
			case 4:
				this->changeMenu();
				break;
			}
		}
		_flag = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (_optionMenu != 0)) {
		if (_flag) {
			this->PageUp();
			_flag = false;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (_optionMenu != 0)) {
		if (_flag) {
			this->PageDown();
			_flag = false;
		}
	}
	else {
		_flag = true;
	}
}

void MenuMap::changeMenu() {
	switch (_optionMenu) {
	case 0:
		_names[_selectedItemAux].setString(_inventoryList[_selectedItemIndex].getString());
		_selectedItemIndex = _selectedItemAux;
		_menu[_selectedItemIndex].setFillColor(sf::Color::Red);
		_cursor.setPosition({ _menu[_selectedItemIndex].getPosition().x + 10 + _menu[_selectedItemIndex].getGlobalBounds().width, _menu[_selectedItemIndex].getPosition().y + _menu[_selectedItemIndex].getGlobalBounds().height / 2 });
		break;
	case 1:
		_selectedItemAux = _selectedItemIndex;
		_selectedItemIndex = 0;
		for (int i = 1; i < _inventoryList.size(); i++) {
			_inventoryList[i].setFillColor(sf::Color::White);
		}
		_inventoryList[_selectedItemIndex].setFillColor(sf::Color::Red);
		_cursor.setPosition({ _inventoryList[_selectedItemIndex].getPosition().x + 10 + _inventoryList[_selectedItemIndex].getGlobalBounds().width, _inventoryList[_selectedItemIndex].getPosition().y + _inventoryList[_selectedItemIndex].getGlobalBounds().height / 2 });
		break;
	case 2:
		_selectedItemAux = _selectedItemIndex;
		_selectedItemIndex = 0;
		for (int i = 1; i < _inventoryList.size(); i++) {
			_inventoryList[i].setFillColor(sf::Color::White);
		}
		_inventoryList[_selectedItemIndex].setFillColor(sf::Color::Red);
		_cursor.setPosition({ _inventoryList[_selectedItemIndex].getPosition().x + 10 + _inventoryList[_selectedItemIndex].getGlobalBounds().width, _inventoryList[_selectedItemIndex].getPosition().y + _inventoryList[_selectedItemIndex].getGlobalBounds().height / 2 });
		_optionMenu = 3;
		break;
	case 3:
		_selectedItemCraft = _selectedItemIndex;
		_selectedItemIndex = 0;
		for (int i = 1; i < _inventoryList.size(); i++) {
			_inventoryList[i].setFillColor(sf::Color::White);
		}
		_inventoryList[_selectedItemIndex].setFillColor(sf::Color::Yellow);
		_cursor.setPosition({ _inventoryList[_selectedItemIndex].getPosition().x + 10 + _inventoryList[_selectedItemIndex].getGlobalBounds().width, _inventoryList[_selectedItemIndex].getPosition().y + _inventoryList[_selectedItemIndex].getGlobalBounds().height / 2 });
		_optionMenu = 4;
		break;
	case 4:
		_selectedItemIndex = 0;
		for (int i = 1; i < _inventoryList.size(); i++) {
			_inventoryList[i].setFillColor(sf::Color::White);
		}
		_inventoryList[_selectedItemCraft].setFillColor(sf::Color::Yellow);
		_cursor.setPosition({ _inventoryList[_selectedItemIndex].getPosition().x + 10 + _inventoryList[_selectedItemIndex].getGlobalBounds().width, _inventoryList[_selectedItemIndex].getPosition().y + _inventoryList[_selectedItemIndex].getGlobalBounds().height / 2 });
		_optionMenu = 0;
		break;
	}
}

void MenuMap::MoveUp() {
	if (_optionMenu != 0) {
		if (_selectedItemIndex - 1 >= 0) {
			_inventoryList[_selectedItemIndex].setFillColor(sf::Color::White);
			_selectedItemIndex--;
			_inventoryList[_selectedItemIndex].setFillColor(sf::Color::Red);
			_cursor.setPosition({ _inventoryList[_selectedItemIndex].getPosition().x + 10 + _inventoryList[_selectedItemIndex].getGlobalBounds().width, _inventoryList[_selectedItemIndex].getPosition().y + _inventoryList[_selectedItemIndex].getGlobalBounds().height / 2 });
		}
	}
	else if (_selectedItemIndex - 1 >= 0) {
		_menu[_selectedItemIndex].setFillColor(sf::Color::White);
		_selectedItemIndex--;
		_menu[_selectedItemIndex].setFillColor(sf::Color::Red);
		_cursor.setPosition({ _menu[_selectedItemIndex].getPosition().x + 10 + _menu[_selectedItemIndex].getGlobalBounds().width, _menu[_selectedItemIndex].getPosition().y + _menu[_selectedItemIndex].getGlobalBounds().height / 2 });
	}
	if (_optionMenu == 3) {
		_inventoryList[_selectedItemCraft].setFillColor(sf::Color::Yellow);
	}
}

void MenuMap::MoveDown() {
	if (_optionMenu != 0) {
		if (_selectedItemIndex + 1 < 15) {
			_inventoryList[_selectedItemIndex].setFillColor(sf::Color::White);
			_selectedItemIndex++;
			_inventoryList[_selectedItemIndex].setFillColor(sf::Color::Red);
			_cursor.setPosition({ _inventoryList[_selectedItemIndex].getPosition().x + 10 + _inventoryList[_selectedItemIndex].getGlobalBounds().width, _inventoryList[_selectedItemIndex].getPosition().y + _inventoryList[_selectedItemIndex].getGlobalBounds().height / 2 });
		}
	}
	else if (_selectedItemIndex + 1 < sizeOfMenu) {
		_menu[_selectedItemIndex].setFillColor(sf::Color::White);
		_selectedItemIndex++;
		_menu[_selectedItemIndex].setFillColor(sf::Color::Red);
		_cursor.setPosition({ _menu[_selectedItemIndex].getPosition().x + 10 + _menu[_selectedItemIndex].getGlobalBounds().width, _menu[_selectedItemIndex].getPosition().y + _menu[_selectedItemIndex].getGlobalBounds().height / 2 });
	}
}

void MenuMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_backMenu);

	for (int i = 0; i < sizeOfMenu; i++) {
		target.draw(_menu[i], states);
	}
	for (int i = 0; i < 3; i++) {
		target.draw(_names[i], states);
	}
	target.draw(_cursor, states);
	if (_optionMenu != 0) {
		for (int i = 0; i < _inventoryList.size(); i++) {
			target.draw(_inventoryList[i], states);
		}
	}
}

MenuMap::~MenuMap() {
	delete[] _menu;
	delete[] _names;
	std::cout << "se murióx2" << std::endl << std::endl;
}
