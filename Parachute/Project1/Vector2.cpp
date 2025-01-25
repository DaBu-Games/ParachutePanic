#include "Vector2.h"

// Constructure 
Vector2::Vector2( float x, float y ) : x(x), y(y) {}

// Adding
Vector2 Vector2::operator+(const Vector2& other) const {
	return Vector2( x + other.x, y + other.y );
}

// Subtracting
Vector2 Vector2::operator-(const Vector2& other) const {
	return Vector2( x - other.x, y - other.y );
}

// Scaling
Vector2 Vector2::operator*(const float scaler) const {
	return Vector2( x * scaler, y * scaler );
}

// Divide
Vector2 Vector2::operator/(const float scaler) const {
	return Vector2( x / scaler, y / scaler );
}

// Magnitude: sqrt of x2 + y2
float Vector2::magnitude() const {
	return std::sqrt( std::pow(x, 2) + std::pow(y, 2) );
}

// Normalize the vector: x & y / magnitude  
Vector2 Vector2::normalize() const {

	float mag = magnitude();

	return (mag > 0) ? Vector2(x / mag, y / mag) : Vector2(0, 0);

}