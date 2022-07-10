#include "stdafx.h"
#include "DyvirFight.h"


DyvirFight::DyvirFight() {

	//TODO: Implementar leveo, subida de stats, etc.

	_HPMax = 100;
	_HP = _HPMax;
	_physicalDamage = 30;
	_texture.loadFromFile("./Textures/Characters/spritesheets/DyvirFight.png");
	_sprite.setTexture(_texture);
	_sprite.setTextureRect({ 0,0,260,230 });
	_sprite.setScale(0.5, 0.5);
	_sprite.setPosition(85, 480 - _sprite.getGlobalBounds().height);
	_isAlive = true;
	_wins = 0;

	//Variables útiles para los sprites
	_flagDie = true; // Usar para reproducir la animación de muerte
	_flagWin = true;
	_frame = 0;
}

void DyvirFight::update() {
	if (_isAlive) {
		_frame += 0.15;
		if (_frame >= 8 && _isAlive) {
			_frame = 0;
		}
		_sprite.setTextureRect({ int(_frame) * 260, 0, 260, 230 });
	}
	else {
		this->Die();
	}
}

void DyvirFight::Die() {
	if (_flagDie) {
		_frame = 0;
		_texture.loadFromFile("./Textures/Characters/spritesheets/DyvirDead.png");
		_sprite.setTexture(_texture);
		_sprite.setScale(1, 1);
		_flagDie = false;
	}
	_frame += 0.15;
	if (_frame >= 9) {
		_frame = 9;
	}
	_sprite.setTextureRect({ int(_frame) * 170, 0, 170, 110 });
	_sprite.setPosition(85, 480 - _sprite.getGlobalBounds().height);
}

void DyvirFight::Win() {
	if (_flagWin) {
		_frame = 0;
		_texture.loadFromFile("./Textures/Characters/spritesheets/DyvirWin.png");
		_sprite.setTexture(_texture);
		_sprite.setScale(1, 1);
		_flagWin = false;
	}
	_frame += 0.15;
	if (_frame >= 5) {
		_frame = 0;
	}
	_sprite.setTextureRect({ int(_frame) * 170, 0, 170, 110 });
}
//TODO: Win()  (cambiar el sprite de animación por el de victoria)