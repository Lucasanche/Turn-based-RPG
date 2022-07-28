#pragma once
#ifndef COLLISION_H
#define COLLISION_H


class Collision
{
private:
	sf::Sprite& _origin_rect;
public:
	Collision(sf::Sprite& origin_rect);
	bool CheckCollision(Collision target_rect, float push);
	void move(float delta_x, float delta_y) { _origin_rect.move(delta_x, delta_y); }
	sf::Vector2f getPosition() { return _origin_rect.getPosition(); }
	sf::Vector2f getHalfSize() { return { _origin_rect.getGlobalBounds().width / 2.0f, _origin_rect.getGlobalBounds().height / 2.0f }; }
};

#endif