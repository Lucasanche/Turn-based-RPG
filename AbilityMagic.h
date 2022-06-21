#pragma once
class AbilityMagic
{
protected:
	float _damage;
	int _element;
	int _status;
	
public: 
	AbilityMagic();

	enum elements
	{
		neutral = 0,
		fire,
		water,
		air,
		earth,
		poison,
		burnt,
	};
};

