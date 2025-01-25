#include "Rigidbody.h"

Rigidbody::Rigidbody( float friction, float mass, float gravity )
	:	position(0, 0), velocity(0, 0), accel(0, 0),
	friction(friction), mass(mass), gravity(gravity) {}

void Rigidbody::addForce( const Vector2& force ) {

	accel = accel + force / mass;

}

void Rigidbody::update(float deltaTime) {

	// Get the friction force 
	Vector2 frictionForce = velocity.normalize() * ( -friction * mass * gravity );

    // Apply friction force
    velocity = velocity + frictionForce / mass;

    // Update position and velocity based on acceleration
    position = position + velocity * deltaTime;
    velocity = velocity + accel * deltaTime;

    // Stop the object if the velocity becomes very small
    if (velocity.magnitude() < 0.01f) {
        velocity = Vector2(0, 0); 
    }

}

