#include "stdafx.h"
#include "Inventory.h"
#include "Ability.h"

//Constructors & Destructors
Inventory::Inventory(unsigned capacity)
{
	_capacity = capacity;
	_nrOfAbilities = 0;
	_abilityArray = new Ability * [_capacity];
	this->nullify(0);
}




//Functions
void Inventory::nullify(const int from)
{
	for (size_t i = from; i < _capacity; i++)
	{
		_abilityArray[i] = nullptr;
	}
}

void Inventory::clear()
{
	for (size_t i = 0; i < this->_nrOfAbilities; i++)
	{
		delete this-> _abilityArray[i];
	}

	this->_nrOfAbilities = 0;

	this->nullify();
}


bool Inventory::add(Ability& newAbility)
{
	if (_nrOfAbilities < _capacity)
	{
		int _position = 0;
		while (_abilityArray[_position]) 
		{
			_position++;
		}
		_abilityArray[_position] = &newAbility;
		_nrOfAbilities++;
		return true;
	}

	return false;
}

bool Inventory::remove(const unsigned index) //REVISAR -> Tira un error en el debugger (quizás es algo relacionado a liberarr la memoria mal)
{
	if (_nrOfAbilities > 0)
	{
		if (index < 0 || index >= _capacity) return false;
		else
		{
			delete _abilityArray[index];
			_abilityArray[index] = nullptr;
			--_nrOfAbilities;
			return true;
		}
	}
	return false;
}

void Inventory::listar()
{
	for (int i = 0; i < _capacity; i++) {
		if (_abilityArray[i]) {
			//_abilityArray[i]->Mostrar();
		}
		else {
			std::cout << "-" << std::endl;
		}
	}

}

void Inventory::freeMemory() {
	for (size_t i = 0; i < _nrOfAbilities; i++)
	{
		delete _abilityArray[i];
	}
	delete[] _abilityArray;
}

Inventory::~Inventory()
{
	this->freeMemory();
	std::cout << "se muere";
}
/*const bool Inventory::saveToFile(const std::string fileName)
{
	return false;
}

const bool Inventory::loadFromFile(const std::string fileName)
{
	return false;
}
*/