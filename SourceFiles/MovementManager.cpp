#include "MovementManager.hpp"

void MovementManager::drawGameObjects(std::vector<std::unique_ptr<sf::Drawable>>& gameObjects, sf::Time elapsed, const float& timeScale)
{


    sf::Vector2f movementVector = inputManager.getMovementVectorFromWASD();
    
    elapsed *= timeScale;

    for (const auto& gameObject : gameObjects)
    {
        

        if (Player* p = dynamic_cast<Player*>(gameObject.get()))
        {

            if(movementVector == sf::Vector2f(0, 0))
            {
                p->changeAnimationState("idle");
            }
            else
            {
                p->changeAnimationState("idle_right");
            }
            p->animate(elapsed);

        }

        else
        {
            sf::Sprite* s = dynamic_cast<sf::Sprite*>(gameObject.get());
        }
    }
}


void MovementManager::movePlayer(std::vector<std::unique_ptr<sf::Drawable>>& gameObjects, sf::Time elapsed, const float& timeScale)
{
    float currentPlayerSpeed = 0;

    sf::Vector2f movementVector = inputManager.getMovementVectorFromWASD();
    
    elapsed *= timeScale;

    //Finding player movement speed
    for (const auto& gameObject : gameObjects)
    {        
        if (Player* p = dynamic_cast<Player*>(gameObject.get()))
        {
            currentPlayerSpeed = p->getMovementSpeed();
        }
    }

    //Processing movement
    for (const auto& gameObject : gameObjects)
    {        
        if (Background* bg = dynamic_cast<Background*>(gameObject.get()))
        {
            bg->updateTexturePositions(movementVector.x * elapsed.asSeconds() * currentPlayerSpeed, movementVector.y * elapsed.asSeconds() * currentPlayerSpeed);
        }

        if (Enemy* enemy = dynamic_cast<Enemy*>(gameObject.get()))
        {
            enemy->move(movementVector * elapsed.asSeconds() * currentPlayerSpeed);
        }
    }

}


void MovementManager::moveEnemies(std::vector<std::unique_ptr<sf::Drawable>>& gameObjects, sf::Time elapsed, const float& timeScale, sf::Vector2f playerPos)
{
    elapsed *= timeScale;

    for (const auto& gameObject : gameObjects)
    {
        if (Enemy* m = dynamic_cast<Enemy*>(gameObject.get()))
        {
            m->moveTowardsPlayer(playerPos, elapsed);
        }
    }
}