#pragma once

#include "Vector2.h" 

class Rigidbody
{
	public:
		Vector2 position; 
		Vector2 velocity;
		Vector2 accel;

		Vector2 totalForce; 

		float friction; // Can only be between 0 and 1
		float mass;
		float gravity;

		Rigidbody(float mass, float friction, float gravity);

		void addForce(const Vector2& force);
		void update(float deltaTime);

};

