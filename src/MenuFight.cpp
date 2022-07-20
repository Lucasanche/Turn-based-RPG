#include "stdafx.h"
#include "MenuFight.h"


MenuFight::MenuFight(float width, float height, Dragon& dyvir) : _menu(3), _dragonNames(2), _menuStrings(3) {
	_resultBars = 0;
	_lenghtHPdyvir = 0;
	_lenghtMPdyvir = 0;
	_lenghtHPenemy = 0;
	_lenghtHPdyvir = 0;
	_flag = false;
	_option = wait;

	if (!_font.loadFromFile("./Fonts/Nostalgia.ttf")) {
		std::cout << "No se pudo cargar el archivo ./Fonts/Nostalgia.ttf";
	}
	if (!_backMenuTexture.loadFromFile("./Textures/Interface/mFightPrincipal.png")) {
		std::cout << "No se pudo cargar mFightPrincipal.png" << std::endl;
	}
	if (!_backMenuEnemyTexture.loadFromFile("./Textures/Interface/mFightEnemy.png")) {
		std::cout << "No se pudo cargar mFightEnemy.png" << std::endl;
	}
	_backMenu.setTexture(_backMenuTexture);
	_backMenu.setPosition(0, height - _backMenu.getGlobalBounds().height);
	_backMenuEnemy.setTexture(_backMenuEnemyTexture);
	_backMenuEnemy.setPosition(width - _backMenuEnemy.getGlobalBounds().width, 0);
	_selectedItemIndex = 0;
	///Variables útiles para los sprites
	 // Setea el color del relleno del HP
	_statusHPdyvir = 1;
	_statusHPenemy = 1;

	//Barra de HP y MP

	//Setear textura
	_textureHP.loadFromFile("./Textures/Interface/HP_bar.png");
	_spriteHPdyvir.setTexture(_textureHP);
	_spriteMPdyvir.setTexture(_textureHP);
	_spriteHPFilldyvir.setTexture(_textureHP);
	_spriteMPFilldyivir.setTexture(_textureHP);
	_textHPdyvir.setTexture(_textureHP);
	_textMPdyvir.setTexture(_textureHP);
	_spriteHPenemy.setTexture(_textureHP);
	_spriteHPFillenemy.setTexture(_textureHP);
	_textHPenemy.setTexture(_textureHP);
	//
	spriteSize = { 158,15 };
	positionHPdyvir = { _backMenu.getPosition().x + 40, _backMenu.getPosition().y + 50 };
	positionHPenemy = { _backMenuEnemy.getPosition().x + 30, _backMenuEnemy.getPosition().y + 57 };

	_spriteHPdyvir.setTextureRect({ {0, spriteSize.y * 0 }, spriteSize });
	_spriteHPdyvir.setPosition(_backMenu.getPosition().x + 40, _backMenu.getPosition().y + 50);
	_spriteHPFilldyvir.setTextureRect({ {0, spriteSize.y * 1 }, spriteSize });
	_spriteHPFilldyvir.setPosition(_spriteHPdyvir.getPosition());
	_textHPdyvir.setPosition(_spriteHPdyvir.getPosition());
	_textHPdyvir.setTextureRect({ {0, spriteSize.y * 8 }, spriteSize });
	_spriteMPdyvir.setTextureRect({ {0, spriteSize.y * 0 }, spriteSize });
	_spriteMPdyvir.setPosition(positionHPdyvir.x, positionHPdyvir.y + _spriteHPdyvir.getGlobalBounds().height + 5);
	_spriteMPFilldyivir.setTextureRect({ {0, spriteSize.y * 6 }, spriteSize });
	_spriteMPFilldyivir.setPosition(_spriteMPdyvir.getPosition());
	_textMPdyvir.setTextureRect({ {0, spriteSize.y * 7 }, spriteSize });
	_textMPdyvir.setPosition(_spriteMPdyvir.getPosition());

	_spriteHPenemy.setTextureRect({ {0, spriteSize.y * 0 }, spriteSize });
	_spriteHPenemy.setPosition(positionHPenemy);
	_spriteHPFillenemy.setTextureRect({ {0, spriteSize.y * _statusHPenemy }, spriteSize });
	_spriteHPFillenemy.setPosition(_spriteHPenemy.getPosition());
	_textHPenemy.setPosition(_spriteHPenemy.getPosition());
	_textHPenemy.setTextureRect({ {0, spriteSize.y * 8 }, spriteSize });
	_posIniMenu = _spriteHPdyvir.getPosition().y + 27;
	_posMaxMenu = 120;
	// Setea el largo del relleno del HP


	for (int i = 0; i < _dragonNames.size(); i++) {
		_dragonNames[i].setCharacterSize(25);
		_dragonNames[i].setFont(_font);
		_dragonNames[i].setFillColor(sf::Color::White);
		_dragonNames[i].setStyle(sf::Text::Italic);
		_dragonNames[i].setString("DYVIR");
	}

	_dragonNames[0].setString("DYVIR");
	_dragonNames[0].setPosition({ _spriteHPdyvir.getPosition().x + _spriteHPdyvir.getGlobalBounds().width / 3, _spriteHPdyvir.getPosition().y - 30 });

	_dragonNames[1].setString("ENEMY");
	_dragonNames[1].setPosition({ _spriteHPenemy.getPosition().x + _spriteHPenemy.getGlobalBounds().width / 3, _spriteHPenemy.getPosition().y - 40 });
	
	_menuStrings[0] = "Attack";
	_menuStrings[1] = "Ability 1";
	_menuStrings[2] = "Ability 2";

	for (int i = 0; i < _menu.size(); i++) {
		_menu[i].setCharacterSize(25);
		_menu[i].setFont(_font);
		_menu[i].setFillColor(sf::Color::White);
		_menu[i].setString(_menuStrings[i]);
		//_menu[i].setPosition();
	}

	_menu[0].setFillColor(sf::Color::Red);
	_menu[0].setPosition({ 35, _posIniMenu });

	_menu[1].setPosition(35, _posIniMenu + (_posMaxMenu * 1 / 3));

	_menu[2].setPosition(35, _posIniMenu + (_posMaxMenu * 2 / 3));
	_cursor.setPosition({ _menu[0].getPosition().x + 10 + _menu[0].getGlobalBounds().width,_menu[0].getPosition().y + _menu[0].getGlobalBounds().height / 2 });

	_textBox.setCharacterSize(25);
	_textBox.setFont(_font);
	_textBox.setFillColor(sf::Color::White);
	_textBox.setString(" ");
	_textBox.setPosition(_spriteHPdyvir.getPosition().x + 220, _spriteHPdyvir.getPosition().y);
}

