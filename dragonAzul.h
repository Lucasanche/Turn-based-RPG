#pragma once
#include <SFML/Graphics.hpp>
class dragonAzul : public sf::Drawable
{
private:
	int _HP;
	int _BaseDamage;
	int _statusHP;
	int _lenghtHP;
	/*int BaseDefense;
	int ElectricDamage;
	int FireDamage;*/
	bool _isAlive;
	int _backGround;
	float _frame;
	sf::Texture _texture;
	sf::Sprite _sprite;
	

	//Barra de vida
	sf::Texture _textureHP;
	sf::Sprite _spriteHP;
	sf::Sprite _spriteHPFill;

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

