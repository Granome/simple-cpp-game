#pragma once

#include "AnimatedSprite.hpp"
#include "Collider.hpp"

class Enemy : public AnimatedSprite, Collider
{
protected:
    double maxHP;
    double currentHP;
    double movementSpeed;
    int attackRange;
    double damagePerHit;
    float attackSpeed;

public:
    Enemy(double maxHP_=50, double movementSpeed_=0,
       int attackRange_=30, double damagePerHit_=0,float attackSpeed_=1);

    void attack();
    void takeDamage(double damage_);
    void movetowardsPlayer();
    int getDistanceToPlayer();
    void death();
};