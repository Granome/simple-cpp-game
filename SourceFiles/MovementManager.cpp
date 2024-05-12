#include "MovementManager.hpp"

void MovementManager::drawGameObjects(std::vector<std::unique_ptr<sf::Drawable>>& gameObjects, sf::Time elapsed, const float& timeScale)
{
    float currentPlayerSpeed = 0;


    sf::Vector2f movementVector = inputManager.getMovementVectorFromWASD();
    
    elapsed *= timeScale;


    for (const auto& gameObject : gameObjects)
    {


        if (Player* p = dynamic_cast<Player*>(gameObject.get()))
        {

            currentPlayerSpeed = p->getMovementSpeed();
            if(movementVector == sf::Vector2f(0, 0))
            {
                p->changeAnimationState("idle");
            }
            else
            {
                p->changeAnimationState("running");
            }
            p->animate(elapsed);

        }

        else
        {
            sf::Sprite* s = dynamic_cast<sf::Sprite*>(gameObject.get());
            s->move(movementVector * elapsed.asSeconds() * currentPlayerSpeed);
        }
    }
}