void MenuFight::updateSpriteHPdyvir(int HP, int HPbase) {
	_resultBars = HP * 100 / HPbase;
	if (_resultBars < 80 && _resultBars > 60) {
		_statusHPdyvir = 2;
	}
	if (_resultBars <= 60 && _resultBars > 40) {
		_statusHPdyvir = 3;
	}
	if (_resultBars <= 40 && _resultBars > 20) {
		_statusHPdyvir = 4;
	}
	if (_resultBars <= 20 && _resultBars > 0) {
		_statusHPdyvir = 5;
	}
	if (_resultBars == 0) {
		_statusHPdyvir = 2;
	}
	_lenghtHPdyvir = _resultBars * spriteSize.x / 100;
	_spriteHPFilldyvir.setTextureRect({ 0, spriteSize.y * _statusHPdyvir, _lenghtHPdyvir, spriteSize.y });
}

void MenuFight::updateSpriteMPdyvir(int MP, int MPbase) {
	_resultBars = MP * 100 / MPbase;
	_lenghtMPdyvir = _resultBars * spriteSize.x / 100;
	_spriteMPFilldyivir.setTextureRect({ 0, spriteSize.y * 6, _lenghtMPdyvir, spriteSize.y });
}

void MenuFight::updateSpriteHPenemy(int HP, int HPbase) {
	_resultBars = HP * 100 / HPbase;
	if (_resultBars < 80 && _resultBars > 60) {
		_statusHPenemy = 2;
	}
	if (_resultBars <= 60 && _resultBars > 40) {
		_statusHPenemy = 3;
	}
	if (_resultBars <= 40 && _resultBars > 20) {
		_statusHPenemy = 4;
	}
	if (_resultBars <= 20 && _resultBars > 0) {
		_statusHPenemy = 5;
	}
	if (_resultBars == 0) {
		_statusHPenemy = 2;
	}
	_lenghtHPenemy = _resultBars * spriteSize.x / 100;
	_spriteHPFillenemy.setTextureRect({ 0, spriteSize.y * _statusHPenemy, _lenghtHPenemy, spriteSize.y });
}

