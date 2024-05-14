#pragma once

#include "AnimatedSprite.hpp"
#include "Collider.hpp"
#include <cmath>

class Enemy : public AnimatedSprite, Collider
{
protected:
    double maxHP;
    double currentHP;
    double movementSpeed;
    int attackRange;
    double damagePerHit;
    float attackSpeed;

    float distanceToPlayer;

public:
    Enemy(double maxHP_=50, double movementSpeed_=0,
       int attackRange_=30, double damagePerHit_=0,float attackSpeed_=1);

    void attack();
    void takeDamage(double damage_);
    void movetowardsPlayer();
    float findDistanceToPlayer(sf::Vector2f playerPos);
    float getDistanceToPlayer();
    void death();
};