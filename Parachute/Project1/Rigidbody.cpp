#include "Rigidbody.h"

Rigidbody::Rigidbody( float drag, float mass, const Vector2& position )
	:   velocity(0, 0), forces(0, 0), drag(drag), mass(mass), position(position) {}

void Rigidbody::AddForce(const Vector2& force) {
    forces += force;
}

void Rigidbody::AddImpulse(const Vector2& impulse) {
	impulses += impulse;
}

Vector2& Rigidbody::GetPosition() {
    return position; 
}

void Rigidbody::ReverseVelocityX() {
    velocity.x *= -1;
}

void Rigidbody::Update(float deltaTime) {
	if (mass == 0.0f)
		return;

	Vector2 totalForce = forces;

    if (velocity.magnitude() > 0.0f) {
        totalForce += velocity.normalize() * -drag * velocity.magnitude();
    }

    Vector2 acceleration = totalForce / mass;

    velocity += acceleration * deltaTime;
    velocity += impulses / mass;

    float maxSpeed = 200.0f;
    if (velocity.magnitude() > maxSpeed) {
        velocity = velocity.normalize() * maxSpeed;
    }

    position += velocity * deltaTime;

    forces = Vector2(0, 0);
    impulses = Vector2(0, 0);

    if (velocity.magnitude() < 0.1f) {
        velocity = Vector2(0, 0);
    }

}

