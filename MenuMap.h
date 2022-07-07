#ifndef MENUMAP_H
#define MENUMAP_H
#include "Cursor.h"
#include "DyvirFight.h"

class MenuMap : public sf::Drawable
{
private:
	bool _flag, _flagSubmenu;
	int _option;
	int _selectedItemIndex;
	int _selectedItemAux;
	sf::Font _font;
	sf::Text* _menu;
	sf::Text* _names;
	sf::Text* _inventoryList;
	Cursor _cursor;
	sf::Sprite _backMenu;
	sf::Texture _backMenuTexture;
	float _posIniMenu;
	int _posMaxMenu;
	int sizeOfMenu;
	int sizeOfList;
public:
	MenuMap(float width, float height, Dyvirfight);
	void MoveUp();
	void MoveDown();
	void setOption(int option);
	void update();
	int GetPressedItem() { return _selectedItemIndex; }
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void changeMenu();
	~MenuMap();
};


#endif // MENUMAP_H
