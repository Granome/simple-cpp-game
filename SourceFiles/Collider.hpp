#pragma once
#include <vector>
#include <memory>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Collider
{
protected:
    sf::FloatRect bounds; 

public:
    Collider(sf::FloatRect _bounds); 

    virtual ~Collider() = default;

    sf::FloatRect getBounds();

    void setBounds(sf::FloatRect _bounds);


    bool checkCollision(Collider otherCollider); // AABB algorithm for 2D collision detection
        
};