#include "stdafx.h"
#include "DyvirMap.h"


DyvirMap::DyvirMap() {
	_texture.loadFromFile("./Textures/Characters/spritesheets/DyvirMap.png");
	_sprite.setTexture(_texture);
	_sprite.setTextureRect({ 0, 0, 184, 170 });
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);
	_sprite.setScale(0.15, 0.15);
	_sprite.setPosition(200, 200 - _sprite.getGlobalBounds().height);
	_frame = 0;
	_speedX = 2;
	_speedY = 2;
	Collide = false;
}

void DyvirMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_sprite, states);
}

bool DyvirMap::update() {
	srand(time(0));
	_frame += 0.15;
	if (_frame >= 5) {
		_frame = 0;
	}
	_sprite.setTextureRect({ int(_frame) * 222, 0, 184, 170 });


	/// MOVER
	_velocity = { 0, 0 };
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		_velocity.y = -_speedY;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		_velocity.y = _speedY;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		_velocity.x = -_speedX;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		_velocity.x = _speedX;
	}
	///ROTAR LA ANIMACIÓN
	_sprite.move(_velocity);
	if (_velocity.x < 0) {
		_sprite.setScale(-0.15, 0.15);
	}
	if (_velocity.x > 0) {
		_sprite.setScale(0.15, 0.15);
	}
	if (_velocity != sf::Vector2f(0, 0)) {
		if (rand() % 5 == 1) {
			return true;
		}
		std::cout << rand() << std::endl;
	}
	return false;
}

sf::FloatRect DyvirMap::getBounds() const {

	return _sprite.getGlobalBounds();

}

void DyvirMap::setCollide() {
	if (_velocity.x != 0) {
		_sprite.move(-_velocity.x, 0);
	}
	if (_velocity.y != 0) {
		_sprite.move(0, -_velocity.y);
		std::cout << _velocity.x << std::endl;
	}
}


