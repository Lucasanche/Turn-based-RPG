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
	_velocity = { 0,0 };
	_speed = { 2, 2 };
	Collide = false;
	_left = _right = _up = _down = false;
}

void DyvirMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_sprite, states);
}

bool DyvirMap::update() {
	_frame += 0.15;
	if (_frame >= 5) {
		_frame = 0;
	}
	_sprite.setTextureRect({ int(_frame) * 222, 0, 184, 170 });

	//Mover
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !_right) {
		_left = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			_velocity.x = _speed.x;
		}
		else {
			_velocity.x = -_speed.x;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !_left) {
		_right = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			_velocity.x = -_speed.x;
		}
		else {
			_velocity.x = _speed.x;
		}
	}
	else {
		_velocity.x = 0;
		_right = _left = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !_up) {
		_down = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			_velocity.y = -_speed.y;
		}
		else {
			_velocity.y = _speed.y;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !_down) {
		_up = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			_velocity.y = _speed.y;
		}
		else {
			_velocity.y = -_speed.y;
		}
	}
	else {
		_velocity.y = 0;
		_up = _down = false;
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
		//Setea los encuentros aleatorios (return false para desactivarlos)
		if (rand() % 360 == 0) {
			return false;
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

bool DyvirMap::collisionDirection(Collision& obj) const {
	if (obj.getBounds().left == getBounds().width || obj.getBounds().width == getBounds().left) {
		return true;
	}
	return false;
}


