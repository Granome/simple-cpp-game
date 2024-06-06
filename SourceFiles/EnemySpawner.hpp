#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class EnemySpawner 
{
private:
    sf::Vector2f playerPos;
    sf::Vector2f enemySpawnRange = sf::Vector2f(400, 500);
    float currentDifficultyPoints = 0;
    float difficultyAccumulation = 0.3;
    int nextEnemy = 0;

    int currentLVL=1;
    int currentXP=0;
    int xpForNextLevel=100;

    std::vector<int> enemyDifficultyCost = 
    {
        1, //Bat
        5, //Crab

    };

public:
    EnemySpawner(sf::Vector2f playerPosition=sf::Vector2f(0, 0));
    sf::Vector2f findRandomPosition(sf::Vector2f playerPos, sf::Vector2f enemySpawnRange);
    void spawnEnemy(int enemyNumber, std::vector<std::unique_ptr<sf::Drawable>>& gameObjects);
    int chooseNextEnemy(int currentLevel);


    void update(sf::Time elapsed, std::vector<std::unique_ptr<sf::Drawable>>& gameObjects);

    int getCurrentXp();
    int getCurrentLevel();
    int getXpForNextLevel();
    void setPlayerPosition(sf::Vector2f playerPosition);

    void addXP(int xp);
    void levelUp();
    void calculateXPForNextLevel();
};