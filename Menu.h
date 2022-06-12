#pragma once
#include <SFML/Graphics.hpp>
#include "iostream"

#define MAX_NUMBER_OF_ITEMS 3

class Menu : public sf::Drawable
{
private:
	int _option;
	bool _flag;
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
public:
	Menu(float width, float height);
	void MoveUp();
	void MoveDown();
	void update();
	int GetPressedItem() { return selectedItemIndex; }
	int getOption() { return _option; }
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	~Menu();
};
