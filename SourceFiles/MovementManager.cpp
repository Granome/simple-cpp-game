#include "MovementManager.hpp"
#include <memory>

void MovementManager::drawGameObjects(std::vector<std::unique_ptr<sf::Drawable>>& gameObjects, sf::Time elapsed, const float& timeScale)
{


    sf::Vector2f movementVector = inputManager.getMovementVectorFromWASD();
    
    elapsed *= timeScale;

    for (auto it = gameObjects.begin(); it != gameObjects.end(); ) {
    {
        

        if (Player* p = dynamic_cast<Player*>(it->get()))
        {
            //facing management
            //Horizontal facing is prioritized, so if player goes diagonaly, character will face horizontally 
            if (movementVector.x == -1)
            {
                p->setFacing(right);
            }
            else if (movementVector.x == 1)
            {
                p->setFacing(left);
            }
            else if (movementVector.y == 1)
            {
                p->setFacing(up);
            }
            else if (movementVector.y == -1)
            {
                p->setFacing(down);
            }

            std::string facingStr;
            //convert facing to string
            switch (p->getFacing())
            {
                case 0:
                    facingStr = "_up";
                    break;
                case 1:
                    facingStr = "_down";
                    break;
                case 2:
                    facingStr = "_left";
                    break;
                case 3:
                    facingStr = "_right";
                    break;
            }


            if(movementVector == sf::Vector2f(0, 0))
            {
                p->changeAnimationState("idle"+facingStr);
            }
            else
            {
                p->changeAnimationState("move"+facingStr);
                
            }

            p->animate(elapsed);

        }

        else if (Enemy* enemy = dynamic_cast<Enemy*>(it->get()))
        {
            enemy->changeAnimationState("move");
            //TODO: ANIMATIONS
            //Add facing for enemies, flip texture by multip. x of scale by -1.0
        }

        else if (Bullet* bullet = dynamic_cast<Bullet*>(it->get()))
        {
            bullet->animate(elapsed);
            if (bullet->getAnimationState() == "idle" && bullet->exploading)
            {
                it = gameObjects.erase(it);
                continue;
            }
        }
        ++it;
        
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

        else if (Enemy* enemy = dynamic_cast<Enemy*>(gameObject.get()))
        {
            enemy->move(movementVector * elapsed.asSeconds() * currentPlayerSpeed);
        }

        else if (Bullet* b = dynamic_cast<Bullet*>(gameObject.get()))
        {
            b->move(movementVector * elapsed.asSeconds() * currentPlayerSpeed);
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

void MovementManager::moveBullets(std::vector<std::unique_ptr<sf::Drawable>>& gameObjects, sf::Time elapsed, const float& timeScale)
{
    
    elapsed *= timeScale;

    for (const auto& gameObject : gameObjects)
    {
        if (Bullet* b = dynamic_cast<Bullet*>(gameObject.get()))
        {
            b->moveBullet(elapsed);
        }
    }

}



