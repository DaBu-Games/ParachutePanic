#pragma once

#include "Rigidbody.h"
#include "SFML/Graphics.hpp"
class GameManager;  // forward declaration

class Object
{
	protected:
		Rigidbody rigidbody;
		GameManager& manager;
		const Vector2& screenSize; 

	public:
		Object(float mass, float drag, const Vector2& screenSize, const Vector2& position, GameManager& manager);

		virtual void SetPosition();
		virtual void Update();
		virtual void Draw();
		virtual void BorderDetection();
		virtual Vector2 GetPosition();
};

