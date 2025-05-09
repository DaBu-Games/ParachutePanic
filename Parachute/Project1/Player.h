#pragma once

#include "IMoveable.h"
#include "Circle.h"

class Player : public IMoveable
{
	private:
		const float moveSpeed = 750; 
		const sf::Color playerColor = sf::Color::Green;
		Circle shape; 
		static const float playerRadius;
		static const float playerMass;
		static const float playerFriction;
		static const float playerGravity;
		static const Vector2 startPosition; 
		sf::RenderWindow& currentWindow; 

	public:
		Player(sf::RenderWindow& window);
		void Move(const float& deltaTime) override; 
		void DrawPlayer(); 
};

