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
    double HP=50;
    float attackSpeed=0.6;
    float damage=35;
    float criticalHitChance=0.1;
    float criticalDamageCoefficient=1.3;
    int movementSpeed=100;
    std::vector<float> bullets={0, 180}; // vector consists of angles. For example 0 - bullet forward, 180 - bullet backwards
    bool bulletPenetration=false;
    float bulletVelocity=140;
    float bulletRange=300; // maximum distance bullet can travel
    PlayerFacing facing = down;
    sf::Vector2f positionOfClosestEnemy;
    float shotCooldown=1;




    sf::Vector2f normalizeVector2(const sf::Vector2f& vector);
    

public:
    Player();
    void shoot(std::vector<std::unique_ptr<sf::Drawable>>& gameObjects, sf::Time elapsed);
    void death();
    void takeDamage(double damage_);
    void addBullet(float angle=0);
    float getMovementSpeed();
    double getCurrentHP();
    double getMaxHp();


    void setFacing(PlayerFacing newFacing);
    PlayerFacing getFacing();
    void addBeard();

    float findDistance(sf::Vector2f pos1, sf::Vector2f pos2);
    sf::Vector2f findClosestEnemy(const std::vector<std::unique_ptr<sf::Drawable>>& gameObjects);
    double calculate_angle(sf::Vector2f pos1, sf::Vector2f pos2);



};


