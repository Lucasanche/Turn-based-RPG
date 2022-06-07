#pragma once
#include <SFML/Graphics.hpp>
class dragonAzul : public sf::Drawable
{
private:
	int _HP;
	int _BaseDamage;
	/*int BaseDefense;
	int ElectricDamage;
	int FireDamage;*/
	float _frame;
	sf::Texture _texture;
	sf::Sprite _sprite;
	bool _isAlive;
	bool _flagDie;
	int _backGround;

	//Barra de vida
	sf::Texture _textureHP;
	sf::Sprite _spriteHP;
	sf::Sprite _spriteHPFill;
	int _statusHP;
	int _lenghtHP;

public:
	dragonAzul();
	/// Getters
	int getHP() { return _HP; }
	int getBaseDamage() { return _BaseDamage; }
	bool getIsAlive() { return _isAlive; }
	int getBack() { return _backGround; }


	void update();
	bool damageTaken(int);
	int doDamage();
    void updateSpriteHP();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

