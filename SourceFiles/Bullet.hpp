#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "AnimatedSprite.hpp"
#include "Collider.hpp"

Animation bulletAnimation;

class Bullet : public AnimatedSprite, public Collider
{
private:
    float damage_;
    float criticalHitChance_;
    float criticalDamageCoefficient_;
    int movementSpeed_;
    float maxFlightDistance_;
    float currentFightDistance_=0;
    sf::Vector2f movementUnitVector_;
public:
    Bullet(float damage, float criticalHitChance,float criticalDamageCoefficient, 
    int movementSpeed, float maxFlightDistance, sf::Vector2f movementUnitVector) : Collider(getBounds())
    {
        damage_ = damage;
        criticalHitChance_ = criticalHitChance;
        criticalDamageCoefficient_= criticalDamageCoefficient;
        movementSpeed_ = movementSpeed;
        maxFlightDistance_ = maxFlightDistance;
        movementUnitVector_ = movementUnitVector;
        setAnimation(bulletAnimation);
    }
};