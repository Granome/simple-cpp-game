#include "Player.hpp"

Player::Player()
{
    AnimationState idle("idle", 3, true);
    AnimationState running("running", 6, true);
    this->setPosition(300, 300);
    this->changeAnimationState("idle");
    Animation animation("..\\Resourses\\Animations\\character.png", 9, {idle, running});
    this->setAnimation(animation);
    this->setFps(5);
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
    std::cout << "DEATH";
}

float Player::getMovementSpeed()
{
    return movementSpeed;
}