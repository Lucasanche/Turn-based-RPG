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
public:
	bool saveGame(DyvirMap& mapAux, DyvirFight& fightAux, int option);
	bool loadGame(DyvirMap& mapAux, DyvirFight& fightAux, int option);
};

#endif