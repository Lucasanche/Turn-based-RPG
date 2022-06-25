#include "Inventory.h"
#include "Ability.h"

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



//Functions
void Inventory::nullify(const int from)
{
	for (size_t i = from; i < this->_capacity; i++)
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


bool Inventory::add(Ability& _newAbility) //REVISAR -> en mi cabeza. recorre el array, siempre que encuentre algo va 
//sumando las posiciones. Cuando deja de sumar es porque la posicion esta vacia, asi que ahi le tendriamos que poner 
//la habilidad nueva. 
{
	if (_nrOfAbilities < _capacity)
	{
		int _position = 0;
		while (_abilityArray[_position]) 
		{
			_position++;
		}
		_abilityArray[_position] = &_newAbility; //WTF NO SE COMO HAY Q PONER ESO AHI NO ME TIRA ERROR PERO NO ME GUSTA
		return true;
	}

	return false;
}

bool Inventory::remove(const unsigned index) //REVISAR -> para borrar setea el espacio como vacio, lo cual tiene sentido
//con el add que cuando recorra el while, va a encontrar un lugar vacio y ahi va a agregar la nueva habilidad
//NO SE BIEN EL INDEX COMO FUNCIONA
{
	if (_nrOfAbilities > 0)
	{
		if (index < 0 || index >= _capacity) return false;
		else
		{
			delete _abilityArray[index];
			_abilityArray[index] = nullptr;
			_nrOfAbilities--;
			return true;
		}
	}

	return false;
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