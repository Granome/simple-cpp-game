#include "Player.hpp"

Player::Player()
{
    AnimationState idle("idle", 4, true);
    AnimationState idle_left("idle_left", 4, true);
    AnimationState idle_right("idle_right", 4, true);
    AnimationState idle_forward("idle_forward", 4, true);

    this->setPosition(300, 300);
    this->changeAnimationState("idle");
    Animation animation("..\\Resourses\\Animations\\player.png", 16, {idle, idle_left, idle_right, idle_forward});
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