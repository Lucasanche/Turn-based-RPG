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
		errno_t err;
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
			err = fopen_s(&p, "/saves/SaveGame1.dat", "wb");
			break;
		case 1:
			err = fopen_s(&p, "/saves/SaveGame2.dat", "wb");
			break;
		case 2:
			err = fopen_s(&p, "/savesSaveGame3.dat", "wb");
			break;
		}
		if (err != 0) {
			fwrite(this, sizeof(this), 1, p);
			return true;
		}
		else { return false; }
	}
	bool loadGame(DyvirMap mapAux, DyvirFight fightAux, int option) {
		errno_t err;
		FILE* p;
		switch (option) {
		case 0:
			err = fopen_s(&p, "/saves/SaveGame1.dat", "rb");
			break;
		case 1:
			err = fopen_s(&p, "/saves/SaveGame2.dat", "rb");

			break;
		case 2:
			err = fopen_s(&p, "/savesSaveGame3.dat", "rb");
			break;
		}
		if (err != 0) {
			fread(this, sizeof(this), 1, p);
		}
		else { return false; }
		//fightAux.setStats();
		//TODO: arreglar todo esto - Lucas
		// fightAux.setInventory(_inventory);
		fightAux.setWins(_wins);
		for (int i; i < 3; i++) {
			//TODO: Arreglar esta función - Lucas
			//fightAux.setAbilityEquiped(_abilityEquiped[i], i);
		}
		mapAux.setPosition(_position);
		return true;
	}
};

