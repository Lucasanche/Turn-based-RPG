#pragma once
#ifndef COLLISION_H
#define COLLISION_H

class Collision {

	public:
		virtual sf::FloatRect getBounds() const = 0;
		bool isCollision(Collision& col) const;
	};

#endif