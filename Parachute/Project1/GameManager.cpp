#include "GameManager.h"

GameManager::GameManager(const Vector2& resolution)
    : window(sf::VideoMode(static_cast<unsigned int>(resolution.x), static_cast<unsigned int>(resolution.y)), "Parachute Panic"),
    deltaTime(0.0f) {
    player = std::make_unique<Player>(
        50.0f, // size
        500.0f, // move speed
        1.0f, // mass
        3.0f, // Drag
        resolution, // screen resolution
        Vector2(resolution.x / 2, resolution.y - 50), // position
        *this // Gamemanger refence
    );

    spawner = std::make_unique<EnemySpawner>(
        *this, // Gamemanger refence
        *player, // Player refence
        resolution // screen resolution
    );


    if (!font.loadFromFile("../Fonts/arial.ttf"))
    {
        std::cout << "font does NOT work";
    }
    scoreText.setFont(font); 
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(window.getSize().x - 150.0f, 10.0f);
    
    loseText.setFont(font);
    loseText.setCharacterSize(74);
    loseText.setFillColor(sf::Color::White);
    loseText.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    loseText.setString("You lose");
}


void GameManager::run() {

    sf::Clock clock;

    while ( window.isOpen() )
    {

        while ( window.pollEvent( event ) )
        {

            if (event.type == sf::Event::Closed) 
            {
                window.close();
            }

        }

        window.clear();

        if (gameOver) 
        {
            window.draw(loseText);
        }
        else 
        {
            deltaTime = clock.restart().asSeconds();
            update();
        }

        scoreText.setString("Score: " + std::to_string(score));
        window.draw(scoreText);

        window.display();
    }
}

void GameManager::update() {
    player->Update(); 
    spawner->Update(); 
}

void GameManager::Lose() {
    gameOver = true;
    std::cout << "Lose";
}

void GameManager::AddScore() {
    score++; 
}