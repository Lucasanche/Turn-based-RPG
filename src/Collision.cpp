#include "stdafx.h"
#include "Collision.h"


Collision::Collision(sf::Sprite& origin_rect) : _origin_rect(origin_rect) {

}

bool Collision::CheckCollision(Collision target_rect, float push) {
	sf::Vector2f targetPosition = target_rect.getPosition();
	sf::Vector2f targetHalfSize = target_rect.getHalfSize();
	sf::Vector2f originPosition = getPosition();
	sf::Vector2f originHalfSize = getHalfSize();

	float delta_x = targetPosition.x - originPosition.x;
	float delta_y = targetPosition.y - originPosition.y;
	float intersect_x = std::abs(delta_x) - (targetHalfSize.x + originHalfSize.x);
	float intersect_y = std::abs(delta_y) - (targetHalfSize.y + originHalfSize.y);
	if (intersect_x < 0.0f && intersect_y < 0.0f) {
		push = std::min(std::max(push, 0.0f), 1.0f);
		if (intersect_x > intersect_y) {
			if (delta_x > 0.0f) {
				move(intersect_x * (1.0f - push), 0.0f);
				target_rect.move(-intersect_x * push, 0.0f);
			}
			else {
				move(-intersect_x * (1.0f - push), 0.0f);
				target_rect.move(intersect_x * push, 0.0f);
			}
		}
		else {
			if (delta_y > 0.0f) {
				move(0.0f, intersect_y * (1.0f - push));
				target_rect.move(0.0f, -intersect_y * push);
			}
			else {
				move(0.0f, -intersect_y * (1.0f - push));
				target_rect.move(0.0f, intersect_y * push);
			}
		}
		return true;
	}
	return false;
}
