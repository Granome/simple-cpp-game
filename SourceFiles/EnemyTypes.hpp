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


class Bat : public Enemy
{
public:
Animation batAnimation = Animation("..\\Resourses\\Animations\\bat.png", 23, {AnimationState("move", 4, true) ,AnimationState("attack", 7, false), AnimationState("hit", 5, false), AnimationState("death", 11, false)});
    Bat() : Enemy(50, 50, 20, 10, 1.2)
    {
        setAnimation(batAnimation);
        setFps(4);
        setScale(-1.0f, 1.0f);
    }
};
