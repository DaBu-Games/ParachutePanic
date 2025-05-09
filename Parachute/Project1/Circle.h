#pragma once
#include "Shape.h"

class Circle : public Shape
{
	private:
		sf::CircleShape circleShape;
		float radius;

	public:
		Circle(const float& radius);
		void SetOrigin(const Vector2& position); 
		void SetShapeColor(const sf::Color& color) override;
		void SetShapePosition(const Vector2& position) override;
		const float GetArea() const override;
		const sf::Shape& GetShape() const override;
};

