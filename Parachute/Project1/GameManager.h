#pragma once

#include "SFML/Graphics.hpp"
#include "Vector2.h"
#include "Player.h"
#include "EnemySpawner.h"
#include <iostream>

class GameManager
{
	private:
		bool gameOver = false;
		int health = 5;
		int score = 0; 
		sf::Text scoreText;
		sf::Text loseText; 
		sf::Font font;

	public:
		sf::RenderWindow window;
		sf::Event event; 
		float deltaTime; 
		std::unique_ptr<Player> player;
		std::unique_ptr<EnemySpawner> spawner;

		GameManager(const Vector2& resolution);
		void run(); 
		void update();
		void Lose();
		void AddScore();

};

