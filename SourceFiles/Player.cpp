#include "Player.hpp"

Player::Player()
{

    //Equipment

    //Player
    AnimationState idle_down("idle_down", 4, true);
    AnimationState idle_up("idle_up", 4, true);
    AnimationState idle_left("idle_left", 4, true);
    AnimationState idle_right("idle_right", 4, true);

    AnimationState move_down("move_down", 6, true);
    AnimationState move_up("move_up", 6, true);
    AnimationState move_left("move_left", 6, true);
    AnimationState move_right("move_right", 6, true);

    std::vector<AnimationState> animationStates =  {idle_down, idle_left, idle_right, idle_up, move_down, move_left, move_right, move_up};

    this->setPosition(300, 300);
    this->changeAnimationState("idle");
    Animation animation("..\\Resourses\\Animations\\Character.png", 108, animationStates);
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


void Player::setFacing(PlayerFacing newFacing)
{
    facing = newFacing;
}


PlayerFacing Player::getFacing()
{
    return facing;
}

void Player::addBeard()
{
    sf::Texture tex0;
    if (!tex0.loadFromFile("..\\Resourses\\Animations\\Character.png")) {
        std::cerr << "Failed to load Character.png" << std::endl;
    }

    // Load the second texture
    sf::Texture tex1;
    if (!tex1.loadFromFile("..\\Resourses\\Animations\\Equipment\\Beard.png")) {
        std::cerr << "Failed to load Beard.png" << std::endl;
    }

    // Create a render texture with the appropriate size
    sf::RenderTexture renderTexture;
    if (!renderTexture.create(tex0.getSize().x, tex0.getSize().y)) {
        std::cerr << "Failed to create render texture" << std::endl;
    }
    renderTexture.clear(sf::Color::Transparent);

    // Draw the first texture
    sf::Sprite sprite0(tex0);
    renderTexture.draw(sprite0, sf::BlendAlpha);

    // Draw the second texture with blending mode to handle transparency
    sf::Sprite sprite1(tex1);
    renderTexture.draw(sprite1, sf::BlendAlpha);  // Using sf::BlendAlpha to handle transparency correctly

    // Display the render texture to finalize the drawing
    renderTexture.display();

    // Get the combined texture
    sf::Texture newTexture = renderTexture.getTexture();

    Animation newAnimation = getAnimation();
    newAnimation.texture = newTexture;
    this->setAnimation(newAnimation);
}