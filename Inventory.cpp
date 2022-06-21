#include "Inventory.h"
//Private functions

void Inventory::nullify(const unsigned from)
{
	for (size_t i = from; i < this->_capacity; i++)
	{
		_abilityArray[i] = nullptr;
	}
}


//Constructors & Destructors
Inventory::Inventory(unsigned capacity)
{
	_capacity = capacity;
	_nrOfAbilities = 0;
	_abilityArray = new Ability * [_capacity];
	this->nullify();
}

Inventory::~Inventory()
{
	for (size_t i = 0; i < _nrOfAbilities; i++)
	{
		delete _abilityArray[i];
	}
	delete[] _abilityArray;
}



//Modifiers

//Functions

void Inventory::clear()
{
	for (size_t i = 0; i < this->nrOfItems; i++)
	{
		delete this->itemArray[i];
	}

	this->nrOfItems = 0;

	this->nullify();
}

const bool Inventory::empty() const
{
	return this->nrOfItems == 0;
}

const bool Inventory::add(Item* item)
{
	if (this->nrOfItems < this->capacity)
	{
		this->itemArray[this->nrOfItems++] = item->clone();

		return true;
	}

	return false;
}

const bool Inventory::remove(const unsigned index)
{
	if (this->nrOfItems > 0)
	{
		if (index < 0 || index >= this->capacity)
			return false;

		delete this->itemArray[index];
		this->itemArray[index] = nullptr;
		--this->nrOfItems;

		return true;
	}

	return false;
}

const bool Inventory::saveToFile(const std::string fileName)
{
	return false;
}

const bool Inventory::loadFromFile(const std::string fileName)
{
	return false;
}
