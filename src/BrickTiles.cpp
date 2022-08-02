#include "stdafx.h"
#include "BrickTiles.h"


BrickTiles::BrickTiles() {
	_texture.loadFromFile("./Textures/Backgrounds/Tilesheet2.png");
	_spriteCollision.setTexture(_texture);
	_spriteNoCollision.setTexture(_texture);
	_spriteNoCollision.setTextureRect(sf::IntRect(0, 0, 32, 32));
	_spriteNoCollision.setOrigin(_spriteNoCollision.getGlobalBounds().width / 2, _spriteNoCollision.getGlobalBounds().height / 2);
	_frameVortex = 0;
	_draw = false;
	_frameCheckpoint = 0;
	_frameWalls = 0;
	_spriteCollision.setTextureRect(sf::IntRect(0, 0, 32, 32));
	_spriteCollision.setOrigin(_spriteCollision.getGlobalBounds().width / 2, _spriteCollision.getGlobalBounds().height / 2);
}

void BrickTiles::update(int j, int i, const char* mapValue, int wins, sf::Time& delta_time, sf::RenderWindow& window) {

	wins += 2;
	_frameWalls += 0.003 * delta_time.asSeconds();
	_frameCheckpoint += 0.003 * delta_time.asSeconds();
	_frameVortex += 0.002 * delta_time.asSeconds();
	if (_frameCheckpoint >= 13) {
		_frameCheckpoint = 0;
	}
	if (_frameWalls >= 12) {
		_frameWalls = 0;
	}
	if (_frameVortex >= 11) {
		_frameVortex = 0;
	}
	//Walls 32X32, empieza en la posición 0x 49y
	
	if (!strcmp(mapValue, "w01")) {
		_spriteNoCollision.setTextureRect(sf::IntRect(32, 128, 32, 32));
		_spriteNoCollision.setPosition(j * 32, i * 32);
		_draw = true;
	}
	else if (!strcmp(mapValue, "w02")) {
		_spriteNoCollision.setTextureRect(sf::IntRect(0, 128, 32, 32));
		_spriteNoCollision.setPosition(j * 32, i * 32);
		_draw = true;
	}
	else if (!strcmp(mapValue, "d01")) {
		_spriteCollision.setTextureRect(sf::IntRect(int(_frameWalls) * 32, 0, 32, 32));
		_spriteCollision.setPosition(j * 32, i * 32);
	}
	else if (!strcmp(mapValue, "d02")) {
		_spriteNoCollision.setTextureRect(sf::IntRect(int(_frameWalls) * 32, 0, 32, 32));
		_spriteNoCollision.setPosition(j * 32, i * 32);
		_spriteCollision.setTextureRect(sf::IntRect(0, 64, 32, 32));
		_spriteCollision.setPosition(j * 32, i * 32);
		_draw = true;
	}
	else if (!strcmp(mapValue, "d03")) {
		_spriteNoCollision.setTextureRect(sf::IntRect(int(_frameWalls) * 32, 0, 32, 32));
		_spriteNoCollision.setPosition(j * 32, i * 32);
		_spriteCollision.setTextureRect(sf::IntRect(32, 64, 32, 32));
		_spriteCollision.setPosition(j * 32, i * 32);
		_draw = true;
	}
	else if (!strcmp(mapValue, "d04")) {
		_spriteNoCollision.setTextureRect(sf::IntRect(int(_frameWalls) * 32, 0, 32, 32));
		_spriteNoCollision.setPosition(j * 32, i * 32);
		_spriteCollision.setTextureRect(sf::IntRect(64, 32 * 2, 32, 32));
		_spriteCollision.setPosition(j * 32, i * 32);
		_draw = true;
	}
	else if (!strcmp(mapValue, "d05")) {
		_spriteNoCollision.setTextureRect(sf::IntRect(int(_frameWalls) * 32, 0, 32, 32));
		_spriteNoCollision.setPosition(j * 32, i * 32);
		_spriteCollision.setTextureRect(sf::IntRect(32 * 3, 64, 32, 32));
		_spriteCollision.setPosition(j * 32, i * 32);
		_draw = true;
	}
	else if (!strcmp(mapValue, "d06")) {
		_spriteNoCollision.setTextureRect(sf::IntRect(int(_frameWalls) * 32, 0, 32, 32));
		_spriteNoCollision.setPosition(j * 32, i * 32);
		_spriteCollision.setTextureRect(sf::IntRect(32 * 4, 64, 32, 32));
		_spriteCollision.setPosition(j * 32, i * 32);
		_draw = true;
	}
	else if (!strcmp(mapValue, "d07")) {
		_spriteNoCollision.setTextureRect(sf::IntRect(int(_frameWalls) * 32, 0, 32, 32));
		_spriteNoCollision.setPosition(j * 32, i * 32);
		_spriteCollision.setTextureRect(sf::IntRect(32 * 5, 64, 32, 32));
		_spriteCollision.setPosition(j * 32, i * 32);
		_draw = true;
	}
	else if (!strcmp(mapValue, "d08")) {
		_spriteNoCollision.setTextureRect(sf::IntRect(int(_frameWalls) * 32, 0, 32, 32));
		_spriteNoCollision.setPosition(j * 32, i * 32);
		_spriteCollision.setTextureRect(sf::IntRect(32 * 6, 64, 32, 32));
		_spriteCollision.setPosition(j * 32, i * 32);
		_draw = true;
	}
	else if (!strcmp(mapValue, "d09")) {
		_spriteNoCollision.setTextureRect(sf::IntRect(int(_frameWalls) * 32, 0, 32, 32));
		_spriteNoCollision.setPosition(j * 32, i * 32);
		_spriteCollision.setTextureRect(sf::IntRect(32 * 7, 64, 32, 32));
		_spriteCollision.setPosition(j * 32, i * 32);
		_draw = true;
	}
	else if (!strcmp(mapValue, "d10")) {
		_spriteNoCollision.setTextureRect(sf::IntRect(int(_frameWalls) * 32, 0, 32, 32));
		_spriteNoCollision.setPosition(j * 32, i * 32);
		_spriteCollision.setTextureRect(sf::IntRect(32 * 8, 64, 32, 32));
		_spriteCollision.setPosition(j * 32, i * 32);
		_draw = true;
	}
	else if (!strcmp(mapValue, "d11")) {
		_spriteNoCollision.setTextureRect(sf::IntRect(int(_frameWalls) * 32, 0, 32, 32));
		_spriteNoCollision.setPosition(j * 32, i * 32);
		_spriteCollision.setTextureRect(sf::IntRect(32 * 9, 64, 32, 32));
		_spriteCollision.setPosition(j * 32, i * 32);
		_draw = true;
	}
	else if (!strcmp(mapValue, "d12")) {
		_spriteNoCollision.setTextureRect(sf::IntRect(int(_frameWalls) * 32, 0, 32, 32));
		_spriteNoCollision.setPosition(j * 32, i * 32);
		_spriteCollision.setTextureRect(sf::IntRect(32 * 10, 64, 32, 32));
		_spriteCollision.setPosition(j * 32, i * 32);
		_draw = true;
	}
	else if (!strcmp(mapValue, "d13")) {
		_spriteNoCollision.setTextureRect(sf::IntRect(int(_frameWalls) * 32, 0, 32, 32));
		_spriteNoCollision.setPosition(j * 32, i * 32);
		_spriteCollision.setTextureRect(sf::IntRect(32 * 11, 64, 32, 32));
		_spriteCollision.setPosition(j * 32, i * 32);
		_draw = true;
	}
	else if (!strcmp(mapValue, "d14")) {
		_spriteNoCollision.setTextureRect(sf::IntRect(int(_frameWalls) * 32, 0, 32, 32));
		_spriteNoCollision.setPosition(j * 32, i * 32);
		_spriteCollision.setTextureRect(sf::IntRect(32 * 12, 64, 32, 32));
		_spriteCollision.setPosition(j * 32, i * 32);
		_draw = true;
	}
	//Checkpoint 27x49, empieza en 315x 0y
	else if (!strcmp(mapValue, "s01")) {
		_spriteNoCollision.setTextureRect(sf::IntRect(32, 128, 32, 32));
		_spriteNoCollision.setPosition(j * 32, i * 32);
		_spriteCollision.setTextureRect(sf::IntRect(int(_frameCheckpoint) * 32, 96, 32, 32));
		_spriteCollision.setPosition(j * 32, i * 32);
		_draw = true;
	}

	//Boss Vortex 35x35 (por el culo te la hinco), empieza en 0x 0y
	/*else if (!strcmp(mapValue, "s02") || !strcmp(mapValue, "s03") || !strcmp(mapValue, "s04") || !strcmp(mapValue, "s05") || !strcmp(mapValue, "s06")) {
		_spriteNoCollision.setTextureRect(sf::IntRect(32, 128, 32, 32));
		_spriteNoCollision.setPosition(j * 32, i * 32);
		_spriteCollision.setTextureRect(sf::IntRect(int(_frameVortex) * 32, 32, 32, 32));
		_spriteCollision.setPosition(j * 32, i * 32);
		_draw = true;
	}*/
	if (_draw) {
		window.draw(_spriteNoCollision);
		_draw = false;
	}
	window.draw(_spriteCollision);
}

void BrickTiles::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_spriteCollision, states);
}
