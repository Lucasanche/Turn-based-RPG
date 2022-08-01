#include "stdafx.h"
#include "DyvirFight.h"
#include "AbilityFactory.h"

DyvirFight::DyvirFight() {
	_abilityInventory.push_back(_abilityFactory.createFireball());
	_abilityInventory.push_back(_abilityFactory.createInferno());
	_abilityInventory.push_back(_abilityFactory.createBubble());
	_abilityInventory.push_back(_abilityFactory.createDoton());
	_abilityInventory.push_back(_abilityFactory.createPoisonGas());
	_level = 1;
	_XP = 0;
	_HPbase = 20000;
	_MPbase = 2000;
	_physicalDamagebase = 20;
	_magicDamagebase = 150;
	_physicalResistancebase = 50;
	_magicResistancebase = 50;
	_HP = _HPbase;
	_MP = _MPbase;
	_physicalDamage = _physicalDamagebase;
	_magicDamage = _magicDamagebase;
	_physicalResistance = _physicalResistancebase;
	_magicResistance = _magicResistancebase;
	_wins = 0;
	this->setFightSprite();
	_winTexture.loadFromFile("./Textures/Characters/spritesheets/DyvirWin 110x200.png");
	_deathTexture.loadFromFile("./Textures/Characters/spritesheets/DyvirDead.png");
	_texture.loadFromFile("./Textures/Characters/spritesheets/DyvirFight.png");
	_spriteStatesPosition = { 230, 510 };
}

void DyvirFight::update(bool enemyIsAlive, int enemyXP) {
	_physicalDamagebase = 20000;
	if (enemyIsAlive) {
		if (_isAlive) {
			_frame += 0.15f;
			if (_frame >= 8 && _isAlive) {
				_frame = 0;
			}
			_sprite.setTextureRect({ int(_frame) * 260, 0, 260, 230 });
		}
		else {
			this->Die();
		}
	}
	else {
		this->Win(enemyXP);
		this->resetStats();
	}
}

void DyvirFight::getAbilityDrop(abilityName abilityDrop) {
	_abilityInventory.push_back(_abilityFactory.createAbility(abilityDrop));
}

void DyvirFight::setAbilityEquiped(Ability ability, int pos) {
	_ability[pos] = ability;
}

sf::String DyvirFight::setAbilityEquipedElement(int i, int ability) {
	{
		if (ability < _abilityInventory.size()) {
			_ability[i] = _abilityInventory[ability];
			return _ability[i].getName();
		}
		else return _ability[i].getName();
	}
}

sf::String DyvirFight::getInventoryElementName(int i) {
	if (i >= _abilityInventory.size()) {
		return "Empty";
	}
	else return _abilityInventory[i].getName();
}

sf::String DyvirFight::getInventoryElementDescription(int i) {
	if (i >= _abilityInventory.size()) {
		return "Empty";
	}
	else return _abilityInventory[i].getDescription();
}

