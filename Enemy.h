#pragma once
#include "Dragon.h"
#include "AbilityFactory.h"
#include "Ability.h"
class Enemy : public Dragon
{
private:
	AbilityFactory* abilityFactory;
	Ability* _ability1;
	Ability* _ability2;
public:
	Enemy(std::string path, int widht, int height, float frameMultiplier, int totalFrames);
	void setStats(int _HP,
		int _physicalDamage,
		int _elementWeak,
		int _physicalDefense,
		int _magicResist);
	void setAbility1(abilityName);
	void setAbility2(abilityName);
	void setAbility(Ability& ability, abilityName abName);
	void update() override;
};
