#include "Game.hpp"

Game::Game()
{
    window.create(sf::VideoMode(800, 600), "My window");
}

void Game::start()
{

    window.clear(sf::Color::Black);


    RectEnemy enemy1;
    enemy1.setPosition(0, 0);

    gameObjects.emplace_back(std::make_unique<Enemy>(enemy1));

    update();

    
    

}

void Game::update()
{

    sf::Time elapsed = clock.restart();


    while (window.isOpen()) 
    {

        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for (const auto& gameObject : gameObjects)
        {
            if (Player* p = dynamic_cast<Player*>(gameObject.get()))
            {
                
            }
            else
            {

            }
            window.draw(*gameObject);
        }

        window.display();
    }
}


