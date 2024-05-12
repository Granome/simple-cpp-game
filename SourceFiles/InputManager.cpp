#include "InputManager.hpp"

sf::Vector2f InputManager::getMovementVectorFromWASD()
{
    sf::Vector2f movementVector;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        movementVector.y += 1; 
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        movementVector.x += 1; 
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        movementVector.y -= 1; 
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        movementVector.x -= 1; 
    }
    return normalizeVector2(movementVector);
}

sf::Vector2f InputManager::normalizeVector2(const sf::Vector2f& vector) 
    {
        float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);
        if (magnitude != 0)
            return sf::Vector2f(vector.x / magnitude, vector.y / magnitude);
        else
            return sf::Vector2f(0.f, 0.f); // Return zero vector if magnitude is zero
    }