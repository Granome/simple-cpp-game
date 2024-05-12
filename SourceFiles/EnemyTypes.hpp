#pragma once

#include "Enemy.hpp"

class RectEnemy : public Enemy
{
private:
    sf::Texture tx;
public:
    RectEnemy() : Enemy(60, 10, 20, 10, 1)
    {
        
        tx.loadFromFile("..\\Resourses\\Textures\\wall.png");
        this->setTexture(tx);
        
    }
};