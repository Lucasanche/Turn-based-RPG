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
	errno_t _err;
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
		_level = fightAux.getLevel();
		_wins = fightAux.getWins();
		_position = mapAux.getPosition();
		_err = fopen_s(&p, "saves/savegame", "wb");
		switch (option) {
		case 0:
			_err = fopen_s(&p, "/saves/SaveGame1.dat", "wb");
			break;
		case 1:
			_err = fopen_s(&p, "/saves/SaveGame2.dat", "wb");
			break;
		case 2:
			_err = fopen_s(&p, "/saves/SaveGame3.dat", "wb");
			break;
		}
		if (_err == 0) {
			fwrite(this, sizeof(this), 1, p);
			if (p) {
				_err = fclose(p);
				return true;
			}
			else {
				return false;
			}
		}
		else { return false; }
	}

	bool loadGame(DyvirMap mapAux, DyvirFight fightAux, int option) {
		FILE* p;
		switch (option) {
		case 0:
			_err = fopen_s(&p, "/saves/SaveGame1.dat", "rb");
			break;
		case 1:
			_err = fopen_s(&p, "/saves/SaveGame2.dat", "rb");

			break;
		case 2:
			_err = fopen_s(&p, "/savesSaveGame3.dat", "rb");
			break;
		}
		if (_err == 0) {
			fread(this, sizeof(this), 1, p);

		}
		else { return false; }
		fightAux.setStats(_HPbase, _MPbase, _physicalDamagebase, _magicalDamagebase, _physicalDefensebase, _magicResistbase, _XP);
		fightAux.setLevel(_level);
		fightAux.setInventory(_inventory);
		fightAux.setWins(_wins);
		fightAux.setAbilityEquiped(_abilityEquiped);
		mapAux.setPosition(_position);
		if (p) {
			_err = fclose(p);
			return true;
		}
		else {
			return false;
		}
	}
};

