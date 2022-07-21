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
	std::vector<sf::Text> _dragonNames;
	std::vector<sf::String> _menuStrings;
	sf::Text _textBox;
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
	//Barra MP Dyvir
	sf::Sprite _spriteMPdyvir;
	sf::Sprite _spriteMPFilldyivir;
	sf::Sprite _textMPdyvir;
	int _lenghtMPdyvir;
	//Barra de vida enemy
	sf::Texture _textureHPenemy;
	sf::Sprite _spriteHPenemy;
	sf::Sprite _spriteHPFillenemy;
	sf::Sprite _textHPenemy;

	//States
	sf::Texture _textureStates;
	sf::Sprite _spriteStunDyvir;
	sf::Sprite _spriteBleedingDyvir;
	sf::Sprite _spriteBurnsDyvir;
	sf::Sprite _spritePoisonedDyvir;
	sf::Sprite _spritePRincreaseDyvir;
	sf::Sprite _spriteMDincreaseDyvir;
	sf::Sprite _spritePDincreaseDyvir;
	sf::Sprite _spriteMRincreaseDyvir;
	sf::Sprite _spritePRdecreaseDyvir;
	sf::Sprite _spriteMDdecreaseDyvir;
	sf::Sprite _spritePDdecreaseDyvir;
	sf::Sprite _spriteMRdecreaseDyvir;
	sf::Sprite _spriteDamageMultiplierDyvir;
	
	int _statusHPenemy;
	int _lenghtHPenemy;
	sf::Vector2i spriteSize;
	sf::Vector2f positionHPdyvir;
	sf::Vector2f positionHPenemy;
	float _posIniMenu;
	int _posMaxMenu;
public:
	MenuFight(float width, float height, Dragon& dyvir);
	void updateSpriteHPdyvir(int, int);
	void updateSpriteHPenemy(int, int);
	void updateSpriteMPdyvir(int, int);
	void updateStatesSprites(std::vector<bool> _negativeStates, std::vector<bool> _positiveStates);
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