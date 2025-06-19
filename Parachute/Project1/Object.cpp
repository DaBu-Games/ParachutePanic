#include "Object.h"
#include "GameManager.h"

Object::Object( float mass, float drag, const Vector2& screenSize, const Vector2& position, GameManager& manager )
	: rigidbody( mass, drag, position ), screenSize(screenSize), manager( manager ) {}

void Object::Update() {

}

void Object::SetPosition() {

}

void Object::Draw() {

}

void Object::BorderDetection() {

}

Vector2 Object::GetPosition() {
	return rigidbody.GetPosition();
}