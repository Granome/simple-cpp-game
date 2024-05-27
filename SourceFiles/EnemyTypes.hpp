#pragma once

#include "Enemy.hpp"

class RectEnemy : public Enemy
{
private:
    sf::Texture tx;
public:
    RectEnemy() : Enemy(60, 30, 20, 40, 1)
    {
        
        tx.loadFromFile("..\\Resourses\\Animations\\player.png");
        this->setTexture(tx);
        this->setScale(1, 1);
        
    }
};