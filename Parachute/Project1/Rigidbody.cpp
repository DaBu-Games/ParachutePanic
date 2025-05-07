#include "Rigidbody.h"

Rigidbody::Rigidbody(const float& mass, const float& friction, const float& gravity, const Vector2& position)
	: velocity(0, 0), accel(0, 0),
	friction(friction), mass(mass), gravity(gravity), position(position) {}

void Rigidbody::addForce( const Vector2& force ) {
    totalForce = Vector2(0, 0); 
    totalForce = totalForce + force;
}

void Rigidbody::update(float& deltaTime) {

    accel = totalForce / mass; 

    if ( velocity.magnitude() > 0.0f ) {
        Vector2 frictionForce = velocity.normalize() * (-friction * mass * gravity);
        accel = accel + frictionForce / mass; // Add friction to the acceleration
    }

    velocity = velocity + accel * deltaTime;
    position = position + velocity * deltaTime;

    totalForce = Vector2(0, 0);

    // Set velocity to 0 if its to small
    if ( velocity.magnitude() < 0.01f ) {
        velocity = Vector2(0, 0);
    }

}

Vector2& Rigidbody::GetPosition() {
    return position;
}
