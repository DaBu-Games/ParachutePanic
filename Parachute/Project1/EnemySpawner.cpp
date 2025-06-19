#include "EnemySpawner.h"
#include "GameManager.h"

EnemySpawner::EnemySpawner(GameManager& manager, Player& player, const Vector2& resolution)
    : manager(manager), player(player), resolution(resolution)
{
    SpawnEnemy();
}

void EnemySpawner::SpawnEnemy() {
	Enemy enemy = Enemy(
        20.0f, // size
        1.0f, // mass
        3.0f, // Drag
        resolution, // screen resolution
        Vector2(resolution.x / 2, 0.0f), // position
        manager // Gamemanager
	);

    enemies.push_back(enemy); 
}

void EnemySpawner::Update() {
    timeSinceSpawn += manager.deltaTime;

    if (timeSinceSpawn >= spawnInterval) {
        SpawnEnemy();
        timeSinceSpawn = 0.0f;
    }

    for (auto it = enemies.begin(); it != enemies.end();) {
        Enemy& enemy = *it;

        EnemyCollisonCheck(enemy);

        if (enemy.IsDeleted()) {
            it = enemies.erase(it);
        }
        else {
            enemy.Update();
            ++it;
        }
    }
}

// check if the enemy has hit the player or is of the screen
void EnemySpawner::EnemyCollisonCheck(Enemy& enemy) {

    if (enemy.GetPosition().y >= resolution.y + enemy.GetRadius()) {
        enemy.DeleteEnemy();
        manager.Lose(); 
    }
    else 
    {
        Vector2 difference = player.GetPosition() - enemy.GetPosition();
        float distance = difference.x * difference.x + difference.y * difference.y;
        float radius = player.GetRadius() + enemy.GetRadius();

        if (distance <= radius * radius) {
            enemy.DeleteEnemy();
            manager.AddScore();
        }
    }
}