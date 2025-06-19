#include "Enemy.h"
#include "GameManager.h"

Enemy::Enemy(float radius, float mass, float drag, const Vector2& resolution, const Vector2& position, GameManager& manager)
    : Object(mass, drag, resolution, position, manager),
    radius(radius), circleShape(sf::CircleShape(radius)) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(100.0f, 300.0f);

    // Set random initial movement speed
    moveSpeedX = dist(gen);
    moveSpeedY = dist(gen);

    circleShape.setOrigin(radius, radius);
}

void Enemy::Update() {

    rigidbody.AddForce(Vector2(moveSpeedX, moveSpeedY));

    BorderDetection();
    rigidbody.Update(manager.deltaTime);
    SetPosition();
    Draw();
}

void Enemy::SetPosition() {
    const Vector2& pos = rigidbody.GetPosition();
    circleShape.setPosition(pos.x, pos.y);
}

void Enemy::Draw() {
    manager.window.draw(circleShape);
}

void Enemy::BorderDetection() {
    const Vector2& pos = rigidbody.GetPosition();
    if (pos.x <= radius || pos.x >= screenSize.x - radius) {
        rigidbody.ReverseVelocityX();
        ReverseForceX(); 
    }
}

void Enemy::ReverseForceX() {
    moveSpeedX *= -1; 
}

void Enemy::DeleteEnemy() {
    isDeleted = true;
}

bool Enemy::IsDeleted() const{
    return isDeleted;
}

float Enemy::GetRadius() const{
    return radius;
}