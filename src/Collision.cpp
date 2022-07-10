#include "stdafx.h"
#include "Collision.h"


bool Collision::isCollision(Collision& obj) const {
	return getBounds().intersects(obj.getBounds());
}