#include "stdafx.h"
#include "DyvirMap.h"


DyvirMap::DyvirMap() {
	_texture.loadFromFile("./Textures/Characters/spritesheets/DyvirMap.png");
	_sprite.setTexture(_texture);
	_sprite.setTextureRect({ 0, 0, 184, 170 });
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height/2);
	_sprite.setScale(0.15, 0.15);
	_sprite.setPosition(225, 110);
	//_sprite.setPosition(-400, 110);
	_frame = 0;
	_velocity = { 0,0 };
	_speed = 300;
	Collide = false;
	_left = _right = _up = _down = false;
}

void DyvirMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_sprite, states);
}

bool DyvirMap::update(sf::Time& delta_time) {
	sf::Vector2f position = _sprite.getPosition();
	_frame += 0.15;
	if (_frame >= 5) {
		_frame = 0;
	}
	_sprite.setTextureRect({ int(_frame) * 222, 0, 184, 170 });
	_velocity = { 0,0 };
	//Mover
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !_right) {
		_left = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			_velocity.x += _speed * delta_time.asSeconds();
		}
		else {
			_velocity.x += -_speed * delta_time.asSeconds();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !_left) {
		_right = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			_velocity.x += -_speed * delta_time.asSeconds();
		}
		else {
			_velocity.x += _speed * delta_time.asSeconds();
		}
	}
	else {
		_right = _left = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !_up) {
		_down = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			_velocity.y += -_speed * delta_time.asSeconds();
		}
		else {
			_velocity.y += _speed * delta_time.asSeconds();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !_down) {
		_up = true;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			_velocity.y += _speed * delta_time.asSeconds();
		}
		else {
			_velocity.y += -_speed * delta_time.asSeconds();
		}
	}
	else {
		_up = _down = false;
	}
	///ROTAR LA ANIMACIÓN
	if (_velocity.x < 0) {
		_sprite.setScale(-0.15, 0.15);
	}
	if (_velocity.x > 0) {
		_sprite.setScale(0.15, 0.15);
	}
	
	_sprite.move(_velocity);

	
	if (_velocity != sf::Vector2f(0, 0)) {
		//Setea los encuentros aleatorios (return false para desactivarlos)
		if (rand() % 100 == 0) {
			return false;
		}
		std::cout << rand() << std::endl;
	}
	return false;
}




