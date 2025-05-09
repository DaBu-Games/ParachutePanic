#pragma once

#include "Rigidbody.h" 

class Imoveable
{
	public:
		Rigidbody rb;
		Imoveable(const float& mass, const float& friction, const float& gravity, const Vector2& position)
			: rb(mass, friction, gravity, position) {
		}
		virtual void Move(const float& deltaTime) = 0; 
};

