#ifndef MENUMAP_H
#define MENUMAP_H

#include "Cursor.h"
#include "DyvirFight.h"
#include "SaveGame.h"
#include "DyvirMap.h"


class MenuMap : public sf::Drawable
{
private:
	enum class MenuOption
	{
		MainMenu = 0,
		AbilityChange,
		Craft,
		Craft2,
		Save
	};
	int _page;
	SaveGame _save;
	int _abilitySelect;
	bool _flag, _flagSubmenu;
	int _optionAbility;
	int _optionMenu;
	int _selectedItemIndex;
	int _selectedItemAux;
	int _selectedItemCraft;
	int _pageAux;
	sf::Font _font;
	std::vector<sf::Text>_menu;
	std::vector<sf::Text>_names;
	std::vector<sf::Text>_slots;
	sf::Text _description;
	sf::Text _saveText;
	std::vector <sf::Text> _inventoryList;
	Cursor _cursor;
	sf::Sprite _backMenu;
	sf::Sprite _backMenu2;
	sf::Texture _backMenuTexture;
	sf::Texture _backMenuTexture2;
	float _posIniMenu;
	int _posMaxMenu;
	bool _checkPoint;
	bool _flagSave;
	DyvirFight dyvir;
	MenuOption _menuOption;
public:
	MenuMap(float width, float height, DyvirFight&);
	void MoveUp();
	void MoveDown();
	void setOption(int option);
	void PageUp();
	void PageDown();
	void update(DyvirFight& dyvir, bool, DyvirMap&);
	int GetPressedItem() { return _selectedItemIndex; }
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void changeMenu();
	void ResetColor();
	void ResetCursor();
	~MenuMap();
};

#endif
