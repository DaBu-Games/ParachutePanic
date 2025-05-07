// Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "SFML/Graphics.hpp"
#include "Rigidbody.h"

int main()
{

    sf::RenderWindow current_window( sf::VideoMode(800, 800), "Test" );
    sf::Event e;

    sf::Clock clock; 

    Rigidbody rigidbody( 1.0f, 0.8f, 1.0f ); // mass, friction, gravity
    rigidbody.position = Vector2(400, 400); 

    sf::CircleShape circle(20);
    circle.setFillColor(sf::Color::Green);

    while ( current_window.isOpen() ) 
    {

        while (current_window.pollEvent(e)) 
        {

            if (e.type == sf::Event::Closed)
                current_window.close(); 

        }

        float deltaTime = clock.restart().asSeconds();
        rigidbody.addForce(Vector2(5, 10));
        rigidbody.update(deltaTime);

        // Set the circle's position based on the Rigidbody's position
        circle.setPosition(rigidbody.position.x, rigidbody.position.y);

        std::cout << deltaTime << std::endl;

        // Clear the window
        current_window.clear();

        // Draw the circle
        current_window.draw(circle);

        // Display everything we just rendered
        current_window.display();
    }
}
