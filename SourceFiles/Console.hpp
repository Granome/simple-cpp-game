#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <functional>
#include <unordered_map>
#include <vector>
#include <memory>
#include <sstream>

#include "UiElement.hpp" 
#include "Player.hpp"

class Console : public UiElement

{
private:
    std::vector<std::unique_ptr<sf::Drawable>>& gameObjects;

    sf::RectangleShape background;
    sf::Text inputText;
    sf::Text outputText;
    std::string inputString;
    std::vector<std::string> outputLog;


    std::unordered_map<std::string, std::function<void(const std::string&)>> commands;
    
    sf::Vector2f position;
    sf::Vector2f size;
    
    bool isOpen;


    void executeCommand(const std::string& input);


public:
    Console(float x, float y, float width, float height, std::vector<std::unique_ptr<sf::Drawable>>& gameObjects_);

    void registerCommand(const std::string& command, std::function<void(const std::string&)> func);

    void handleEvent(const sf::Event& event);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void update();

    bool getIsOpen();




    //Actual commands

    void setSpeed(std::string arg)
    {
        for (const auto& gameObject : gameObjects)
        {
            if (!gameObject)
            {
                continue;
            }
            if (Player* p = dynamic_cast<Player*>(gameObject.get()))
            {
                try 
                {
                    int speed = std::stoi(arg);

                    p->setMovementSpeed(speed);
                    outputLog.push_back("Speed is set to " + arg);


                }
                catch (const std::invalid_argument& e) 
                {
                    outputLog.push_back("Error: Invalid number format.");
                }

                catch (const std::out_of_range& e) 
                {
                    outputLog.push_back("Error: Number out of range.");
                }
            }
        }
    }

    void setMaxHP(std::string arg)
    {
        for (const auto& gameObject : gameObjects)
        {
            if (!gameObject)
            {
                continue;
            }
            if (Player* p = dynamic_cast<Player*>(gameObject.get()))
            {
                try 
                {
                    double d = std::stod(arg);

                    p->setMaxHP(d);
                    outputLog.push_back("Max HP is set to " + arg);


                }
                catch (const std::invalid_argument& e) 
                {
                    outputLog.push_back("Error: Invalid number format.");
                }

                catch (const std::out_of_range& e) 
                {
                    outputLog.push_back("Error: Number out of range.");
                }
            }
        }
    }

    void setHP(std::string arg)
    {
        for (const auto& gameObject : gameObjects)
        {
            if (!gameObject)
            {
                continue;
            }
            if (Player* p = dynamic_cast<Player*>(gameObject.get()))
            {
                try 
                {
                    double d = std::stod(arg);

                    p->setHP(d);
                    outputLog.push_back("HP is set to " + arg);


                }
                catch (const std::invalid_argument& e) 
                {
                    outputLog.push_back("Error: Invalid number format.");
                }

                catch (const std::out_of_range& e) 
                {
                    outputLog.push_back("Error: Number out of range.");
                }
            }
        }
    }

    void setAttackSpeed(std::string arg)
    {
        for (const auto& gameObject : gameObjects)
        {
            if (!gameObject)
            {
                continue;
            }
            if (Player* p = dynamic_cast<Player*>(gameObject.get()))
            {
                try 
                {
                    float n = std::stof(arg);

                    p->setAttackSpeed(n);
                    outputLog.push_back("Attack speed is set to " + arg);


                }
                catch (const std::invalid_argument& e) 
                {
                    outputLog.push_back("Error: Invalid number format.");
                }

                catch (const std::out_of_range& e) 
                {
                    outputLog.push_back("Error: Number out of range.");
                }
            }
        }
    }

    void setDamage(std::string arg)
    {
        for (const auto& gameObject : gameObjects)
        {
            if (!gameObject)
            {
                continue;
            }
            if (Player* p = dynamic_cast<Player*>(gameObject.get()))
            {
                try 
                {
                    float n = std::stof(arg);

                    p->setDamage(n);
                    outputLog.push_back("Damage is set to " + arg);


                }
                catch (const std::invalid_argument& e) 
                {
                    outputLog.push_back("Error: Invalid number format.");
                }

                catch (const std::out_of_range& e) 
                {
                    outputLog.push_back("Error: Number out of range.");
                }
            }
        }
    }

