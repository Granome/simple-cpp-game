#pragma once

#include "Enemy.hpp"





extern Animation batAnimation;
class Bat : public Enemy
{
public:
    Bat() : Enemy(70, 80, 40, 25, 1.2, 20)
    {
        changeAnimationState("idle");
        setAnimation(batAnimation);
        setScale(1.4, 1.4);
        setFps(8);

    }
};

extern Animation crabAnimation;
class Crab : public Enemy
{
public:
    Crab() : Enemy(300, 100, 40, 60, 1, 50)
    {
        changeAnimationState("idle");
        setAnimation(crabAnimation);
        setScale(1.4, 1.4);
        setFps(8);

    }
};

extern Animation slimeAnimation;
class Slime : public Enemy
{
public:
    Slime() : Enemy(700, 110, 40, 70, 0.8, 150)
    {
        changeAnimationState("idle");
        setAnimation(slimeAnimation);
        setScale(1.4, 1.4);
        setFps(8);

    }
};
