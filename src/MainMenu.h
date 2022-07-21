#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H
#define MAX_NUMBER_OF_ITEMS 3

class mainMenu : public sf::Drawable
{
private:
	int _option;
	bool _flag;
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
public:
	mainMenu(float width, float height);
	void MoveUp();
	void MoveDown();
	void update();
	int GetPressedItem() { return selectedItemIndex; }
	int getOption() { return _option; }
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	~mainMenu();
};

#endif