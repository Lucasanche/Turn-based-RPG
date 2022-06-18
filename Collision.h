#pragma once
#include <SFML/Graphics.hpp>
class Collision {

	public:
		virtual sf::FloatRect getBounds() const = 0;
		bool isCollision(Collision& col) const;
	};



