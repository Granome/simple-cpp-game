#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "AnimatedSprite.hpp"
#include "Collider.hpp"




class Bullet : public AnimatedSprite, public Collider
{
private:
    float damage_;
    float criticalHitChance_;
    float criticalDamageCoefficient_;
    float movementSpeed_;
    float maxFlightDistance_;
    bool penetrating_;

    float currentFightDistance_=0;
    sf::Vector2f movementUnitVector_;



public:
    std::vector<uint64_t> damagedEnemies;
    bool exploading = false;

    
    Bullet(float damage, float criticalHitChance,float criticalDamageCoefficient, 
    int movementSpeed, float maxFlightDistance, bool penetrating, sf::Vector2f movementUnitVector);

    void moveBullet(sf::Time elapsed);

    float getDamage();
    
    bool isPenetrating();

    void blowUp();
};