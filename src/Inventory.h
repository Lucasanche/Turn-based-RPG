#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H
#include "Ability.h"

class Inventory
{
private:
	Ability **_abilityArray;
	int _nrOfAbilities;
	int _capacity;
	//bool _isEmpty; la necesitamos realmente? 
	// Nah que se yo

	//Private functions
	void nullify(const int from = 0);

public:
	Inventory(unsigned capacity);
	void freeMemory();
	virtual ~Inventory();
	// Gets()
	int getCapacity() { return _capacity; }
	int getNroOfAbilities() { return _nrOfAbilities; }
	//Functions
	void clear();
	bool add(Ability&); 
	bool remove(const unsigned index);
	void listar();

	//const bool saveToFile(const std::string fileName);
	//const bool loadFromFile(const std::string fileName);
};

#endif