void DyvirFight::updateSpriteStates(sf::RenderWindow& window) {


	/*_spriteDamageMultiplier.setTextureRect(sf::IntRect(600, 0, 50, 50));
	_spriteBleeding.setTextureRect(sf::IntRect(50, 0, 50, 50));*/

	if (_negativeStates[stun]) {
		_spriteStates.setTextureRect({ 0, 0, 50, 50 });
		_spriteStates.setPosition(_spriteStatesPosition);
		window.draw(_spriteStates);
	}
	if (_negativeStates[burns]) {
		_spriteStates.setTextureRect({ 100, 0, 50, 50 });
		_spriteStates.setPosition({ _spriteStates.getPosition().x + 35, _spriteStates.getPosition().y });
		window.draw(_spriteStates);
	}
	if (_negativeStates[poison]) {
		_spriteStates.setPosition({ _spriteStates.getPosition().x + 35, _spriteStates.getPosition().y });
		_spriteStates.setTextureRect({ 150, 0, 50, 50 });
		window.draw(_spriteStates);
	}
	if (_negativeStates[reducePR]) {
		_spriteStates.setTextureRect({ 200, 0, 50, 50 });
		_spriteStates.setPosition({ _spriteStates.getPosition().x + 35, _spriteStates.getPosition().y });
		window.draw(_spriteStates);
	}
	if (_negativeStates[reduceMR]) {
		_spriteStates.setTextureRect({ 350, 0, 50, 50 });
		_spriteStates.setPosition({ _spriteStates.getPosition().x + 35, _spriteStates.getPosition().y });
		window.draw(_spriteStates);
	}
	if (_negativeStates[reducePD]) {
		_spriteStates.setTextureRect({ 300, 0, 50, 50 });
		_spriteStates.setPosition({ _spriteStates.getPosition().x + 35, _spriteStates.getPosition().y });
		window.draw(_spriteStates);
	}
	if (_negativeStates[reduceMD]) {
		_spriteStates.setTextureRect({ 250, 0, 50, 50 });
		_spriteStates.setPosition({ _spriteStates.getPosition().x + 35, _spriteStates.getPosition().y });
		window.draw(_spriteStates);
	}
	//positive states
	if (_positiveStates[increasePR]) {
		_spriteStates.setTextureRect({ 550, 0, 50, 50 });
		_spriteStates.setPosition({ _spriteStates.getPosition().x + 35, _spriteStates.getPosition().y });
		window.draw(_spriteStates);
	}
	if (_positiveStates[increaseMR]) {
		_spriteStates.setTextureRect({ 500, 0, 50, 50 });
		_spriteStates.setPosition({ _spriteStates.getPosition().x + 35, _spriteStates.getPosition().y });
		window.draw(_spriteStates);
	}
	if (_positiveStates[increasePD]) {
		_spriteStates.setTextureRect({ 400, 0, 50, 50 });
		_spriteStates.setPosition({ _spriteStates.getPosition().x + 35, _spriteStates.getPosition().y });
		window.draw(_spriteStates);
	}
	if (_positiveStates[increaseMD]) {
		_spriteStates.setTextureRect({ 450, 0, 50, 50 });
		_spriteStates.setPosition({ _spriteStates.getPosition().x + 35, _spriteStates.getPosition().y });
		window.draw(_spriteStates);
	}
}

bool DyvirFight::craftAbility(sf::String ab1, sf::String ab2, int indexAb1, int indexAb2) {
	if (_abilityFactory.craftAbility(ab1, ab2) != CraftError) {
		if (indexAb1 < indexAb2) {
			_abilityInventory.erase(_abilityInventory.begin() + indexAb1);
			_abilityInventory.erase(_abilityInventory.begin() + indexAb2 - 1);
		}
		else {
			_abilityInventory.erase(_abilityInventory.begin() + indexAb2);
			_abilityInventory.erase(_abilityInventory.begin() + indexAb1 - 1);
		}
		_abilityInventory.push_back(_abilityFactory.createAbility(_abilityFactory.craftAbility(ab1, ab2)));
		return true;
	}
	else { return false; }
}

void DyvirFight::restoreLife() {
	_HP = _HPbase;
	_MP = _MPbase;
}

void DyvirFight::setFightSprite() {
	_sprite.setTexture(_texture);
	_sprite.setTextureRect({ 0,0,260,230 });
	_sprite.setScale(0.5, 0.5);
	_sprite.setPosition(85, 480 - _sprite.getGlobalBounds().height);
	_flagWin = true;
}

void DyvirFight::Die() {
	if (_flagDie) {
		_frame = 0;
		_sprite.setTexture(_deathTexture);
		_sprite.setScale(1, 1);
		_flagDie = false;
	}
	_frame += 0.15f;
	if (_frame >= 9) {
		_frame = 9;
	}
	_sprite.setTextureRect({ int(_frame) * 170, 0, 170, 110 });
	_sprite.setPosition(85, 480 - _sprite.getGlobalBounds().height);
}

void DyvirFight::Win(int enemyXP) {

	if (_flagWin) {
		this->increaseXP(enemyXP);
		_frame = 0;
		_sprite.setTexture(_winTexture);
		_sprite.setScale(1, 1);
		_flagWin = false;
	}
	_frame += 0.15f;
	if (_frame >= 6) {
		_frame = 0;
	}
	_sprite.setTextureRect({ int(_frame) * 110, 0, 110, 200 });
	_sprite.setPosition(85, 480 - _sprite.getGlobalBounds().height);
}

