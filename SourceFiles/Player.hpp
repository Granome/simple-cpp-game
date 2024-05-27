#pragma once

#include "AnimatedSprite.hpp"
#include <iostream>


//Usage of enumurator
enum PlayerFacing
{
    up,
    down,
    left,   
    right
};


class Player : public AnimatedSprite
{
private:
    double maxHP=100;
    double HP=100;
    float attackSpeed=1;
    float Damage=35;
    float criticalHitChance=0.1;
    float criticalDamageCoefficient=1.3;
    int movementSpeed=100;
    std::vector<float> bullets={0}; // vector consists of angles. For example 0 - bullet forward, 180 - bullet backwards
    bool bulletPenetration=false;
    PlayerFacing facing = down;
    

public:
    Player();
    void shoot();
    void death();
    void takeDamage(double damage_);
    void addBullet(float angle=0);
    float getMovementSpeed();
    double getCurrentHP();
    void setFacing(PlayerFacing newFacing);
    PlayerFacing getFacing();
    void addBeard();
};


