#pragma once

#include "Vector2.h"

class Rigidbody
{
	private:
		Vector2 velocity;
		Vector2 forces;
		Vector2 impulses;
		Vector2 position;

		float drag;
		float mass;

	public:
		Rigidbody(float mass, float drag, const Vector2& position);

		void AddForce(const Vector2& force);
		void AddImpulse(const Vector2& impulse); 
		Vector2& GetPosition();
		void ReverseVelocityX();
		void Update(float deltaTime);
};

