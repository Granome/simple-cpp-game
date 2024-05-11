#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>

#include "Player.hpp"

class Game
{
private:
    std::vector<std::unique_ptr<sf::Drawable>> gameObjects;
    int currentDifficulty;
    double totalTime;
    float timeScale;
    void GameLoop();
    void DrawFrame();
public:
    Game();
    void start();
    void update();
};