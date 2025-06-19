#include "Player.h"
#include "GameManager.h"

Player::Player( float radius, float moveSpeed, float mass, float drag, const Vector2& resolution, const Vector2& position, GameManager& manager )
	: Object( mass, drag, resolution, position, manager ), 
    radius(radius), moveSpeed(moveSpeed), circleShape(sf::CircleShape(radius)) {
    circleShape.setOrigin(radius, radius); 
}

void Player::Update() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        rigidbody.AddForce(Vector2(-moveSpeed, 0)); //Move left
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        rigidbody.AddForce(Vector2(moveSpeed, 0)); //Move right
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        rigidbody.AddForce(Vector2(0, -moveSpeed)); //Move up
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        rigidbody.AddForce(Vector2(0, moveSpeed)); //Move down
    }

    BorderDetection();
    rigidbody.Update( manager.deltaTime );
    SetPosition();
    Draw();
}

void Player::SetPosition() {
    const Vector2& pos = rigidbody.GetPosition();
    circleShape.setPosition(pos.x, pos.y);
}

void Player::Draw() {
    manager.window.draw(circleShape);
}

void Player::BorderDetection() {
    const Vector2& pos = rigidbody.GetPosition();
    if (pos.x <= radius || pos.x >= screenSize.x - radius) {
        rigidbody.ReverseVelocityX(); 
    }
}

float Player::GetRadius() {
    return radius;
}