#include "Enemy.hpp"

Enemy::Enemy(double maxHP_, double movementSpeed_,
       int attackRange_, double damagePerHit_, float attackSpeed_, int xpDrop_) : Collider(sf::FloatRect(getGlobalBounds().left+getGlobalBounds().width/4, getGlobalBounds().top+getGlobalBounds().height/4, getGlobalBounds().width/2, getGlobalBounds().height/2))
   {
      maxHP = maxHP_;
      currentHP = maxHP;
      movementSpeed = movementSpeed_;
      attackRange = attackRange_;
      damagePerHit = damagePerHit_;
      attackSpeed = attackSpeed_;
      xpDrop = xpDrop_;

      uid = generateUID();
   }

void Enemy::takeDamage(double damage_, EnemySpawner& enemySpawner)
{
   if (currentTakingDamageCooldown <= 0) // so it cantake damage only once per some period
   {
      currentHP -= damage_;
      if (currentHP <= 0)
      {
         death(enemySpawner);
      }
      currentTakingDamageCooldown = takingDamageCooldown;
   }
}

void Enemy::death(EnemySpawner& enemySpawner)
{
   if (getAnimationState() == "death_right" || getAnimationState() == "death_left") 
   {
      return;
   }
   changeAnimationState(std::string("death") + "_" + facing);
   dying = true;
   attackCooldown = 11111111;
   movementSpeed = 2;
   enemySpawner.addXP(xpDrop);
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
            changeAnimationState(std::string("attack") + "_" + facing);
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


uint64_t Enemy::getUID()
{
   return uid;
}


int Enemy::getXpDrop()
{
   return xpDrop;
}


void Enemy::setFacing(std::string newFacing)
{
   facing = newFacing;
}



uint64_t Enemy::generateUID() 
{
   static std::random_device rd;  // Seed for the random number engine
   static std::mt19937_64 gen(rd()); // Mersenne Twister engine
   static std::uniform_int_distribution<uint64_t> dis;

   return dis(gen);
}