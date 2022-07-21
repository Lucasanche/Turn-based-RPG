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
	sf::Vector2f _position; // Map
	errno_t _err;
	abilityName _abilityEquiped[3];
	std::vector<int> _abilityInventory;
public:
	bool saveGame(DyvirMap& mapAux, DyvirFight& fightAux, int option) {
		FILE* p = nullptr;
		SaveGame aux;
		_inventorySize = fightAux.getInventorySize();
		for (int i = 0; i < _inventorySize; i++) {
			_abilityInventory.push_back(int(fightAux.getInventoryElement(i).getID()));
		}
		for (int i = 0; i < 3; i++) {
			_abilityEquiped[i] = fightAux.getAbility(i).getID();
		}
		this->_HPbase = fightAux.getHPbase();
		this->_MPbase = fightAux.getMPbase();
		this->_physicalDamagebase = fightAux.getPhysicalDamageBase();
		this->_magicDamagebase = fightAux.getMagicDamageBase();
		this->_physicalResistancebase = fightAux.getPhysicalResistanceBase();
		this->_magicResistancebase = fightAux.getMagicResistanceBase();
		this->_XP = fightAux.getXP();
		this->_level = fightAux.getLevel();
		this->_wins = fightAux.getWins();
		this->_position = mapAux.getPosition();
		aux = *this;
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
				std::cout << fwrite(this, sizeof(aux), 1, p) << std::endl;
				_err = fclose(p);
				return true;
			}
			else {
				return false;
			}
		}
		else { return false; }
	}
	void setInventorySize(int size){
		_abilityInventory.assign(size, 26);
		//for (int i = 0; i < size; i++) {
		//	
		//	_abilityInventory.push_back(26);
		//}
	}
	bool loadGame(DyvirMap& mapAux, DyvirFight& fightAux, int option) {
		FILE* p = nullptr;
		SaveGame aux;
		AbilityFactory abilityFactory;
		*this = aux;
		switch (option) {
		case 0:
			_err = fopen_s(&p, "saves/SaveGame1.dat", "rb");
			break;
		case 1:
			_err = fopen_s(&p, "saves/SaveGame2.dat", "rb");
			break;
		case 2:
			_err = fopen_s(&p, "saves/SaveGame3.dat", "rb");
			break;
		}

		if (p != nullptr) {
			if (_err == 0) {
				int auxSizeOfInventory = 0;
				
				fread(&auxSizeOfInventory, sizeof(int), 1, p);
				aux.setInventorySize(auxSizeOfInventory);
				fseek(p, 0,0);
				fread(&aux, sizeof(aux), 2, p);
				_err = fclose(p);
				p == nullptr;
				fightAux.setStats(_HPbase, _MPbase, _physicalDamagebase, _magicDamagebase, _physicalResistancebase, _magicResistancebase, _XP);
				fightAux.setLevel(_level);
				//fightAux.setInventory(_inventory);
				fightAux.setWins(_wins);
				for (int i = 0; i < 3; i++) {
					fightAux.setAbilityEquiped(abilityFactory.createAbility(_abilityEquiped[i]), i);
				}
				mapAux.setPosition(_position);
				
			}
		}
		else { return false; }
	}
};

#endif