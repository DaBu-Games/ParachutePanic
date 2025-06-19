#pragma once

#include <cmath>

class Vector2
{
	public:
		float x;
		float y;

		Vector2( float x = 0, float y = 0 );

		Vector2 operator+(const Vector2 &other) const;
		Vector2 operator-(const Vector2& other) const;
		Vector2 operator*(const float scaler) const;
		Vector2 operator/(const float scaler) const;
		Vector2 operator+=(const Vector2& other); 

		float magnitude() const; 
		Vector2 normalize() const; 
};

