#include "EnemySpawner.hpp"
#include "EnemyTypes.hpp"


EnemySpawner::EnemySpawner(sf::Vector2f playerPosition)
{
    playerPos = playerPosition;
}


void EnemySpawner::setPlayerPosition(sf::Vector2f playerPosition)
{
    playerPos = playerPosition;
}


void EnemySpawner::spawnEnemy(int enemyNumber, std::vector<std::unique_ptr<sf::Drawable>>& gameObjects)
{
    std::unique_ptr<Enemy> newEnemy;
    switch (enemyNumber)
    {
        case 0:

            newEnemy = std::make_unique<Bat>();
            break;
    }
    if (newEnemy)
    {
        newEnemy->setPosition(findRandomPosition(playerPos, enemySpawnRange));
        gameObjects.emplace_back(std::move(newEnemy));

    }


}


int randomInt(int min, int max) 
{
    srand((unsigned) time(NULL));

    if (max-min != 0)
    {
        return rand()%(max-min)+min;
    }
    else
    {
        return 0;
    }
        
    //return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}


float toRadians(float degrees) {
    return degrees * M_PI / 180.0f;
}

sf::Vector2f EnemySpawner::findRandomPosition(sf::Vector2f playerPos, sf::Vector2f enemySpawnRange) {
    // Choose a random angle in degrees
    float angle = randomInt(0, 360);

    // Convert angle to radians
    float angleRadians = toRadians(angle);

    // Choose a random distance
    float distance = randomInt(enemySpawnRange.x, enemySpawnRange.y);

    // Calculate new coordinates
    float newX = playerPos.x + distance * cos(angleRadians);
    float newY = playerPos.y + distance * sin(angleRadians);

    return sf::Vector2f(newX, newY);
}

int EnemySpawner::chooseNextEnemy(int currentLevel)
{
    unsigned int maxEnemy = currentLevel/3.0;
    return randomInt(0, maxEnemy);
}


void EnemySpawner::update(sf::Time elapsed, std::vector<std::unique_ptr<sf::Drawable>>& gameObjects)
{
    currentDifficultyPoints += difficultyAccumulation * elapsed.asSeconds();

    if (enemyDifficultyCost[nextEnemy] <= currentDifficultyPoints)
    {
        currentDifficultyPoints -= enemyDifficultyCost[nextEnemy];
        spawnEnemy(nextEnemy, gameObjects);
        //std::cout << currentDifficultyPoints << std::endl;
        chooseNextEnemy(0);
    }
}


int EnemySpawner::getCurrentXp()
{
    return currentXP;
}

int EnemySpawner::getXpForNextLevel()
{
    return xpForNextLevel;
}

int EnemySpawner::getCurrentLevel()
{
    return currentLVL;
}

void EnemySpawner::calculateXPForNextLevel()
{
    xpForNextLevel = xpForNextLevel + currentLVL*100;
}

void EnemySpawner::levelUp()
{
    currentLVL++;
    difficultyAccumulation *= 1.4;
    calculateXPForNextLevel();
}

void EnemySpawner::addXP(int xp)
{
    currentXP += xp;
    while (currentXP >= xpForNextLevel)
    {
        levelUp();
    }
}