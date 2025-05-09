// Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "SFML/Graphics.hpp"
#include "Player.h"

int main()
{

    sf::RenderWindow currentWindow( sf::VideoMode(800, 800), "ParachutePanic" );
    sf::Event e;

    Player player = Player(currentWindow); 

    sf::Clock clock; 

    while ( currentWindow.isOpen() ) 
    {

        while (currentWindow.pollEvent(e)) 
        {

            if (e.type == sf::Event::Closed)
                currentWindow.close(); 

        }

        // Clear the window
        currentWindow.clear();

        float deltaTime = clock.restart().asSeconds();
        
        player.Move(deltaTime); 

        // Display everything we just rendered
        currentWindow.display();
    }
}
