#include "Rigidbody.h"

Rigidbody::Rigidbody( float friction, float mass, float gravity )
	:	position(0, 0), velocity(0, 0), accel(0, 0),
	friction(friction), mass(mass), gravity(gravity) {}

void Rigidbody::addForce( const Vector2& force ) {

	accel = accel + force / mass;

}

void Rigidbody::update(float deltaTime) {

    if ( velocity.magnitude() > 0.0f ) {
        Vector2 frictionForce = velocity.normalize() * (-friction * mass * gravity);
        accel = accel + frictionForce / mass; // Add friction to the acceleration
    }

    // Update velocity based on acceleration
    velocity = velocity + accel * deltaTime;

    // Update position based on velocity
    position = position + velocity * deltaTime;

    // Reset acceleration after each update
    accel = Vector2(0, 0);

    // Set velocity to 0 if its to small
    if ( velocity.magnitude() < 0.01f ) {
        velocity = Vector2(0, 0);
    }

}

