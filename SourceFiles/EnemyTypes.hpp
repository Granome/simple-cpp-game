#pragma once

#include "Enemy.hpp"





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