void MenuFight::setOption(turns option) {
	_option = option;
}

void MenuFight::setTextBoxString(turns option, int dmg) {
	switch (option) {
	case attack:
		_textBox.setString(L"Hiciste " + std::to_wstring(dmg) + L" puntos de daño");
		break;
	case enemyAttack:
		_textBox.setString(L"Te hicieron " + std::to_wstring(dmg) + L" puntos de daño");
	}
}

void MenuFight::setTextBoxString(turns option, int dmg, std::string string) {

}

void MenuFight::MoveUp() {
	if (_selectedItemIndex - 1 >= 0) {
		_menu[_selectedItemIndex].setFillColor(sf::Color::White);
		_selectedItemIndex--;
		_menu[_selectedItemIndex].setFillColor(sf::Color::Red);
		_cursor.setPosition({ _menu[_selectedItemIndex].getPosition().x + 10 + _menu[_selectedItemIndex].getGlobalBounds().width, _menu[_selectedItemIndex].getPosition().y + _menu[_selectedItemIndex].getGlobalBounds().height / 2 });
	}
}

void MenuFight::MoveDown() {
	if (_selectedItemIndex + 1 < _menu.size()) {
		_menu[_selectedItemIndex].setFillColor(sf::Color::White);
		_selectedItemIndex++;
		_menu[_selectedItemIndex].setFillColor(sf::Color::Red);
		_cursor.setPosition({ _menu[_selectedItemIndex].getPosition().x + 10 + _menu[_selectedItemIndex].getGlobalBounds().width, _menu[_selectedItemIndex].getPosition().y + _menu[_selectedItemIndex].getGlobalBounds().height / 2 });
	}
}

turns MenuFight::update(Dragon& dyvir, Dragon& enemy) {
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
	//sf::Text text;
	//text.getString();
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
		if (_flag) {
			switch (this->GetPressedItem()) {
			case 0:
				std::cout << "Se presionó el botón ATACK" << std::endl << std::endl;
				_option = attack;
				break;
			case 1:
				std::cout << "Se presionó el botón HABILIDAD 1" << std::endl << std::endl;
				_option = ability1;
				break;
			case 2:
				std::cout << "Se presionó el botón ESCAPE" << std::endl << std::endl;
				_option = ability2;
				break;
			}
			_flag = false;
		}
	}
	else {
		_flag = true;
		_option = wait;
	}
	this->updateSpriteHPdyvir(dyvir.getHP(), dyvir.getHPbase());
	this->updateSpriteMPdyvir(dyvir.getMP(), dyvir.getMPbase());
	this->updateSpriteHPenemy(enemy.getHP(), enemy.getHPbase());
	return _option;
}
void MenuFight::chargeText(int pos) {
	_textBoxAux.setString(_textBox.getString().substring(pos));
}

void MenuFight::draw(sf::RenderTarget& target, sf::RenderStates states) const {

	target.draw(_backMenu);
	target.draw(_backMenuEnemy);
	target.draw(_spriteHPdyvir);
	target.draw(_spriteHPFilldyvir);
	target.draw(_textHPdyvir);
	target.draw(_spriteHPenemy);
	target.draw(_spriteHPFillenemy);
	target.draw(_spriteMPdyvir);
	target.draw(_spriteMPFilldyivir);
	target.draw(_textMPdyvir);
	target.draw(_textHPenemy);
	target.draw(_textBox);
	//TODO ver qué hacer con textBoxAux - Lucas
	
	for (int i = 0; i < _menu.size(); i++) {
		target.draw(_menu[i], states);
	}
	for (int i = 0; i < _dragonNames.size(); i++) {
		target.draw(_dragonNames[i], states);
	}
	target.draw(_cursor, states);
}

MenuFight::~MenuFight() {
	std::cout << "se murió" << std::endl << std::endl;
}