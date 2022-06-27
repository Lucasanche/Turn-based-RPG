#pragma once


class AbilityFactory
{
private:
	Ability* _ability;
public:
	Ability* createFireball();
	Ability* createBubble();
	Ability* createWindBlow();
};
