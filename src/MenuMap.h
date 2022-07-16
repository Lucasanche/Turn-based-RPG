#ifndef MENUMAP_H
#define MENUMAP_H

#include "Cursor.h"
#include "DyvirFight.h"


class MenuMap : public sf::Drawable
{
private:
	int _page;
	int _abilitySelect;
	bool _flag, _flagSubmenu;
	int _option;
	int _selectedItemIndex;
	int _selectedItemAux;
	sf::Font _font;
	sf::Text* _menu;
	sf::Text* _names;
	std::vector <sf::Text> _inventoryList;
	Cursor _cursor;
	sf::Sprite _backMenu;
	sf::Texture _backMenuTexture;
	float _posIniMenu;
	int _posMaxMenu;
	int sizeOfMenu;
	DyvirFight dyvir;
public:
	MenuMap(float width, float height, DyvirFight&);
	void MoveUp();
	void MoveDown();
	void setOption(int option);
	void PageUp();
	void PageDown();
	void update(DyvirFight& dyvir);
	int GetPressedItem() { return _selectedItemIndex; }
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void changeMenu();
	~MenuMap();
};

#endif
