#include "stdafx.h"
#include "MenuFight.h"



MenuFight::MenuFight(float width, float height, Dragon& dyvir)
{
	_menu = new sf::Text[3];
	_names = new sf::Text[2];
	_flag = false;
	_option = 0;
	if (!_font.loadFromFile("Nostalgia.ttf"))
	{
		std::cout<<"No se pudo cargar el archivo Nostalgia.ttf";
	}

	if (!_backMenuTexture.loadFromFile("interface/mFightPrincipal.png")) {
		std::cout << "No se pudo cargar mFightPrincipal.png" << std::endl;
	}
	if (!_backMenuEnemyTexture.loadFromFile("interface/mFightEnemy.png")) {
		std::cout << "No se pudo cargar mFightEnemy.png" << std::endl;
	}

	_backMenu.setTexture(_backMenuTexture);
	_backMenu.setPosition(0, height - _backMenu.getGlobalBounds().height);
	_backMenuEnemy.setTexture(_backMenuEnemyTexture);
	_backMenuEnemy.setPosition(width - _backMenuEnemy.getGlobalBounds().width, 0);

	_selectedItemIndex = 0;

	
	///Variables útiles para los sprites
	 // Setea el color del relleno del HP
	_statusHPdyvir = 2;
	_statusHPenemy = 2;
	//Barra de vida
	_textureHP.loadFromFile("HP-bar.png");

	_spriteHPdyvir.setTexture(_textureHP);
	_spriteHPdyvir.setTextureRect({ 0,0,159,17 });
	_spriteHPdyvir.setPosition(_backMenu.getPosition().x + 40,_backMenu.getPosition().y + 50 );
	_spriteHPFilldyvir.setTexture(_textureHP);
	_spriteHPFilldyvir.setTextureRect({ 0,17 * _statusHPdyvir,160,17 });
	_spriteHPFilldyvir.setPosition(_spriteHPdyvir.getPosition());
	_textHPdyvir.setTexture(_textureHP);
	_textHPdyvir.setPosition(_spriteHPdyvir.getPosition());
	_textHPdyvir.setTextureRect({ 0, 17, 160, 17 });

	_spriteHPenemy.setTexture(_textureHP);
	_spriteHPenemy.setTextureRect({ 0,0,159,17 });
	_spriteHPenemy.setPosition(_backMenuEnemy.getPosition().x + 30, _backMenuEnemy.getPosition().y + 57 );
	_spriteHPFillenemy.setTexture(_textureHP);
	_spriteHPFillenemy.setTextureRect({ 0,17 * _statusHPenemy,160,17 });
	_spriteHPFillenemy.setPosition(_spriteHPenemy.getPosition());
	_textHPenemy.setTexture(_textureHP);
	_textHPenemy.setPosition(_spriteHPenemy.getPosition());
	_textHPenemy.setTextureRect({ 0, 17, 160, 17 });

	_posIniMenu = _spriteHPdyvir.getPosition().y + 27;
	_posMaxMenu = 120;
	// Setea el largo del relleno del HP
	_lenghtHPenemy = _spriteHPenemy.getGlobalBounds().width;
	_lenghtHPdyvir = _spriteHPdyvir.getGlobalBounds().width;

	_names[0].setCharacterSize(25);
	_names[0].setFont(_font);
	_names[0].setFillColor(sf::Color::White);
	_names[0].setStyle(sf::Text::Italic);
	_names[0].setString("DYVIR");
	_names[0].setPosition({ _spriteHPdyvir.getPosition().x + _spriteHPdyvir.getGlobalBounds().width/3, _spriteHPdyvir.getPosition().y - 30});

	_names[1].setCharacterSize(25);
	_names[1].setFont(_font);
	_names[1].setFillColor(sf::Color::White);
	_names[1].setStyle(sf::Text::Italic);
	_names[1].setString("ENEMY");
	_names[1].setPosition({ _spriteHPenemy.getPosition().x + _spriteHPenemy.getGlobalBounds().width/3, _spriteHPenemy.getPosition().y - 40});

	_menu[0].setCharacterSize(25);
	_menu[0].setFont(_font);
	_menu[0].setFillColor(sf::Color::Red);
	_menu[0].setString("Attack");
	_menu[0].setPosition({ 35, _posIniMenu});

	_menu[1].setCharacterSize(25);
	_menu[1].setFont(_font);
	_menu[1].setFillColor(sf::Color::White);
	//_menu[1].setString(/*dyvir.getAbility1().getName()*/);
	_menu[1].setPosition(35, _posIniMenu + (_posMaxMenu * 1 / 3));

	_menu[2].setCharacterSize(25);
	_menu[2].setFont(_font);
	_menu[2].setFillColor(sf::Color::White);
	_menu[2].setString("Magic 2");
	_menu[2].setPosition(35, _posIniMenu + (_posMaxMenu * 2 / 3));
	_cursor.setPosition({ _menu[0].getPosition().x + 10 + _menu[0].getGlobalBounds().width,_menu[0].getPosition().y + _menu[0].getGlobalBounds().height / 2 });
}

