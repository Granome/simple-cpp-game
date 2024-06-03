#include "Enemy.hpp"

Enemy::Enemy(double maxHP_, double movementSpeed_,
       int attackRange_, double damagePerHit_, float attackSpeed_) : Collider(getGlobalBounds())
   {
      maxHP = maxHP_;
      currentHP = maxHP;
      movementSpeed = movementSpeed_;
      attackRange = attackRange_;
      damagePerHit = damagePerHit_;
      attackSpeed = attackSpeed_;
   }

void Enemy::takeDamage(double damage_)
{
   currentHP -= damage_;
   if (currentHP <= 0)
   {
      death();
   }
}

void Enemy::death()
{
   
}


float Enemy::findDistanceToPlayer(sf::Vector2f playerPos)
{
   sf::Vector2f position =  this->getPosition();
   position.x += this->getGlobalBounds().width/2;
   position.y += this->getGlobalBounds().height/2;
   distanceToPlayer = sqrt((playerPos.x - position.x)*(playerPos.x - position.x)+(playerPos.y - position.y)*(playerPos.y - position.y));
   return (distanceToPlayer);
}

sf::Vector2f Enemy::getUnitVectorToPlayer(sf::Vector2f playerPos)
{
   sf::Vector2f position =  this->getPosition();
   position.x += this->getGlobalBounds().width/2;
   position.y += this->getGlobalBounds().height/2;
   return ((playerPos-position) / findDistanceToPlayer(playerPos));
}

//this function runs on every frame
void Enemy::moveTowardsPlayer(sf::Vector2f playerPos, sf::Time elapsed)
{
   if (findDistanceToPlayer(playerPos) > attackRange)
   {
      move(getUnitVectorToPlayer(playerPos) * elapsed.asSeconds() * movementSpeed);
   }


   attackCooldown -= elapsed.asSeconds();
   if (attackCooldown < 0)
   {
      attackCooldown = 0;
   }

}

void Enemy::attack(Player& player)
{
      if (getDistanceToPlayer() <= attackRange)
      {
         if (attackCooldown <= 0)
         {
            player.takeDamage(damagePerHit);
            attackCooldown += 1.0/attackSpeed;
         }
      }
}

float Enemy::getDistanceToPlayer()
{
   return (distanceToPlayer);
}