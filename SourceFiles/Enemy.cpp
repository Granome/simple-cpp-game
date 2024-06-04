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
   if (currentTakingDamageCooldown <= 0) // so it cantake damage only once per some period
   {
      currentHP -= damage_;
      std::cout <<"here";
      if (currentHP <= 0)
      {
         death();
      }
      currentTakingDamageCooldown = takingDamageCooldown;
   }
}

void Enemy::death()
{
   changeAnimationState("death");
   dying = true;
   attackCooldown = 11111111;
   movementSpeed = 2;
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
   sf::Vector2f movementVector;
   if (findDistanceToPlayer(playerPos) > attackRange)
   {
      movementVector = sf::Vector2f(getUnitVectorToPlayer(playerPos) * elapsed.asSeconds() * movementSpeed);
      move(movementVector);
   }

   //managing facing
   if (movementVector.x < 0)
   {
      facing = "left";
   }
   else
   {
      facing = "right";
   }


   attackCooldown -= elapsed.asSeconds();
   if (attackCooldown < 0)
   {
      attackCooldown = 0;
   }

   currentTakingDamageCooldown -= elapsed.asSeconds();

}

void Enemy::attack(Player& player)
{
      if (getDistanceToPlayer() <= attackRange)
      {
         if (attackCooldown <= 0)
         {
            player.takeDamage(damagePerHit);
            attackCooldown += 1.0/attackSpeed;
            changeAnimationState("attack");
         }
      }
}

float Enemy::getDistanceToPlayer()
{
   return (distanceToPlayer);
}


std::string Enemy::getFacing()
{
   return facing;
}

void Enemy::setFacing(std::string newFacing)
{
   facing = newFacing;
}