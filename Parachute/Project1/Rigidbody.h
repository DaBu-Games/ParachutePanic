#pragma once

#include "Vector2.h" 

class Rigidbody
{
	private:
		Vector2 position; 
		Vector2 velocity;
		Vector2 accel;
		Vector2 totalForce; 

		float friction; // Can only be between 0 and 1
		float mass;
		float gravity;

	public:
		Rigidbody(const float& mass, const float& friction, const float& gravity, const Vector2& position);
		void addForce(const Vector2& force);
		void update(float& deltaTime);
		Vector2& GetPosition();

};

