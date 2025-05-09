#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2.h" 

class Shape
{
	public:
		Shape(); 
		virtual void SetShapeColor(const sf::Color& color) = 0;
		virtual void SetShapePosition(const Vector2& position) = 0; 
		virtual const float GetArea() const = 0; 
		virtual const sf::Shape& GetShape() const = 0;
};

