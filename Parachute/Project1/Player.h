#pragma once

#include "Object.h"

class Player : public Object
{
	private:
		float radius; 
		float moveSpeed;
		sf::CircleShape circleShape;

	public:
		Player( float radius, float moveSpeed, float mass, float drag, const Vector2& resolution, const Vector2& position, GameManager& manager );
		void Update() override;
		void Draw() override;
		void SetPosition() override;
		void BorderDetection() override;
		float GetRadius();
};

