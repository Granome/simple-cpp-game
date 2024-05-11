#include "Game.hpp"

Game::Game(){}

void Game::start()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Random shapes grid");
    window.clear(sf::Color::Black);




    

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

}

void Game::update()
{
    
}


