#pragma once
#include "Ability.h"

class AbilityMagic : public Ability
{
private:
	int _magicDamage;
	bool _damageMultiplier,
		_vampireishon,
		_stun,
		_reducePD,
		_reduceMR,
		_reduceAtt,
		_burns,
		_poison,
		_truedamash;
public: 
	AbilityMagic();
	void setMagicDamage(int magicDamage) override { _magicDamage = magicDamage; }
	void setDamageMultiplier(bool status) override { _damageMultiplier = status; }
	void setMpCost(int mpCost) override { _mpCost = mpCost; }
	void setVampireishon(bool status) override { _vampireishon = status; }
	void setStun(bool status) override { _stun = status; }
	void setReducePD(bool status) override { _reducePD = status; }
	void setReduceMR(bool status) override { _reduceMR = status; }
	void setReduceAtt(bool status) override { _reduceAtt = status; }
	void setBurns(bool status) override { _burns = status; }
	void setPoison(bool status) override { _poison = status; }
	void setTrueDamash(bool status) override { _truedamash = status; }
	float useAbility(Dragon &dragon) override;
};

