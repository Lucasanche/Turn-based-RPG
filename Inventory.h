#pragma once

#include "Ability.h"

class Inventory
{
private:
	Ability** _abilityArray;
	int _nrOfAbilities;
	int _capacity;

	//Private functions
	void nullify(const unsigned from = 0);

public:
	Inventory(unsigned capacity);
	virtual ~Inventory();

	// Gets()
	int getCapacity() { return _capacity; }
	int getNroOfAbilities() { return _nrOfAbilities; }

	//Modifiers

	//Functions
	void clear();
	const bool empty() const;

	const bool add(Item* item);
	const bool remove(const unsigned index);

	const bool saveToFile(const std::string fileName);
	const bool loadFromFile(const std::string fileName);
};




