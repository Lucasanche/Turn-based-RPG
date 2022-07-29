#pragma once
#include "Dragon.h"
#include "AbilityFactory.h"
#include "Ability.h"


class Enemy : public Dragon
{
private:
	int _frameY;
	int _filas;
	//AbilityFactory* abilityFactory;
	AbilityFactory abilityFactory;

	//States Enemigos
	sf::Sprite _spriteStunEnemy;
	sf::Sprite _spriteBleedingEnemy;
	sf::Sprite _spriteBurnsEnemy;
	sf::Sprite _spritePoisonedEnemy;
	sf::Sprite _spritePRincreaseEnemy;
	sf::Sprite _spriteMDincreaseEnemy;
	sf::Sprite _spritePDincreaseEnemy;
	sf::Sprite _spriteMRincreaseEnemy;
	sf::Sprite _spritePRdecreaseEnemy;
	sf::Sprite _spriteMDdecreaseEnemy;
	sf::Sprite _spritePDdecreaseEnemy;
	sf::Sprite _spriteMRdecreaseEnemy;
	sf::Sprite _spriteDamageMultiplierEnemy;
public:
	Enemy(std::string path, int widht, int height, int totalFrames, float scale, int filas);
	void setStats(int HP, int MP, int physicalDamage, int magicDamage, int physicalResistance, int magicResist, elements elementWeak, elements elementResist, int XP);
	void update(bool, int) override;
	void updateSpriteStates(sf::RenderWindow& window) override;
	void Die() override;
};
