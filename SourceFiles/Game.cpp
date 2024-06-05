#include "Game.hpp"

Game::Game()
{
    window.create(sf::VideoMode(800, 600), "My window");
}

void Game::start()
{

    window.clear(sf::Color::Black);
    window.setFramerateLimit(200);
    windowCentre = findWindowCentre(window);

    Background background;
    background.fillTheWindow(window.getSize());
    gameObjects.emplace_back(std::make_unique<Background>(background));
    

    Player player;
    
    player.setPosition(static_cast<sf::Vector2f>(windowCentre));
    player.move(-player.getGlobalBounds().width/2, -player.getGlobalBounds().height/2);
    player.addBeard();

    gameObjects.emplace_back(std::make_unique<Player>(player));




    Bat bat1;
    bat1.setPosition(100, 400);
    gameObjects.emplace_back(std::make_unique<Enemy>(bat1));



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
        movementManager.moveEnemies(gameObjects, elapsed, timeScale, windowCentre);
        movementManager.movePlayer(gameObjects, elapsed, timeScale);
        movementManager.moveBullets(gameObjects, elapsed, timeScale);

        checkEnemyAttacks();
        handleShooting(elapsed*timeScale);
        checkBulletHits();



        window.clear(sf::Color::Black);


        for (const auto& gameObject : gameObjects)
        {
            window.draw(*gameObject);
        }

        window.display();
    }
}


sf::Vector2f Game::findWindowCentre(sf::RenderWindow& window)
{
    return sf::Vector2f(window.getSize().x/2, window.getSize().y/2);
}


void Game::checkEnemyAttacks()
{
    Player* player;
    // Player always has to be before enemies in vector of game objects
    for (const auto& gameObject : gameObjects)
    {
        if (Player* p = dynamic_cast<Player*>(gameObject.get()))
        {
            player = p;
        }
        else if (Enemy* enemy = dynamic_cast<Enemy*>(gameObject.get()))
        {
            
            enemy->attack(*player);
        }
    }
}

void Game::handleShooting(sf::Time elapsed)
{
    for (const auto& gameObject : gameObjects)
    {
        if (!gameObject)
        {
            std::cerr << "Null pointer found in gameObjects" << std::endl;
            continue;
        }
        if (Player* p = dynamic_cast<Player*>(gameObject.get()))
        {
            p->findClosestEnemy(gameObjects);
            p->shoot(gameObjects, elapsed);
            return;
        }

    }
}

void Game::checkBulletHits()
{
    for (const auto& gameObject : gameObjects)
    {
        if (Bullet* b = dynamic_cast<Bullet*>(gameObject.get()))
        {
            b->setBounds(b->getGlobalBounds()); // updating collider bounds

            for (const auto& gameObject2 : gameObjects)
            {
                if (Enemy* e = dynamic_cast<Enemy*>(gameObject2.get()))
                {
                    Collider& enemyCollider = *e;
                    enemyCollider.setBounds(e->getGlobalBounds()); // updating collider bounds
                    //std::cout << b->getGlobalBounds().left << std::endl;;
                    if (b->checkCollision(enemyCollider))
                    {
                        e->takeDamage(b->getDamage());
                        b->blowUp();
                    }
                }
            } 
        }
    } 
}