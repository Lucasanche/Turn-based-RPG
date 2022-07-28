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
	sf::Text _enemyName;
	std::vector<sf::String> _menuStrings;
	sf::Text _textBox;
	Cursor _cursor;
	std::vector<sf::Texture> _texturesv;
	sf::Texture _HPMPtexture;
	sf::Texture _fightMenuTexture;
	sf::Texture _fightMenuEnemyTexture;
	//Barra de vida Dyvir
	/*sf::Sprite _spriteHPdyvir;*/
	sf::Sprite _spriteHPFilldyvir;
	sf::Sprite _textHPdyvir;
	int _statusHPdyvir;
	int _lenghtHPdyvir;

	//Experimento
	sf::Sprite _menuFightBack;
	sf::Texture _menuFightBackTexture;
	sf::Sprite _HPMPbar;
	sf::Sprite _HPMPfill;
	sf::Sprite _HPMPtext;
	//Barra MP Dyvir
	/*sf::Sprite _spriteMPdyvir;*/
	sf::Sprite _spriteMPFilldyvir;
	sf::Sprite _textMPdyvir;
	int _lenghtMPdyvir;
	//Barra de vida enemy
	sf::Sprite _spriteHPMP;
	sf::Sprite _spriteHPFillenemy;
	sf::Sprite _textHPenemy;
	int _statusHPenemy;
	int _lenghtHPenemy;
	sf::Vector2i spriteSize;
	float _posIniMenu;
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
	void setTextBoxString(turns option, int dmg, std::string string);
	turns update(Dragon& dyvir, Dragon& enemy);
	int GetPressedItem() { return _selectedItemIndex; }
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	~MenuFight();
};

#endif