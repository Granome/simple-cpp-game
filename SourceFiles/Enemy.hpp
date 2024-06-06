#pragma once

#include "AnimatedSprite.hpp"
#include "Collider.hpp"
#include "Player.hpp"
#include "EnemySpawner.hpp" 

#include <random>
#include <cstdint>
#include <cmath>

class Enemy : public AnimatedSprite, public Collider
{
protected:
    double maxHP;
    double currentHP;
    float movementSpeed;
    int attackRange;
    double damagePerHit;
    float attackSpeed;
    int xpDrop;


    float attackCooldown = 1;

    float distanceToPlayer;

    float takingDamageCooldown = 0;
    float currentTakingDamageCooldown = 0;


    std::string facing = "left";

    uint64_t uid;

    static uint64_t generateUID();

public:
    bool dying = false;

    Enemy(double maxHP_=50, double movementSpeed_=0,
       int attackRange_=30, double damagePerHit_=0,float attackSpeed_=1, int xpDrop_=10);

    void attack(Player& player);
    void takeDamage(double damage_, EnemySpawner& enemySpawner);
    void moveTowardsPlayer(sf::Vector2f playerPos, sf::Time elapsed);
    float findDistanceToPlayer(sf::Vector2f playerPos);
    float getDistanceToPlayer();
    void death(EnemySpawner& enemySpawner);

    std::string getFacing();
    uint64_t getUID();
    int getXpDrop();

    void setFacing(std::string newFacing);

    sf::Vector2f getUnitVectorToPlayer(sf::Vector2f playerPos);

    virtual ~Enemy() = default;
};