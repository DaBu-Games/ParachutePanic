#pragma once

#include "Imoveable.h"
#include <SFML/Graphics.hpp>

class Player : public Imoveable
{
	private:
		const float moveSpeed = 750;
		const float playerRadius = 80; 
		const sf::Color playerColor = sf::Color::Green;
		static const float playerMass;
		static const float playerFriction;
		static const float playerGravity;
		static const Vector2 startPosition; 
		sf::CircleShape playerShape;
		sf::RenderWindow& currentWindow; 
	public:
		Player(sf::RenderWindow& window);
		void Move(const float& deltaTime) override; 
		void DrawPlayer(); 
};

