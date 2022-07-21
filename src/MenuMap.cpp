#include "stdafx.h"
#include "MenuMap.h"


MenuMap::MenuMap(float width, float height, DyvirFight& dyvir) : _inventoryList(15), _menu(5), _names(5), _slots(3) {
	//TODO: agregar menu para ver los stats - Lucas
	_page = 0;
	_checkPoint = false;
	_flag = false;
	_flagSubmenu = false;
	_optionAbility = 0;
	if (!_font.loadFromFile("./Fonts/Nostalgia.ttf")) {
		std::cout << "No se pudo cargar el archivo ./Fonts/Nostalgia.ttf";
	}
	if (!_backMenuTexture.loadFromFile("./Textures/Interface/mFightPrincipal.png")) {
		std::cout << "No se pudo cargar mFightPrincipal.png" << std::endl;
	}
	if (!_backMenuTexture2.loadFromFile("./Textures/Interface/mMap.png")) {
		std::cout << "No se pudo cargar mFightPrincipal.png" << std::endl;
	}
	_backMenu.setTexture(_backMenuTexture);
	_backMenu.setPosition(0, height / 2 - _backMenu.getGlobalBounds().height);
	_selectedItemIndex = 0;
	_posIniMenu = height / 2 - _backMenu.getGlobalBounds().height + 25;
	_backMenu2.setTexture(_backMenuTexture2);
	_backMenu2.setScale(0.7, 0.7);
	_backMenu2.setPosition(width/7, height / 3 + _backMenu2.getGlobalBounds().height);

	_posMaxMenu = 120;

	for (int i = 0; i < _menu.size(); i++) {
		_menu[i].setCharacterSize(25);
		_menu[i].setFont(_font);
		_names[i].setCharacterSize(20);
		_names[i].setFont(_font);
		_menu[i].setPosition(35, _posIniMenu + (_posMaxMenu * (i * 2) / 7));
		_names[i].setPosition(35, _posIniMenu + (_posMaxMenu * ((i * 2) + 1) / 7));
	}

	for (int i = 0; i < 3; i++) {
		_slots[i].setFillColor(sf::Color::White);
		_slots[i].setPosition(250, _posIniMenu + 30 * i);
		_slots[i].setCharacterSize(25);
		_slots[i].setFont(_font);
	}

	_menu[0].setFillColor(sf::Color::Red);
	_menu[0].setString("Habilidad 1");

	_names[0].setFillColor(sf::Color::White);
	_names[0].setString(dyvir.getAbility(0).getName());

	_menu[1].setFillColor(sf::Color::White);
	_menu[1].setString("Habilidad 2");

	_names[1].setFillColor(sf::Color::White);
	_names[1].setString(dyvir.getAbility(1).getName());

	_menu[2].setFillColor(sf::Color::White);
	_menu[2].setString("Habilidad 3");

	_names[2].setFillColor(sf::Color::White);
	_names[2].setString(dyvir.getAbility(2).getName());

	_menu[3].setFillColor(sf::Color::White);
	_menu[3].setString("Craftear");

	_menu[4].setFillColor(sf::Color::White);
	_menu[4].setString("Guardar");

	_slots[0].setString("Slot 1");
	_slots[1].setString("Slot 2");
	_slots[2].setString("Slot 3");

	_description.setCharacterSize(25);
	_description.setFont(_font);
	_description.setFillColor(sf::Color::White);
	_description.setPosition(225, 450);

	_saveText.setCharacterSize(25);
	_saveText.setFont(_font);
	_saveText.setFillColor(sf::Color::White);
	_saveText.setPosition(225, 450);
	_saveText.setString("Partida guardada correctamente");




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

void MenuMap::update(DyvirFight& dyvir, bool check, DyvirMap& dyvirMap) {

	_checkPoint = check;
	if (_checkPoint) {
		dyvir.restoreLife();
	}

	_description.setString(dyvir.getInventoryElementDescription(_selectedItemIndex + _page));
	

	for (int i = 0; i < _inventoryList.size(); i++) {
		_inventoryList[i].setString(dyvir.getInventoryElementName(i + _page));
	}
	if (!_checkPoint) {
		_menu[_menu.size() - 1].setFillColor(sf::Color::Transparent);
	}
	else {
		_menu[_menu.size() - 1].setFillColor(sf::Color::White);
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
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		_menuOption = MenuOption::MainMenu;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
		if (_flag) {
			switch (_menuOption) {
			case MenuOption::MainMenu:
				switch (this->GetPressedItem()) {
				case 0:
					_optionAbility = 0;
					_menuOption = MenuOption::AbilityChange;
					break;
				case 1:
					_optionAbility = 1;
					_menuOption = MenuOption::AbilityChange;
					break;
				case 2:
					_optionAbility = 2;
					_menuOption = MenuOption::AbilityChange;
					break;
				case 3:
					_menuOption = MenuOption::Craft;
					break;
				case 4:
					_menuOption = MenuOption::Save;
					break;
				}
				_flagSave = false;
				this->changeMenu();
				break;
			case MenuOption::AbilityChange:
				_flagSave = false;
				_names[_optionAbility].setString(dyvir.setAbilityEquipedElement(_optionAbility, _selectedItemIndex + _page));
				_menuOption = MenuOption::MainMenu;
				this->ResetColor();
				_selectedItemIndex = 0;
				this->ResetCursor();

				break;
			case MenuOption::Craft:
				_flagSave = false;
				if (_inventoryList[_selectedItemIndex].getString() == "Empty") { break; }
				_menuOption = MenuOption::Craft2;
				this->changeMenu();
				break;
			case MenuOption::Craft2:
				if (_selectedItemIndex == _selectedItemCraft && _page == _pageAux) {
					_inventoryList[_selectedItemIndex].setFillColor(sf::Color::Green);
					_selectedItemIndex = 0;
					break;
				}
				else if (_inventoryList[_selectedItemIndex].getString() == "Empty") {
					_selectedItemIndex = 0;
					break;
				}
				else {
					dyvir.craftAbility(_inventoryList[_selectedItemIndex + _page].getString(), _inventoryList[_selectedItemCraft + _pageAux].getString(), _selectedItemIndex + _page, _selectedItemCraft + _pageAux);
					this->ResetColor();
					_menuOption = MenuOption::MainMenu;
					_selectedItemIndex = 0;
					this->ResetCursor();
					this->changeMenu();
					break;
				}
			case MenuOption::Save:
				if (_save.saveGame(dyvirMap, dyvir, _selectedItemIndex)) {
					_saveText.setString("Partida guardada correctamente");
				}
				else _saveText.setString("Error de guardado");
				this->ResetColor();
				_menuOption = MenuOption::MainMenu;
				_selectedItemIndex = 0;
				_flagSave = true;
				this->ResetCursor();
				this->changeMenu();
				break;

			}
			_flag = false;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (_menuOption != MenuOption::MainMenu)) {
		if (_flag) {
			this->PageUp();
			_flag = false;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (_menuOption != MenuOption::MainMenu)) {
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
	switch (_menuOption) {
	case MenuOption::MainMenu:
		_selectedItemIndex = _selectedItemAux;
		_menu[_selectedItemAux].setFillColor(sf::Color::Red);
		_cursor.setPosition({ _menu[_selectedItemAux].getPosition().x + 10 + _menu[_selectedItemAux].getGlobalBounds().width, _menu[_selectedItemAux].getPosition().y + _menu[_selectedItemAux].getGlobalBounds().height / 2 });
		break;
	case MenuOption::AbilityChange:
		_selectedItemAux = _selectedItemIndex;
		_selectedItemIndex = 0;
		for (int i = 1; i < _inventoryList.size(); i++) {
			_inventoryList[i].setFillColor(sf::Color::White);
		}
		_inventoryList[_selectedItemIndex].setFillColor(sf::Color::Red);
		_cursor.setPosition({ _inventoryList[_selectedItemIndex].getPosition().x + 10 + _inventoryList[_selectedItemIndex].getGlobalBounds().width, _inventoryList[_selectedItemIndex].getPosition().y + _inventoryList[_selectedItemIndex].getGlobalBounds().height / 2 });
		//_description.setString(dyvir.getInventoryElementDescription(_selectedItemIndex + _page));
		break;
	case MenuOption::Craft:
		_selectedItemAux = _selectedItemIndex;
		_selectedItemIndex = 0;
		for (int i = 1; i < _inventoryList.size(); i++) {
			_inventoryList[i].setFillColor(sf::Color::White);
		}
		_inventoryList[_selectedItemIndex].setFillColor(sf::Color::Red);
		_cursor.setPosition({ _inventoryList[_selectedItemIndex].getPosition().x + 10 + _inventoryList[_selectedItemIndex].getGlobalBounds().width, _inventoryList[_selectedItemIndex].getPosition().y + _inventoryList[_selectedItemIndex].getGlobalBounds().height / 2 });
		
		//_description.setString(dyvir.getInventoryElementDescription(_selectedItemIndex + _page));
		break;
	case MenuOption::Craft2:
		_selectedItemCraft = _selectedItemIndex;
		_selectedItemIndex = 0;
		_pageAux = _page;
		for (int i = 1; i < _inventoryList.size(); i++) {
			_inventoryList[i].setFillColor(sf::Color::White);
		}
		_inventoryList[_selectedItemIndex].setFillColor(sf::Color::Red);
		if (_page == _pageAux) {
			_inventoryList[_selectedItemCraft].setFillColor(sf::Color::Yellow);
		}
		_cursor.setPosition({ _inventoryList[_selectedItemIndex].getPosition().x + 10 + _inventoryList[_selectedItemIndex].getGlobalBounds().width, _inventoryList[_selectedItemIndex].getPosition().y + _inventoryList[_selectedItemIndex].getGlobalBounds().height / 2 });
		//_description.setString(dyvir.getInventoryElementDescription(_selectedItemIndex + _page));
		break;
	case MenuOption::Save:
		_selectedItemIndex = _selectedItemAux;
		_selectedItemIndex = 0;
		_slots[_selectedItemAux].setFillColor(sf::Color::Red);
		_cursor.setPosition({ _slots[_selectedItemAux].getPosition().x + 10 + _slots[_selectedItemAux].getGlobalBounds().width, _slots[_selectedItemAux].getPosition().y + _slots[_selectedItemAux].getGlobalBounds().height / 2 });
		break;
	}

}

void MenuMap::ResetColor() {

	if (_menuOption == MenuOption::Save) {
		for (int i = 0; i < 3; i++) {
			_slots[i].setFillColor(sf::Color::White);

		}
	}
	else if (_menuOption == MenuOption::Craft2) {
		for (int i = 0; i < _inventoryList.size(); i++) {
			_inventoryList[i].setFillColor(sf::Color::White);
		}
	}
	else if (_menuOption == MenuOption::MainMenu) {
		for (int i = 0; i < _menu.size(); i++) {
			_menu[i].setFillColor(sf::Color::White);
		}
	}

}
void MenuMap::ResetCursor() {

	_cursor.setPosition({ _menu[_selectedItemIndex].getPosition().x + 10 + _menu[_selectedItemIndex].getGlobalBounds().width, _menu[_selectedItemIndex].getPosition().y + _menu[_selectedItemIndex].getGlobalBounds().height / 2 });

}

void MenuMap::MoveUp() {
	if (_menuOption == MenuOption::Craft2) {
		if (_selectedItemIndex - 1 >= 0) {
			if (_page == _pageAux && _selectedItemIndex == _selectedItemCraft) {
				_inventoryList[_selectedItemIndex].setFillColor(sf::Color::Yellow);
			}
			else { _inventoryList[_selectedItemIndex].setFillColor(sf::Color::White); }
			_selectedItemIndex--;
			if (_page == _pageAux && _selectedItemIndex == _selectedItemCraft) {
				_inventoryList[_selectedItemIndex].setFillColor(sf::Color::Green);
			}
			else { _inventoryList[_selectedItemIndex].setFillColor(sf::Color::Red); }
			_cursor.setPosition({ _inventoryList[_selectedItemIndex].getPosition().x + 10 + _inventoryList[_selectedItemIndex].getGlobalBounds().width, _inventoryList[_selectedItemIndex].getPosition().y + _inventoryList[_selectedItemIndex].getGlobalBounds().height / 2 });
			//_description.setString(dyvir.getInventoryElementDescription(_selectedItemIndex + _page));
		}
	}
	else if (_menuOption != MenuOption::MainMenu && _menuOption != MenuOption::Save) {
		if (_selectedItemIndex - 1 >= 0) {
			_inventoryList[_selectedItemIndex].setFillColor(sf::Color::White);
			_selectedItemIndex--;
			_inventoryList[_selectedItemIndex].setFillColor(sf::Color::Red);
			_cursor.setPosition({ _inventoryList[_selectedItemIndex].getPosition().x + 10 + _inventoryList[_selectedItemIndex].getGlobalBounds().width, _inventoryList[_selectedItemIndex].getPosition().y + _inventoryList[_selectedItemIndex].getGlobalBounds().height / 2 });
			//_description.setString(dyvir.getInventoryElementDescription(_selectedItemIndex + _page));
		}
	}
	else if (_selectedItemIndex - 1 >= 0 && _menuOption != MenuOption::Save) {
		_menu[_selectedItemIndex].setFillColor(sf::Color::White);
		_selectedItemIndex--;
		_menu[_selectedItemIndex].setFillColor(sf::Color::Red);
		_cursor.setPosition({ _menu[_selectedItemIndex].getPosition().x + 10 + _menu[_selectedItemIndex].getGlobalBounds().width, _menu[_selectedItemIndex].getPosition().y + _menu[_selectedItemIndex].getGlobalBounds().height / 2 });
	}
	else if (_selectedItemIndex - 1 >= 0 && _menuOption == MenuOption::Save) {
		_slots[_selectedItemIndex].setFillColor(sf::Color::White);
		_selectedItemIndex--;
		_slots[_selectedItemIndex].setFillColor(sf::Color::Red);
		_cursor.setPosition({ _slots[_selectedItemIndex].getPosition().x + 10 + _slots[_selectedItemIndex].getGlobalBounds().width, _slots[_selectedItemIndex].getPosition().y + _slots[_selectedItemIndex].getGlobalBounds().height / 2 });
	}
}

void MenuMap::MoveDown() {
	if (_menuOption == MenuOption::Craft2) {
		if (_selectedItemIndex + 1 < 15) {
			if (_page == _pageAux && _selectedItemIndex == _selectedItemCraft) {
				_inventoryList[_selectedItemIndex].setFillColor(sf::Color::Yellow);
			}
			else { _inventoryList[_selectedItemIndex].setFillColor(sf::Color::White); }
			_selectedItemIndex++;
			if (_page == _pageAux && _selectedItemIndex == _selectedItemCraft) {
				_inventoryList[_selectedItemIndex].setFillColor(sf::Color::Green);
			}
			else { _inventoryList[_selectedItemIndex].setFillColor(sf::Color::Red); }
			_cursor.setPosition({ _inventoryList[_selectedItemIndex].getPosition().x + 10 + _inventoryList[_selectedItemIndex].getGlobalBounds().width, _inventoryList[_selectedItemIndex].getPosition().y + _inventoryList[_selectedItemIndex].getGlobalBounds().height / 2 });
			//_description.setString(dyvir.getInventoryElementDescription(_selectedItemIndex + _page));
		}
	}
	else if (_menuOption != MenuOption::MainMenu && _menuOption != MenuOption::Save) {
		if (_selectedItemIndex + 1 < 15) {
			_inventoryList[_selectedItemIndex].setFillColor(sf::Color::White);
			_selectedItemIndex++;
			_inventoryList[_selectedItemIndex].setFillColor(sf::Color::Red);
			_cursor.setPosition({ _inventoryList[_selectedItemIndex].getPosition().x + 10 + _inventoryList[_selectedItemIndex].getGlobalBounds().width, _inventoryList[_selectedItemIndex].getPosition().y + _inventoryList[_selectedItemIndex].getGlobalBounds().height / 2 });
			//_description.setString(dyvir.getInventoryElementDescription(_selectedItemIndex + _page));
		}
	}
	else if ((_selectedItemIndex + 1 < _menu.size() - 1) && !_checkPoint && _menuOption != MenuOption::Save) {
		_menu[_selectedItemIndex].setFillColor(sf::Color::White);
		_selectedItemIndex++;
		_menu[_selectedItemIndex].setFillColor(sf::Color::Red);
		_cursor.setPosition({ _menu[_selectedItemIndex].getPosition().x + 10 + _menu[_selectedItemIndex].getGlobalBounds().width, _menu[_selectedItemIndex].getPosition().y + _menu[_selectedItemIndex].getGlobalBounds().height / 2 });
	}
	else if (_selectedItemIndex + 1 < _menu.size() && _checkPoint && _menuOption != MenuOption::Save) {
		_menu[_selectedItemIndex].setFillColor(sf::Color::White);
		_selectedItemIndex++;
		_menu[_selectedItemIndex].setFillColor(sf::Color::Red);
		_cursor.setPosition({ _menu[_selectedItemIndex].getPosition().x + 10 + _menu[_selectedItemIndex].getGlobalBounds().width, _menu[_selectedItemIndex].getPosition().y + _menu[_selectedItemIndex].getGlobalBounds().height / 2 });
	}
	else if (_menuOption == MenuOption::Save) {
		if (_selectedItemIndex + 1 < 3) {
			_slots[_selectedItemIndex].setFillColor(sf::Color::White);
			_selectedItemIndex++;
			_slots[_selectedItemIndex].setFillColor(sf::Color::Red);
			_cursor.setPosition({ _slots[_selectedItemIndex].getPosition().x + 10 + _slots[_selectedItemIndex].getGlobalBounds().width, _slots[_selectedItemIndex].getPosition().y + _slots[_selectedItemIndex].getGlobalBounds().height / 2 });
		}
	}
}

void MenuMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_backMenu);
	target.draw(_backMenu2);
	for (int i = 0; i < _menu.size(); i++) {
		target.draw(_menu[i], states);
	}
	for (int i = 0; i < _names.size(); i++) {
		target.draw(_names[i], states);
	}
	target.draw(_cursor, states);
	if ((_menuOption != MenuOption::MainMenu) && (_menuOption != MenuOption::Save)) {
		for (int i = 0; i < _inventoryList.size(); i++) {
			target.draw(_inventoryList[i], states);
			target.draw(_description, states);
		}
	}
	else if (_menuOption == MenuOption::Save) {
		for (int i = 0; i < 3; i++) {
			target.draw(_slots[i], states);
		}
	}
	if (_flagSave) {
		target.draw(_saveText, states);
	}
}

MenuMap::~MenuMap() {
	std::cout << "Se eliminó MenuMap" << std::endl << std::endl;
}
