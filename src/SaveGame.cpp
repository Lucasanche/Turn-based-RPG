#include "stdafx.h"
#include "SaveGame.h"

bool SaveGame::saveGame(DyvirMap& mapAux, DyvirFight& fightAux, int option) {
	FILE* p = nullptr;
	errno_t _err;
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
	if (p != nullptr) {
		if (_err == 0) {
			fwrite(this, sizeof(*this), 1, p);
			for (int i = 0; i < _inventorySize; i++) {
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

bool SaveGame::loadGame(DyvirMap& mapAux, DyvirFight& fightAux, int option) {
	FILE* p = nullptr;
	errno_t _err;
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
			fightAux.setStats(_HPbase, _MPbase, _physicalDamagebase, _magicDamagebase, _physicalResistancebase, _magicResistancebase);
			fightAux.setLevel(_level);
			fightAux.setWins(_wins);
			for (int i = 0; i < _inventorySize; i++) {
				fread(&_inventoryAux, sizeof(abilityName), 1, p);
				_abilityInventoryNames.push_back(_inventoryAux);
			}
			_err = fclose(p);
			p = nullptr;
			for (int i = 0; i < _inventorySize; i++) {
				inventoryAux.push_back(abilityFactory.createAbility(_abilityInventoryNames[i]));
			}
			fightAux.setInventory(inventoryAux);
			for (int i = 0; i < 3; i++) {
				fightAux.setAbilityEquiped(abilityFactory.createAbility(_abilityEquiped[i]), i);
			}
			mapAux.setPosition(_position);
			return true;
		}
	}
	return false;
}
