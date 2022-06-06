#pragma once
#include <SFML/Graphics.hpp>
#include "Cursor.h"
#include <iostream>

#define MAX_NUMBER_OF_ITEMS 3

class MenuFight : public sf::Drawable
{
private:
	int _option;
	bool _flag;
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	Cursor cursed;

public:
	MenuFight(float width, float height);
	//void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	void update(sf::Event& event);
	int GetPressedItem() { return selectedItemIndex; }
	int getOption() { return _option; }
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	~MenuFight();
};
