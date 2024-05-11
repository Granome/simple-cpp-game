#include "Player.hpp"

Player::Player()
{
    
}

void Player::addBullet(float angle)
{
    bullets.emplace_back(angle);
}

double Player::getCurrentHP()
{
    return HP;
}

void Player::takeDamage(double damage)
{
    HP -= damage;
    if (HP <= 0)
   {
      death();
   }
}
void Player::death()
{
    
}