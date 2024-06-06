#include "Bullet.hpp"


Animation bulletAnimation("..\\Resourses\\Animations\\Bullet.png", 8, {AnimationState("idle", 4, true), AnimationState("burst", 4, false)});

Bullet::Bullet(float damage, float criticalHitChance,float criticalDamageCoefficient, 
    int movementSpeed, float maxFlightDistance, bool penetrating, sf::Vector2f movementUnitVector) : Collider(getGlobalBounds())
    {
        damage_ = damage;
        criticalHitChance_ = criticalHitChance;
        criticalDamageCoefficient_= criticalDamageCoefficient;
        movementSpeed_ = movementSpeed;
        maxFlightDistance_ = maxFlightDistance;
        movementUnitVector_ = movementUnitVector;
        penetrating_ = penetrating;
        setAnimation(bulletAnimation);
        setFps(10);
        
    }

void Bullet::moveBullet(sf::Time elapsed)
{
    move(movementUnitVector_ * elapsed.asSeconds() * movementSpeed_);
}


float Bullet::getDamage()
{
    return damage_;
}

bool Bullet::isPenetrating()
{
    return penetrating_;
}

void Bullet::blowUp()
{
    //destroys bullet
    changeAnimationState("burst");
    exploading = true;
    movementSpeed_ = 5;
    
}