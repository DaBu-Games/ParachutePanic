#include "Player.h"

const float Player::playerRadius = 80;
const float Player::playerMass = 2.0f;
const float Player::playerFriction = 1.0f;
const float Player::playerGravity = 1.0f; 
const Vector2 Player::startPosition = Vector2(0, 0);

Player::Player(sf::RenderWindow& window) : IMoveable(playerMass, playerFriction, playerGravity, startPosition), currentWindow(window), shape(playerRadius){
    shape.SetShapeColor(playerColor); 
    shape.SetOrigin(startPosition); 
}

void Player::Move(const float& deltaTime) {
    Vector2 directionForce(0, 0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) directionForce.x += moveSpeed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) directionForce.x -= moveSpeed;

    if (directionForce.x != 0) {
        rb.addForce(directionForce);
    }

    rb.update(deltaTime);

    Vector2 position = rb.GetPosition();

    shape.SetShapePosition(position);
    currentWindow.draw(shape.GetShape());
}