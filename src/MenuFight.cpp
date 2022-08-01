#include "stdafx.h"
#include "MenuFight.h"


MenuFight::MenuFight(float width, float height, Dragon& dyvir) : _menu(4), _menuStrings(4) {
	_resultBars = 0;
	_lenghtHPdyvir = 0;
	_lenghtMPdyvir = 0;
	_lenghtHPenemy = 0;
	_lenghtHPdyvir = 0;
	_flag = false;
	_option = wait;

	_font.loadFromFile("./Fonts/Nostalgia.ttf");
	if (!_menuFightBackgroundTexture.loadFromFile("./Textures/Interface/MenuFightBack.png")) {
		std::cout << "no se pudo cargar MenuFightBack.png \n";
	}
	_menuFightBackground.setTexture(_menuFightBackgroundTexture);
	sf::Vector2f spriteHPpos = { 31, height - 171 };
	sf::Vector2f spriteHPenemypos = { 621 , 39 };
	_selectedItemIndex = 0;
	_statusHPdyvir = 1;
	_statusHPenemy = 1;
	_HPMPtexture.loadFromFile("./Textures/Interface/HP_bar.png");

	//Barra de MP y HP
	_hpSpriteSize = { 158,15 };
	_spriteHPFilldyvir.setTexture(_HPMPtexture);
	_spriteMPFilldyvir.setTexture(_HPMPtexture);
	_textHPdyvir.setTexture(_HPMPtexture);
	_textMPdyvir.setTexture(_HPMPtexture);
	_spriteHPFillenemy.setTexture(_HPMPtexture);
	_textHPenemy.setTexture(_HPMPtexture);
	_spriteHPFilldyvir.setTextureRect({ {0, _hpSpriteSize.y * 1 }, _hpSpriteSize });
	_spriteHPFilldyvir.setPosition(spriteHPpos);
	_textHPdyvir.setTextureRect({ {0, _hpSpriteSize.y * 8 }, _hpSpriteSize });
	_textHPdyvir.setPosition(_spriteHPFilldyvir.getPosition());
	_spriteMPFilldyvir.setTextureRect({ {0, _hpSpriteSize.y * 6 }, _hpSpriteSize });
	_spriteMPFilldyvir.setPosition(spriteHPpos.x, spriteHPpos.y + 21);
	_textMPdyvir.setTextureRect({ {0, _hpSpriteSize.y * 7 }, _hpSpriteSize });
	_textMPdyvir.setPosition(_spriteMPFilldyvir.getPosition());

	_spriteHPFillenemy.setTextureRect({ {0, _hpSpriteSize.y * _statusHPenemy }, _hpSpriteSize });
	_spriteHPFillenemy.setPosition(spriteHPenemypos);
	_textHPenemy.setPosition(spriteHPenemypos);
	_textHPenemy.setTextureRect({ {0, _hpSpriteSize.y * 8 }, _hpSpriteSize });
	_posIniMenu = spriteHPpos.y + 40;
	_posMaxMenu = 115;

	_enemyName.setCharacterSize(25);
	_enemyName.setFont(_font);
	_enemyName.setFillColor(sf::Color::White);
	_enemyName.setStyle(sf::Text::Italic);
	_enemyName.setString("ENEMY");
	_enemyName.setPosition({ spriteHPenemypos.x + 50 , spriteHPenemypos.y - 34 });
	
	_menuStrings[0] = "Atacar";
	_menuStrings[1] = "Habilidad 1";
	_menuStrings[2] = "Habilidad 2";
	_menuStrings[3] = "Habilidad 3";

	for (int i = 0; i < _menu.size(); i++) {
		_menu[i].setCharacterSize(25);
		_menu[i].setFont(_font);
		_menu[i].setFillColor(sf::Color::White);
		_menu[i].setString(_menuStrings[i]);
		_menu[i].setPosition(35, _posIniMenu + (_posMaxMenu * i / _menu.size()));
	}

	_menu[0].setFillColor(sf::Color::Red);
	_cursor.setPosition({ _menu[0].getPosition().x + 10 + _menu[0].getGlobalBounds().width,_menu[0].getPosition().y + _menu[0].getGlobalBounds().height / 2 });

	_textBox.setCharacterSize(25);
	_textBox.setFont(_font);
	_textBox.setFillColor(sf::Color::White);
	_textBox.setString(" ");
	_textBox.setPosition(spriteHPpos.x + 220, spriteHPpos.y);
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
	_lenghtHPdyvir = _resultBars * _hpSpriteSize.x / 100;
	_spriteHPFilldyvir.setTextureRect({ 0, _hpSpriteSize.y * _statusHPdyvir, _lenghtHPdyvir, _hpSpriteSize.y });
}

void MenuFight::updateSpriteMPdyvir(int MP, int MPbase) {
	_resultBars = MP * 100 / MPbase;
	_lenghtMPdyvir = _resultBars * _hpSpriteSize.x / 100;
	_spriteMPFilldyvir.setTextureRect({ 0, _hpSpriteSize.y * 6, _lenghtMPdyvir, _hpSpriteSize.y });
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
	_lenghtHPenemy = _resultBars * _hpSpriteSize.x / 100;
	_spriteHPFillenemy.setTextureRect({ 0, _hpSpriteSize.y * _statusHPenemy, _lenghtHPenemy, _hpSpriteSize.y });
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

void MenuFight::draw(sf::RenderTarget& target, sf::RenderStates states) const {

	target.draw(_menuFightBackground);
	target.draw(_spriteHPFilldyvir);
	target.draw(_textHPdyvir);
	target.draw(_spriteHPFillenemy);
	target.draw(_spriteMPFilldyvir);
	target.draw(_textMPdyvir);
	target.draw(_textHPenemy);
	target.draw(_textBox);
	target.draw(_enemyName);
	
	for (int i = 0; i < _menu.size(); i++) {
		target.draw(_menu[i], states);
	}
	target.draw(_cursor, states);
}
void MenuFight::setTextBoxString(turns option, int dmg, sf::String string) {

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
				std::cout << "Se presionó el botón ATTACK" << std::endl << std::endl;
				_option = attack;
				break;
			case 1:
				std::cout << "Se presionó el botón HABILIDAD 1" << std::endl << std::endl;
				_option = ability1;
				break;
			case 2:
				std::cout << "Se presionó el botón HABILIDAD 2" << std::endl << std::endl;
				_option = ability2;
				break;
			case 3:
				std::cout << "Se presionó el botón HABILIDAD 3" << std::endl << std::endl;
				_option = ability3;
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


MenuFight::~MenuFight() {
	std::cout << "se murió" << std::endl << std::endl;
}