void MenuFight::updateSpriteHPdyvir(int HP)
{
		if (HP < 80 && HP > 60) {
			_statusHPdyvir = 2;
		}
		if (HP <= 60 && HP > 40) {
			_statusHPdyvir = 3;
		}
		if (HP <= 40 && HP > 20) {
			_statusHPdyvir = 4;
		}
		if (HP <= 20 && HP > 0) {
			_statusHPdyvir = 5;
		}
		if (HP == 0) {
			_statusHPdyvir = 2;
		}
		_lenghtHPdyvir = HP * 1.6;

		_spriteHPFilldyvir.setTextureRect({ 0,17 * _statusHPdyvir,_lenghtHPdyvir,17 });
}

void MenuFight::updateSpriteHPenemy(int HP)
{
	if (HP < 80 && HP > 60) {
		_statusHPenemy = 2;
	}
	if (HP <= 60 && HP > 40) {
		_statusHPenemy = 3;
	}
	if (HP <= 40 && HP > 20) {
		_statusHPenemy = 4;
	}
	if (HP <= 20 && HP > 0) {
		_statusHPenemy = 5;
	}
	if (HP == 0) {
		_statusHPenemy = 2;
	}
	_lenghtHPenemy = HP * 1.6;

	_spriteHPFillenemy.setTextureRect({ 0,17 * _statusHPenemy,_lenghtHPenemy,17 });
}

void MenuFight::setOption(int option) {
	_option = option;
}

void MenuFight::MoveUp()
{
	if (_selectedItemIndex - 1 >= 0)
	{
		_menu[_selectedItemIndex].setFillColor(sf::Color::White);
		_selectedItemIndex--;
		_menu[_selectedItemIndex].setFillColor(sf::Color::Red);
		_cursor.setPosition({ _menu[_selectedItemIndex].getPosition().x + 10 + _menu[_selectedItemIndex].getGlobalBounds().width, _menu[_selectedItemIndex].getPosition().y + _menu[_selectedItemIndex].getGlobalBounds().height / 2 });
	}
}

void MenuFight::MoveDown()
{
	if (_selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		_menu[_selectedItemIndex].setFillColor(sf::Color::White);
		_selectedItemIndex++;
		_menu[_selectedItemIndex].setFillColor(sf::Color::Red);
		_cursor.setPosition({ _menu[_selectedItemIndex].getPosition().x + 10  + _menu[_selectedItemIndex].getGlobalBounds().width, _menu[_selectedItemIndex].getPosition().y + _menu[_selectedItemIndex].getGlobalBounds().height / 2 });
	}
}

int MenuFight::update(int dyvirHP, int enemyHP, bool turn)
{
	if (turn) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (_flag) {
				this->MoveUp();
				_flag = false;
			}
		}
		sf::Text text;
		text.getString();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
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
	}
	
	this->updateSpriteHPdyvir(dyvirHP);
	this->updateSpriteHPenemy(enemyHP);
	return _option;
}

void MenuFight::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_backMenu);
	target.draw(_backMenuEnemy);
	target.draw(_spriteHPdyvir);
	target.draw(_spriteHPFilldyvir);
	target.draw(_textHPdyvir);
	target.draw(_spriteHPenemy);
	target.draw(_spriteHPFillenemy);
	target.draw(_textHPenemy);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
		{
		target.draw(_menu[i], states);
		}
	for (int i = 0; i < 2; i++)
	{
		target.draw(_names[i], states);
	}
	target.draw(_cursor, states);
}

MenuFight::~MenuFight()
{
	std::cout << "se murió" << std::endl << std::endl;
}