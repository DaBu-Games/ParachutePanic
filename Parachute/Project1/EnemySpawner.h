#pragma once
#include "Player.h"
#include "Enemy.h"
#include <list>

class GameManager;  // forward declaration

class EnemySpawner
{
	private:
		GameManager& manager;
		Player& player; 
		std::list<Enemy> enemies;
		const Vector2& resolution; 
		float timeSinceSpawn = 0.0f;
		float spawnInterval = 3.0f;

	public:
		EnemySpawner(GameManager& manager, Player& player, const Vector2& resolution);
		void SpawnEnemy();
		void Update(); 
		void EnemyCollisonCheck(Enemy& enemy);
};

