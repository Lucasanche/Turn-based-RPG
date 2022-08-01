#pragma once
#ifndef MENUFIGHT_H
#define MENUFIGHT_H

#include "Cursor.h"
#include "Dragon.h"

class MenuFight : public sf::Drawable
{
private:
	bool _flag;
	turns _option;
	int _selectedItemIndex;
	int _resultBars;
	sf::Font _font;
	std::vector<sf::Text> _menu;
	sf::Text _textBox;
	sf::Text _enemyName;
	std::vector<sf::String> _menuStrings;
	Cursor _cursor;
	std::vector<sf::Texture> _texturesv;
	//Barra de vida Dyvir
	sf::Texture _HPMPtexture;
	sf::Sprite _spriteHPFilldyvir;
	sf::Sprite _textHPdyvir;
	sf::Sprite _spriteMPFilldyvir;
	sf::Sprite _textMPdyvir;
	sf::Sprite _spriteHPFillenemy;
	sf::Sprite _textHPenemy;
	int _statusHPdyvir;
	int _lenghtHPdyvir;
	int _lenghtMPdyvir;
	int _statusHPenemy;
	int _lenghtHPenemy;
	sf::Sprite _menuFightBackground;
	sf::Texture _menuFightBackgroundTexture;
	sf::Vector2i _hpSpriteSize;
	int _posIniMenu;
	int _posMaxMenu;
public:
	MenuFight(float width, float height, Dragon& dyvir);
	void updateSpriteHPdyvir(int, int);
	void updateSpriteHPenemy(int, int);
	void updateSpriteMPdyvir(int, int);
	void MoveUp();
	void MoveDown();
	void setOption(turns option);
	void setTextBoxString(turns option, int dmg);
	void setTextBoxString(turns option, int dmg, sf::String string);
	turns update(Dragon& dyvir, Dragon& enemy);
	int GetPressedItem() { return _selectedItemIndex; }
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	~MenuFight();
};

#endif