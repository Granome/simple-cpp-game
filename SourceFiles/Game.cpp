#include "Game.hpp"


Game::Game()
{
    window.create(sf::VideoMode(800, 600), "The great Obliterator");
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

    enemySpawner.setPlayerPosition(player.getPosition());

    gameObjects.emplace_back(std::make_unique<Player>(player));






    


    HealthBar healthBar(40, 510, 200, 20);
    uiObjects.emplace_back(std::make_unique<HealthBar>(healthBar));

    
    XpBar xpBar(40, 550, 180, 15);
    uiObjects.emplace_back(std::make_unique<XpBar>(xpBar));

    enemySpawner.spawnEnemy(1, gameObjects);


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
        updateHealthBar();
        updateXPBar(enemySpawner);
        enemySpawner.update(elapsed * timeScale, gameObjects);




        window.clear(sf::Color::Black);


        for (const auto& gameObject : gameObjects)
        {
            window.draw(*gameObject);
        }
        for (const auto& uiObject : uiObjects)
        {
            window.draw(*uiObject);
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
                    enemyCollider.setBounds(sf::FloatRect(e->getGlobalBounds().left+e->getGlobalBounds().width/4, e->getGlobalBounds().top+e->getGlobalBounds().height/4, e->getGlobalBounds().width/2, e->getGlobalBounds().height/2)); // updating collider bounds
                    //std::cout << b->getGlobalBounds().left << std::endl;;
                    if (b->checkCollision(enemyCollider))
                    {
                        if (std::find(b->damagedEnemies.begin(), b->damagedEnemies.end(), e->getUID()) == b->damagedEnemies.end())
                        {
                            e->takeDamage(b->getDamage(), enemySpawner);
                            b->damagedEnemies.emplace_back(e->getUID());
                            if (!b->isPenetrating())
                            {
                                b->blowUp();
                            }
                        }
                    }
                }
            } 
        }
    } 
}

void Game::updateHealthBar()
{
    double currentHP;
    double maxHP;
    for (const auto& gameObject : gameObjects)
    {
        if (!gameObject)
        {
            std::cerr << "Null pointer found in gameObjects" << std::endl;
            continue;
        }
        if (Player* p = dynamic_cast<Player*>(gameObject.get()))
        {
            currentHP = p->getCurrentHP();
            maxHP = p->getMaxHp();
        }
    }
    for (const auto& uiObject : uiObjects)
    {
        if (HealthBar* hb = dynamic_cast<HealthBar*>(uiObject.get()))
        {
            hb->update(currentHP, maxHP);

        }

    }
}

void Game::updateXPBar(EnemySpawner enemySpawner)
{
    double currentXP = enemySpawner.getCurrentXp();
    double XpforNextLevel = enemySpawner.getXpForNextLevel();
    int currentLVL = enemySpawner.getCurrentLevel();
    for (const auto& uiObject : uiObjects)
    {
        if (!uiObject)
        {
            std::cerr << "Null pointer found in gameObjects" << std::endl;
            continue;
        }
        if (XpBar* xpb = dynamic_cast<XpBar*>(uiObject.get()))
        {

            xpb->update(currentXP, XpforNextLevel, currentLVL);

        }

    }
}