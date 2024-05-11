#include "Enemy.hpp"

Enemy::Enemy(double maxHP_, double movementSpeed_,
       int attackRange_, double damagePerHit_, float attackSpeed_) : Collider(getBounds())
   {
      maxHP = maxHP_;
      currentHP = maxHP;
      movementSpeed = movementSpeed_;
      attackRange = attackRange_;
      damagePerHit = damagePerHit_;
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