sf::String DyvirFight::increaseXP(unsigned int XP) {
	_XP += XP;
	if (_level == 20) {
		return "Nivel máximo alcanzado";
	}
	if (XP >= _XPrequired[_level - 1]) {
		_level++;
		this->levelUp(_level);
		_HP = _HPbase;
		_MP = _MPbase;
		std::cout << "Ganaste " + std::to_string(XP) + " puntos de experiencia. Subiste a nivel " + std::to_string(_level) + "\n";
		return "Ganaste " + std::to_string(XP) + " puntos de experiencia. Subiste a nivel " + std::to_string(_level) + "\n";
	}
	else {
		std::cout << "Ganaste " + std::to_string(XP) + " puntos de experiencia.\n";
		return "Ganaste " + std::to_string(XP) + " puntos de experiencia.\n";
	}
}

void DyvirFight::levelUp(int level) {
	switch (level) {
		//---------------------- STAGE 1 -----------------------------------
		//BASE -> setStats(2000, 60, 150, 50, 50, 50, _XP);
		//Enemies -> _enemy->setStats(700, 200, 35, 35, 30, 30, Air, 100); 
	case 2: this->setStats(500, 20, 20, 0, 0, 0);
		break;
		//Boss 1|lvl 3 -> _enemy->setStats(3500, 1000, 100, 100, 50, 50, Fire, 100);
	case 3: this->setStats(500, 0, 20, 20, 10, 20);
		break;
		//---------------------- STAGE 2 -----------------------------------
		//Enemies -> _enemy->setStats(1100, 600, 80, 80, 50, 50, Earth, 150);
	case 4: this->setStats(500, 20, 0, 30, 20, 20);
		break;
	case 5: this->setStats(500, 0, 0, 30, 0, 0);
		break;
		//Boss 2|lvl 6 -> _enemy->setStats(5000, 1250, 150, 150, 120, 100, Air, 300);
	case 6: this->setStats(500, 25, 50, 20, 50, 30);
		break;
		//---------------------- STAGE 3 -----------------------------------
		//Enemies -> _enemy->setStats(1700, 700, 150, 80, 80, 100, Air, 300);  
	case 7: this->setStats(500, 25, 0, 30, 0, 20);
		break;
	case 8: this->setStats(500, 0, 20, 0, 30, 0);
		break;
		//Boss 3 | lvl 9 -> _enemy->setStats(6500, 1250, 200, 200, 150, 150, Water, 450);
	case 9: this->setStats(500, 0, 30, 30, 0, 0);
		break;
		//---------------------- STAGE 4 -----------------------------------
		//Enemies -> _enemy->setStats(3000, 700, 150, 150, 500, 300, Fire, 500);
	case 10: this->setStats(1000, 25, 100, 0, 0, 30);
		break;
		// Boss 4 | lvl 11 -> _enemy->setStats(8000, 2000, 300, 400, 200, 300, Water, 800);
	case 11: this->setStats(500, 50, 100, 100, 50, 0);
		break;
		//---------------------- STAGE 5 -----------------------------------
		//Enemies -> _enemy->setStats(3500, 1000, 400, 300, 300, 250, Fire, 650);
	case 12: this->setStats(500, 50, 100, 100, 50, 50);
		break;
		// Boss 5 | lvl 13 -> _enemy->setStats(10000, 2000, 750, 750, 350, 350, Neutral, 1500);
	case 13: this->setStats(1500, 0, 200, 100, 50, 100);
		break;
		//---------------------- STAGE EXTRA -----------------------------------
		//Enemies ->_enemy->setStats(1700, 700, 150, 80, 80, 100, Air, 300);
	case 14: this->setStats(0, 0, 0, 200, 50, 50);
		break;
	case 15: this->setStats(0, 0, 50, 50, 0, 0);
		break;
	case 16: this->setStats(0, 0, 0, 0, 100, 50);
		break;
	case 17: this->setStats(0, 0, 50, 50, 50, 50);
		break;
	case 18: this->setStats(0, 0, 50, 50, 50, 50);
		break;
	case 19: this->setStats(0, 0, 50, 50, 450, 450);
		break;
	case 20: this->setStats(0, 50, 100, 100, 100, 100);
		break;
	}
}

void DyvirFight::setStats(int HP, int MP, int physicalDamage, int magicDamage, int physicalResistance, int magicResistance) {
	_HPbase += HP;
	_MPbase += MP;
	_physicalDamagebase += physicalDamage;
	_magicDamagebase += magicDamage;
	_physicalResistancebase += physicalResistance;
	_magicResistancebase += magicResistance;
}