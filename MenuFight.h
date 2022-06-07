#pragma once
#include <SFML/Graphics.hpp>
#include "Cursor.h"
#include <iostream>
#include "Fight.h"

#define MAX_NUMBER_OF_ITEMS 3

class MenuFight : public sf::Drawable
{
private:
	bool _flag;
	int _option;
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	Cursor cursor;

public:
	MenuFight(float width, float height);
	void MoveUp();
	void MoveDown();
	void setOption(int option);
	int update();
	int GetPressedItem() { return selectedItemIndex; }
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	~MenuFight();
};
