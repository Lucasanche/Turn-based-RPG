#pragma once
#ifndef SAVEGAME_H
#define SAVEGAME_H
#include "DyvirFight.h"
#include "DyvirMap.h"

class SaveGame
{
private:
	int _inventorySize;
	unsigned int _XP;
	unsigned short _level;
	unsigned short _wins;
	unsigned int _HPbase;
	int _MPbase;
	int _physicalDamagebase;
	int _magicDamagebase;
	int _physicalResistancebase;
	int _magicResistancebase;
	sf::Vector2f _position; //Posición en el mapa
	errno_t _err;
	abilityName _inventoryAux;
	abilityName _abilityEquiped[3];
	//std::vector<abilityName> _abilityInventory;
public:
	bool saveGame(DyvirMap& mapAux, DyvirFight& fightAux, int option) {
		FILE* p = nullptr;
		_inventorySize = fightAux.getInventorySize();
		_HPbase = fightAux.getHPbase();
		_MPbase = fightAux.getMPbase();
		_physicalDamagebase = fightAux.getPhysicalDamageBase();
		_magicDamagebase = fightAux.getMagicDamageBase();
		_physicalResistancebase = fightAux.getPhysicalResistanceBase();
		_magicResistancebase = fightAux.getMagicResistanceBase();
		_XP = fightAux.getXP();
		_level = fightAux.getLevel();
		_wins = fightAux.getWins();
		_position = mapAux.getPosition();
		for (int i = 0; i < 3; i++) {
			_abilityEquiped[i] = fightAux.getAbility(i).getID();
		}
		switch (option) {
		case 0:
			_err = fopen_s(&p, "saves/SaveGame1.dat", "wb");
			break;
		case 1:
			_err = fopen_s(&p, "saves/SaveGame2.dat", "wb");
			break;
		case 2:
			_err = fopen_s(&p, "saves/SaveGame3.dat", "wb");
			break;
		}
		std::cout << sizeof(*this) << std::endl;
		if (p != nullptr) {
			if (_err == 0) {
				fwrite(this, sizeof(*this), 1, p);
				for (int i=0; i < _inventorySize; i++) {
					_inventoryAux = fightAux.getInventoryElement(i).getID();
					fwrite(&_inventoryAux, sizeof(abilityName), 1, p);
				}
				_err = fclose(p);
				p = nullptr;
				return true;
			}
		}
		return false;
	}
	bool loadGame(DyvirMap& mapAux, DyvirFight& fightAux, int option) {
		FILE* p = nullptr;
		AbilityFactory abilityFactory;
		std::vector<Ability>inventoryAux;
		std::vector<abilityName>_abilityInventoryNames;
		switch (option) {
		case 1:
			_err = fopen_s(&p, "saves/SaveGame1.dat", "rb");
			break;
		case 2:
			_err = fopen_s(&p, "saves/SaveGame2.dat", "rb");
			break;
		case 3:
			_err = fopen_s(&p, "saves/SaveGame3.dat", "rb");
			break;
		}

		if (p != nullptr) {
			if (_err == 0) {
				fread(this, sizeof(*this), 1, p);
				for (int i = 0; i < _inventorySize; i++) {
					fread(&_inventoryAux, sizeof(int), 1, p);
					_abilityInventoryNames.push_back(_inventoryAux);
				}
				_err = fclose(p);
				p == nullptr;
				fightAux.setStats(_HPbase, _MPbase, _physicalDamagebase, _magicDamagebase, _physicalResistancebase, _magicResistancebase, _XP);
				fightAux.setLevel(_level);
				fightAux.setInventory(inventoryAux);
				fightAux.setWins(_wins);
				for (int i = 0; i < _inventorySize; i++) {
					inventoryAux.push_back(abilityFactory.createAbility(_abilityInventoryNames[i]));
				}
				for (int i = 0; i < 3; i++) {
					fightAux.setAbilityEquiped(abilityFactory.createAbility(_abilityEquiped[i]), i);
				}
				mapAux.setPosition(_position);
				return true;
			}
		}
		return false;
	}
};

#endif