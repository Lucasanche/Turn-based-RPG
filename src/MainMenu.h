#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H

class mainMenu : public sf::Drawable
{
private:
	unsigned short _option;
	bool _flag;
	int selectedItemIndex;
	sf::Font _font;
	std::vector<sf::Text> _menu;
public:
	mainMenu(float width, float height);
	void MoveUp();
	void MoveDown();
	int update();
	void setOption(int option) { _option = option; }
	void setMainMenu();
	int getLoadGameIndex() { return selectedItemIndex+1; }
	void setErrorLoadGame();
	void resetIndex();
	int GetPressedItem() { return selectedItemIndex; }
	int getOption() { return _option; }
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	~mainMenu();
};

#endif