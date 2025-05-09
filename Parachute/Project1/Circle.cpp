#include "Circle.h"
#include <iostream>

Circle::Circle(const float& radius) : radius(radius) {
	circleShape = sf::CircleShape(radius);
}

void Circle::SetOrigin(const Vector2& position) {
	circleShape.setOrigin(position.x, position.y); 
}

void Circle::SetShapeColor(const sf::Color& color) {
	circleShape.setFillColor(color); 
}

void Circle::SetShapePosition(const Vector2& position) {
	circleShape.setPosition(position.x, position.y);
}

const float Circle::GetArea() const {
	return radius; 
}

const sf::Shape& Circle::GetShape() const {
	return circleShape; 
}