// Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "SFML/Graphics.hpp"
#include "Rigidbody.h"

int main()
{

    sf::RenderWindow current_window( sf::VideoMode(800, 800), "Test" );
    sf::Event e;

    Rigidbody rigidbody( 1.0f, 0.05f, 1.0f ); // mass, friction, gravity
    rigidbody.position = Vector2(400, 400);  // Initial position at the center of the screen

    sf::CircleShape circle(20); // radius = 20
    circle.setFillColor(sf::Color::Green);

    Vector2 appliedForce(60, 10);  // Apply a force of 50 units to the right
    rigidbody.addForce(appliedForce); 

    while ( current_window.isOpen() ) 
    {

        while (current_window.pollEvent(e)) 
        {

            if (e.type == sf::Event::Closed)
                current_window.close(); 

        }

        rigidbody.update(0.016f);

        // Set the circle's position based on the Rigidbody's position
        circle.setPosition(rigidbody.position.x, rigidbody.position.y);

        std::cout << rigidbody.velocity << std::endl;

        // Clear the window
        current_window.clear();

        // Draw the circle
        current_window.draw(circle);

        // Display everything we just rendered
        current_window.display();
    }


    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
