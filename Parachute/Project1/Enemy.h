#pragma once
#include "Object.h"
#include <random>

class Enemy : public Object
{
	private:
		float radius;
		float moveSpeedX;
		float moveSpeedY;
		sf::CircleShape circleShape;
		bool isDeleted = false;

	public:
		Enemy(float radius, float mass, float drag, const Vector2& resolution, const Vector2& position, GameManager& manager);
		void Update() override;
		void Draw() override;
		void SetPosition() override;
		void BorderDetection() override;
		void ReverseForceX(); 
		void DeleteEnemy(); 
		bool IsDeleted() const; 
		float GetRadius() const;
};

