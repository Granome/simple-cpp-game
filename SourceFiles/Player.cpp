#include "Player.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"
#include "cmath"

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

    AnimationState hit_down("hit_down", 6, false);
    AnimationState hit_up("hit_up", 6, false);
    AnimationState hit_left("hit_left", 6, false);
    AnimationState hit_right("hit_right", 6, false);

    AnimationState death_down("death_down", 11, false);
    AnimationState death_up("death_up", 11, false);
    AnimationState death_left("death_left", 11, false);
    AnimationState death_right("death_right", 11, false);

    AnimationState dead_down("dead_down", 1, true);
    AnimationState dead_up("dead_up", 1, true);
    AnimationState dead_left("dead_left", 1, true);
    AnimationState dead_right("dead_right", 1, true);

    std::vector<AnimationState> animationStates =  {idle_down, idle_left, idle_right, idle_up,
                                            move_down, move_left, move_right, move_up,
                                            hit_down, hit_left, hit_right, hit_up,
                                            death_down, death_left, death_right, death_up,
                                            dead_down, dead_left, dead_right, dead_up
                                            };

    this->setPosition(300, 300);
    this->changeAnimationState("idle");
    Animation animation("..\\Resourses\\Animations\\Character.png", 112, animationStates);
    this->setAnimation(animation);
    this->setFps(5);
}

void Player::addBullet(float angle)
{
    bullets.emplace_back(angle);
}

void Player::takeDamage(double damage)
{

    HP -= damage;
    if (HP <= 0)
    {
        if (!dead)
        {
            death();
        }
    }
}
void Player::death()
{
    std::string facingStr;
    switch (facing)
    {
        case 0:
            facingStr = "_up";
            break;
        case 1:
            facingStr = "_down";
            break;
        case 2:
            facingStr = "_left";
            break;
        case 3:
            facingStr = "_right";
            break;
    }
    dead = true;
    shotCooldown = 30;
    movementSpeed = 2;
    setFps(12);
    changeAnimationState("death"+facingStr);
}

float Player::getMovementSpeed()
{
    return movementSpeed;
}

bool Player::isDead()
{
    return dead;
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


sf::Vector2f Player::findClosestEnemy(const std::vector<std::unique_ptr<sf::Drawable>>& gameObjects)
{
    //finding centre of player
    sf::FloatRect playerBounds= getGlobalBounds();
    sf::Vector2f playerPos = sf::Vector2f(playerBounds.left + playerBounds.width/2, playerBounds.top + playerBounds.height/2);
    
    sf::Vector2f closestEnemy(INFINITY, INFINITY);

    for (const auto& gameObject : gameObjects)
    {
        if (Enemy* enemy = dynamic_cast<Enemy*>(gameObject.get()))
        {
            //finding centre of enemy
            sf::FloatRect enemyBounds= enemy->getGlobalBounds();
            sf::Vector2f enemyPos = sf::Vector2f(enemyBounds.left + enemyBounds.width/2, enemyBounds.top + enemyBounds.height/2);
            
            if(findDistance(playerPos, closestEnemy) > findDistance(playerPos, enemyPos))
            {
                //std::cout << enemyPos.x << " " << enemyPos.y << std::endl;
                closestEnemy = enemyPos;
            }
        }
    }
    positionOfClosestEnemy = closestEnemy;
    return closestEnemy;
}

float Player::findDistance(sf::Vector2f pos1, sf::Vector2f pos2)
{
    return sqrt(pow(pos1.x-pos2.x, 2)+pow(pos1.y-pos2.y, 2));
}


void Player::shoot(std::vector<std::unique_ptr<sf::Drawable>>& gameObjects, sf::Time elapsed)
{
    if (shotCooldown <= 0)
    {


        // Finding shooting angle
        sf::FloatRect playerBounds = getGlobalBounds();
        sf::Vector2f playerPos(playerBounds.left + playerBounds.width / 2, playerBounds.top + playerBounds.height / 2);

        double shootingAngle = calculate_angle(playerPos, positionOfClosestEnemy);
        //std::cout << positionOfClosestEnemy.x << " " << positionOfClosestEnemy.y << std::endl;

        // Spawning bullets and assigning their movement vectors and all the values
        for (auto bulletAngleOffset : bullets)
        {
            // Finding unit vector based on angle
            double bulletAngle = bulletAngleOffset + shootingAngle;
            sf::Vector2f movementVector(normalizeVector2(sf::Vector2f(cos(bulletAngle * 3.14159265 / 180.0), sin(bulletAngle * 3.14159265 / 180.0))));

            //std::cerr << "Bullet angle: " << bulletAngle << ", Movement vector: (" << movementVector.x << ", " << movementVector.y << ")" << std::endl;

            // Creating bullet and adding it to the vector of game objects
            auto bullet = std::make_unique<Bullet>(damage, criticalHitChance, criticalDamageCoefficient, bulletVelocity, bulletRange, bulletPenetration, movementVector);
            bullet->setPosition(playerPos);
            bullet->move(movementVector.x * 30, movementVector.y * 30);

            gameObjects.emplace_back(std::move(bullet));
        }

        shotCooldown += 1.0f / attackSpeed;
    }
    else
    {
        shotCooldown -= elapsed.asSeconds();
    }
}


double Player::calculate_angle(sf::Vector2f pos1, sf::Vector2f pos2) 
{

    double dx = pos2.x - pos1.x;

    double dy = pos2.y - pos1.y;

    double angle_in_radians = atan2(dy, dx);

    double angle_in_degrees = angle_in_radians * 180.0 / 3.14159265;

    if (angle_in_degrees < 0) {
        angle_in_degrees += 360;
    }

    return angle_in_degrees;
}

double Player::getCurrentHP()
{
    return HP;
}

double Player::getMaxHp()
{
    return maxHP;
}




sf::Vector2f Player::normalizeVector2(const sf::Vector2f& vector) 
{
    float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    if (magnitude != 0)
        return sf::Vector2f(vector.x / magnitude, vector.y / magnitude);
    else
        return sf::Vector2f(0.f, 0.f); // Return zero vector if magnitude is zero
}


