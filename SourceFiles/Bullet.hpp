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
    float currentFightDistance_=0;
    sf::Vector2f movementUnitVector_;

public:
    bool exploading = false;

    
    Bullet(float damage, float criticalHitChance,float criticalDamageCoefficient, 
    int movementSpeed, float maxFlightDistance, sf::Vector2f movementUnitVector);

    void moveBullet(sf::Time elapsed);

    float getDamage();

    void blowUp();
};