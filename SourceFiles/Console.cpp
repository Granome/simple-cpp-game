#include "Console.hpp"

void Console::executeCommand(const std::string& input) 
{

    size_t spacePos = input.find(' ');

    std::string command;
    std::string args;

    if (spacePos == std::string::npos) 
    {
        command = input;
        args = "";
    } 
    else 
    {
        command = input.substr(0, spacePos);
        args = input.substr(spacePos + 1);
    }

    auto it = commands.find(command);

    if (it != commands.end()) 
    {
        it->second(args);
    }
    
    else 
    {
        outputLog.push_back("Unknown command: " + command);
    }

    outputLog.push_back("> " + input);
}

Console::Console(float x, float y, float width, float height, std::vector<std::unique_ptr<sf::Drawable>>& gameObjects_)
        : position(x, y), size(width, height), inputString(""), isOpen(false), gameObjects(gameObjects_)
{

    background.setSize(sf::Vector2f(width, height));
    background.setFillColor(sf::Color(0, 0, 0, 150));
    background.setPosition(x, y);

    inputText.setFont(font);
    inputText.setCharacterSize(20);
    inputText.setFillColor(sf::Color::White);
    inputText.setPosition(x + 5, y + height - 30);

    outputText.setFont(font);
    outputText.setCharacterSize(20);
    outputText.setFillColor(sf::Color::White);
    outputText.setPosition(x + 5, y + 5);



    //Command registration
    registerCommand("setSpeed", [&](const std::string args) {setSpeed(args);});
    registerCommand("setMaxHP", [&](const std::string args) {setMaxHP(args);});
    registerCommand("setHP", [&](const std::string args) {setHP(args);});
    registerCommand("setAttackSpeed", [&](const std::string args) {setAttackSpeed(args);});
    registerCommand("setDamage", [&](const std::string args) {setDamage(args);});
    registerCommand("setCriticalHitChance", [&](const std::string args) {setCriticalHitChance(args);});
    registerCommand("setCriticalDamageCoefficient", [&](const std::string args) {setCriticalDamageCoefficient(args);});
    registerCommand("setBulletPenetration", [&](const std::string args) {setBulletPenetration(args);});
    registerCommand("setBulletVelocity", [&](const std::string args) {setBulletVelocity(args);});
    registerCommand("setBulletRange", [&](const std::string args) {setBulletRange(args);});
    registerCommand("setShotCooldown", [&](const std::string args) {setShotCooldown(args);});
    registerCommand("kill", [&](const std::string args) {kill(args);});
}

void Console::registerCommand(const std::string& command, std::function<void(const std::string&)> func) 
{
    commands[command] = func;
}

void Console::handleEvent(const sf::Event& event) 
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Tilde) 
    {
        isOpen = !isOpen;
        if (isOpen) 
        {
            inputString.clear(); // Clear the input to avoid backtick character
        }
    }

    if (isOpen) 
    {
            if (event.type == sf::Event::TextEntered) 
            {
                if (event.text.unicode == 8) // Handle backspace
                { 
                    if (!inputString.empty()) 
                    {
                        inputString.pop_back();
                    }
                } 
                else if (event.text.unicode == 13 || event.text.unicode == 10) // Handle enter
                { 
                    executeCommand(inputString);
                    inputString.clear();
                } 
                else if (event.text.unicode != '`') // Ignore the backtick character, that opens console
                { 
                    inputString += static_cast<char>(event.text.unicode);
                }
            }
        }
}


void Console::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (isOpen) 
    {
        target.draw(background);
        target.draw(inputText);

        sf::Text tempOutput = outputText;
        float lineHeight = tempOutput.getCharacterSize() + 5;
        float maxHeight = background.getSize().y - 35; // Maximum height for log display

        float currentHeight = background.getPosition().y + 5;
        int linesToShow = static_cast<int>(maxHeight / lineHeight);

        int start = std::max(0, static_cast<int>(outputLog.size()) - linesToShow);

        for (int i = start; i < outputLog.size(); ++i) 
        {
            tempOutput.setString(outputLog[i]);
            tempOutput.setPosition(background.getPosition().x + 5, currentHeight);
            target.draw(tempOutput);

            currentHeight += lineHeight;
        }
    }
}
    


void Console::update() 
{
    if (isOpen) 
    {
        inputText.setString("> " + inputString);
    }
}

bool Console::getIsOpen()
{
    return isOpen;
}