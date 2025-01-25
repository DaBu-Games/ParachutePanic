#pragma once

#include "Vector2.h" 

class Rigidbody
{
	public:
		Vector2 position; 
		Vector2 velocity;
		Vector2 accel;
		Vector2 direction; 

		float friction; // Can only be between 0 and 1
		float mass; // Mass of the rigidbody
		float gravity; // The gravity on the rigidbody 

		Rigidbody(float mass, float friction, float gravity);

		void addForce(const Vector2& force);
		void update(float deltaTime);

};

