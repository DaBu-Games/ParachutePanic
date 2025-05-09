#include "Player.h"

const float Player::playerMass = 2.0f;
const float Player::playerFriction = 1.0f;
const float Player::playerGravity = 1.0f; 
const Vector2 Player::startPosition = Vector2(320, 640);

Player::Player(sf::RenderWindow& window) : Imoveable(playerMass, playerFriction, playerGravity, startPosition), currentWindow(window) {
    playerShape = sf::CircleShape(playerRadius);
    playerShape.setFillColor(playerColor);
}

void Player::Move(const float& deltaTime) {
    Vector2 directionForce(0, 0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) directionForce.x += moveSpeed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) directionForce.x -= moveSpeed;

    if (directionForce.x != 0) {
        rb.addForce(directionForce);
    }

    rb.update(deltaTime);

    DrawPlayer(); 
}

void Player::DrawPlayer() {
    Vector2 position = rb.GetPosition();
    playerShape.setPosition(position.x, position.y);
    currentWindow.draw(playerShape); 
}