    void setCriticalHitChance(std::string arg)
    {
        for (const auto& gameObject : gameObjects)
        {
            if (!gameObject)
            {
                continue;
            }
            if (Player* p = dynamic_cast<Player*>(gameObject.get()))
            {
                try 
                {
                    float n = std::stof(arg);
    
                    p->setCriticalHitChance(n);
                    outputLog.push_back("Critical chance is set to " + arg);

                }
                catch (const std::invalid_argument& e) 
                {
                    outputLog.push_back("Error: Invalid number format.");
                }

                catch (const std::out_of_range& e) 
                {
                    outputLog.push_back("Error: Number out of range.");
                }
            }
        }
    }

    void setCriticalDamageCoefficient(std::string arg)
    {
        for (const auto& gameObject : gameObjects)
        {
            if (!gameObject)
            {
                continue;
            }
            if (Player* p = dynamic_cast<Player*>(gameObject.get()))
            {
                try 
                {
                    float n = std::stof(arg);
    
                    p->setCriticalHitChance(n);
                    outputLog.push_back("Critical damage coefficient is set to " + arg);

                }
                catch (const std::invalid_argument& e) 
                {
                    outputLog.push_back("Error: Invalid number format.");
                }

                catch (const std::out_of_range& e) 
                {
                    outputLog.push_back("Error: Number out of range.");
                }
            }
        }
    }

    void setBulletPenetration(std::string arg)
    {
        for (const auto& gameObject : gameObjects)
        {
            if (!gameObject)
            {
                continue;
            }
            if (Player* p = dynamic_cast<Player*>(gameObject.get()))
            {
                try 
                {
                    bool pen;
                    if (arg == "1" || arg == "true")
                    {
                        pen = true;
                    }
                    else if (arg == "0" || arg == "false")
                    {
                        pen = false;
                    }
                    else
                    {
                        outputLog.push_back("Enter true or false");
                    }

    
                    p->setBulletPenetration(pen);
                    outputLog.push_back("Bullet penetration is set to " + arg);

                }
                catch (const std::invalid_argument& e) 
                {
                    outputLog.push_back("Error: Invalid bool format.");
                }
            }
        }
    }

    void setBulletVelocity(std::string arg)
    {
        for (const auto& gameObject : gameObjects)
        {
            if (!gameObject)
            {
                continue;
            }
            if (Player* p = dynamic_cast<Player*>(gameObject.get()))
            {
                try 
                {
                    float n = std::stof(arg);
    
                    p->setBulletVelocity(n);
                    outputLog.push_back("Bullet velocity is set to " + arg);

                }
                catch (const std::invalid_argument& e) 
                {
                    outputLog.push_back("Error: Invalid number format.");
                }

                catch (const std::out_of_range& e) 
                {
                    outputLog.push_back("Error: Number out of range.");
                }
            }
        }
    }

    void setBulletRange(std::string arg)
    {
        for (const auto& gameObject : gameObjects)
        {
            if (!gameObject)
            {
                continue;
            }
            if (Player* p = dynamic_cast<Player*>(gameObject.get()))
            {
                try 
                {
                    float n = std::stof(arg);
    
                    p->setBulletRange(n);
                    outputLog.push_back("Bullet range is set to " + arg);

                }
                catch (const std::invalid_argument& e) 
                {
                    outputLog.push_back("Error: Invalid number format.");
                }

                catch (const std::out_of_range& e) 
                {
                    outputLog.push_back("Error: Number out of range.");
                }
            }
        }
    }

    void setShotCooldown(std::string arg)
    {
        for (const auto& gameObject : gameObjects)
        {
            if (!gameObject)
            {
                continue;
            }
            if (Player* p = dynamic_cast<Player*>(gameObject.get()))
            {
                try 
                {
                    float n = std::stof(arg);
    
                    p->setShotCooldown(n);
                    outputLog.push_back("Shot cooldown is set to " + arg);

                }
                catch (const std::invalid_argument& e) 
                {
                    outputLog.push_back("Error: Invalid number format.");
                }

                catch (const std::out_of_range& e) 
                {
                    outputLog.push_back("Error: Number out of range.");
                }
            }
        }
    }

    void kill(std::string arg)
    {
        for (const auto& gameObject : gameObjects)
        {
            if (!gameObject)
            {
                continue;
            }
            if (Player* p = dynamic_cast<Player*>(gameObject.get()))
            {
                p->death();

                outputLog.push_back("Player is killed.");
            }
        }
    }


};