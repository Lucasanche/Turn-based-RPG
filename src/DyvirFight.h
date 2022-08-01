#pragma once
#ifndef DYVIRFIGHT_H
#define DYVIRFIGHT_H

#include "Dragon.h"
#include "Ability.h"


class DyvirFight : public Dragon
{
private:
	unsigned short _wins;
	std::vector <Ability> _abilityInventory;
	unsigned short _level;
	sf::Texture _deathTexture;
	sf::Texture _winTexture;
	unsigned int _XPrequired[20] = {200, 500, 900, 1400, 2000, 2800, 3800, 5100, 6700, 8700, 11100, 13900, 17400, 21400, 25900, 31100, 37100, 44300, 52700, 62700 };
public:
	DyvirFight();
	//Gets
	unsigned short getWins() { return _wins; }
	unsigned short getLevel() { return _level; }
	int getInventorySize() { return int(_abilityInventory.size()); }
	Ability getInventoryElement(int i) { return _abilityInventory[i]; }
	sf::String getInventoryElementName(int i);
	sf::String getInventoryElementDescription(int i);
	std::vector<Ability> getInventory() { return _abilityInventory; }

	//Sets
	void setWins(int wins) { _wins = wins; }
	void setStats(int HP, int MP, int physicalDamage, int magicDamage, int physicalResistance, int magicResist);
	void setLevel(unsigned short level) { _level = level; }
	sf::String setAbilityEquipedElement(int i, int ability);
	void setAbilityEquiped(Ability ability, int pos);
	void setInventory(std::vector <Ability> abilityInventory) { _abilityInventory = abilityInventory; }
	void setFightSprite();

	//Functions
	void updateSpriteStates(sf::RenderWindow& window) override;
	void increaseWins() { _wins++; }
	bool craftAbility(sf::String, sf::String, int, int);
	void update(bool, int) override;
	void getAbilityDrop(abilityName abilityDrop);
	void Die() override;
	void Win(int enemyXP);
	sf::String increaseXP(unsigned int XP);
	void levelUp(int level);
	void restoreLife();
	
};

#endif
