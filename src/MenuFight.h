#pragma once
#ifndef MENUFIGHT_H
#define MENUFIGHT_H
#include "Cursor.h"
#include "Dragon.h"

#define MAX_NUMBER_OF_ITEMS 3

class MenuFight : public sf::Drawable
{
private:
	bool _flag;
	turns _option;
	int _selectedItemIndex;
	sf::Font _font;
	sf::Text* _menu;
	sf::Text* _names;
	Cursor _cursor;
	sf::Sprite _backMenu;
	sf::Texture _backMenuTexture;
	sf::Sprite _backMenuEnemy;
	sf::Texture _backMenuEnemyTexture;
	//Textura barra de vida
	sf::Texture _textureHP;
	//Barra de vida Dyvir
	sf::Sprite _spriteHPdyvir;
	sf::Sprite _spriteHPFilldyvir;
	sf::Sprite _textHPdyvir;
	int _statusHPdyvir;
	int _lenghtHPdyvir;
	//Barra de vida enemy
	sf::Texture _textureHPenemy;
	sf::Sprite _spriteHPenemy;
	sf::Sprite _spriteHPFillenemy;
	sf::Sprite _textHPenemy;
	int _statusHPenemy;
	int _lenghtHPenemy;
	float _posIniMenu;
	int _posMaxMenu;
public:
	MenuFight(float width, float height, Dragon& dyvir);
	void updateSpriteHPdyvir(int);
	void updateSpriteHPenemy(int);
	void MoveUp();
	void MoveDown();
	void setOption(turns option);
	turns update(int, int);
	int GetPressedItem() { return _selectedItemIndex; }
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	~MenuFight();
};

#endif