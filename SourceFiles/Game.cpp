#include "Game.hpp"

Game::Game(){}

void Game::start()
{

    srand((unsigned) time(NULL));
    sf::RenderWindow window(sf::VideoMode(800, 800), "Random shapes grid");
    window.clear(sf::Color::Black);
    float currentX = 0;
    float currentY = 0;
    // create some shapes
    // std::cout <<"here";

    for (int i = 0; i < 16; i++)
    {
        if (rand() % 2)
        {
            sf::CircleShape circle(100.0);
            circle.setPosition(currentX, currentY);
            circle.setFillColor(sf::Color(rand()%256, rand()%256, rand()%256));
            window.draw(circle);

        }
        else
        {
            sf::RectangleShape rectangle(sf::Vector2f(200.0, 200.0));
            rectangle.setPosition(currentX, currentY);
            rectangle.setFillColor(sf::Color(rand()%256, rand()%256, rand()%256));
            window.draw(rectangle);
        }
        if (currentX == 600.0)
        {
            currentX = 0;
            currentY += 200;
        }
        else
        {
            currentX += 200;
        }
    }
        window.display();
    window.setFramerateLimit(60);


    // run the program as long as the window is open
    while (window.isOpen()) {

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

    }

}

void Game::hello()
{
    std::cout << "HELLO?";
}
