#pragma once
#include "Dragon.h"
#include "AbilityFactory.h"
#include "Ability.h"

class Enemy : public Dragon
{
private:
	int _frameY;
	//AbilityFactory* abilityFactory;
	Ability* _ability1;
	Ability* _ability2;
	AbilityFactory abilityFactory;
public:
	Enemy(std::string path, int widht, int height, int totalFrames);
	void setStats(int _HP,
		int _physicalDamage,
		elements _elementWeak,
		int _physicalDefense,
		int _magicResist);
	void setAbility(Ability& ability, abilityName abName);
	void setAbility1(abilityName);
	void setAbility2(abilityName);
	void update() override;
	void Die() override;
};
