#pragma once

#include "Enemy.hpp"



class RectEnemy : public Enemy
{
private:
    sf::Texture tx;
public:
    RectEnemy() : Enemy(60, 30, 20, 40, 1)
    {
        
        tx.loadFromFile("..\\Resourses\\Textures\\guy.png");
        this->setTexture(tx);
        this->setScale(1, 1);
        
    }
};

extern Animation batAnimation;
class Bat : public Enemy
{
public:
    Bat() : Enemy(50, 50, 20, 10, 1.2)
    {
        changeAnimationState("idle");
        setAnimation(batAnimation);
        setScale(1.4, 1.4);
        setFps(8);
    }
};
