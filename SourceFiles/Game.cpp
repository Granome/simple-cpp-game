#include "Game.hpp"

Game::Game()
{
    window.create(sf::VideoMode(800, 600), "My window");
}

void Game::start()
{

    window.clear(sf::Color::Black);
    window.setFramerateLimit(200);

    Player player;
    

    gameObjects.emplace_back(std::make_unique<Player>(player));


    RectEnemy enemy1;
    enemy1.setPosition(0, 0);

    gameObjects.emplace_back(std::make_unique<Enemy>(enemy1));

    update();

    
    

}

void Game::update()
{




    while (window.isOpen()) 
    {
        sf::Time elapsed = clock.restart();




        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
        movementManager.drawGameObjects(gameObjects, elapsed, timeScale);
        




        window.clear(sf::Color::Black);


        for (const auto& gameObject : gameObjects)
        {
            window.draw(*gameObject);
        }

        window.display();
    }
}


