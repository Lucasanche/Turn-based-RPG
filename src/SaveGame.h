#pragma once
#include "DyvirFight.h"
#include "DyvirMap.h"

class SaveGame
{
private:
	unsigned int _XP;
	unsigned short _level;
	unsigned short _wins;
	std::vector <Ability> _inventory;
	Ability _abilityEquiped[3];
	int _HPbase;
	int _MPbase;
	int _physicalDamagebase;
	int _magicalDamagebase;
	int _physicalDefensebase;
	int _magicResistbase;
	sf::Vector2f _position; // Map
public:
	bool saveGame(DyvirMap mapAux, DyvirFight fightAux, int option) {
		FILE* p;
		_inventory = fightAux.getInventory();
		_HPbase = fightAux.getHPbase();
		_MPbase = fightAux.getMPbase();
		_physicalDamagebase = fightAux.getPhysicalDamageBase();
		_magicalDamagebase = fightAux.getMagicalDamageBase();
		_physicalDefensebase = fightAux.getPhysicalDefenseBase();
		_magicResistbase = fightAux.getMagicResistBase();
		_XP = fightAux.getXP();
		//_level = fightAux.getLevel();
		_wins = fightAux.getWins();
		_position = mapAux.getPosition();
		switch (option) {
		case 0:
			p = fopen("/saves/SaveGame1.dat", "wb");
			fwrite(this, sizeof(this), 1, p);
			break;
		case 1:
			p = fopen("/saves/SaveGame2.dat", "wb");
			fwrite(this, sizeof(this), 1, p);
			break;
		case 2:
			p = fopen("/savesSaveGame3.dat", "wb");
			fwrite(this, sizeof(this), 1, p);
			break;
		}
	}
	bool loadGame(DyvirMap mapAux, DyvirFight fightAux, int option) {
		FILE* p;
		switch (option) {
		case 0:
			p = fopen("/saves/SaveGame1.dat", "rb");
			fread(this, sizeof(this), 1, p);
			break;
		case 1:
			p = fopen("/saves/SaveGame2.dat", "rb");
			fread(this, sizeof(this), 1, p);
			break;
		case 2:
			p = fopen("/saves/SaveGame3.dat", "rb");
			fread(this, sizeof(this), 1, p);
			break;
		}
		if (p == NULL) {
			return false;
		}
		//fightAux.setStats();
		fightAux.setInventory(_inventory);
		fightAux.setWins(_wins);
		for (int i; i < 3; i++) {
			fightAux.setAbilityEquiped(_abilityEquiped[i], i);
		}
		mapAux.setPosition(_position);
		return true;
	}
};

