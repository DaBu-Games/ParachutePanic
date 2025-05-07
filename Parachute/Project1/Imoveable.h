#pragma once

#include "Rigidbody.h" 

class Imoveable
{
	public:
		Rigidbody rb;
		virtual void UpdateRigidbody(const float& deltaTime) = 0; 
		virtual void AddRigidbodyForce(const Vector2& force) = 0; 
};

