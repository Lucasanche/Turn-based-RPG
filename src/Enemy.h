#pragma once
#include "Dragon.h"
#include "AbilityFactory.h"
#include "Ability.h"


class Enemy : public Dragon
{
private:
	float scale;
	int _frameY;
	int _filas;
	//AbilityFactory* abilityFactory;
	AbilityFactory abilityFactory;
public:
	Enemy(std::string path, int widht, int height, int totalFrames, float scale, int filas);
	void setStats(int HP, int MP, int physicalDamage, int magicDamage, int physicalResistance, int magicResist, elements elementWeak, elements elementResist, int XP);
	void update(bool, int) override;
	void Die() override;
};
