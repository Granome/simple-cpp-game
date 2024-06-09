#include "Booster.hpp"

Booster::Booster(std::function<void()> ability, int rarity, std::string name, std::string description)
{
    ability_ = ability;
    rariry_ = rarity;
    name_ = name;
    description_ = description;
}

int Booster::getRarity()
{
    return rariry_;
}

void Booster::setHighlited(bool highlited_)
{
    highlited = highlited_;
}
void Booster::setShown(bool shown_)
{
    shown = shown_;
}

bool Booster::isHighlited()
{
    return highlited;
}

bool Booster::isShown()
{
    return shown;
}



InfoBox::InfoBox(sf::Vector2f postion)
{
    name.setFont(font);
    name.setCharacterSize(25);

    description.setFont(font);
    description.setCharacterSize(15);
    description.setFillColor(sf::Color(0x1E0051));

    bg.setPosition(postion);
    bg.setScale(1.5, 1.5);
    positionTexts();

}

void InfoBox::positionTexts()
{
    name.setCharacterSize(20);
    name.setOutlineThickness(3);
    description.setCharacterSize(15);


    sf::FloatRect bgBounds = bg.getGlobalBounds();

    // Get the global bounds of the name text
    sf::FloatRect nameBounds = name.getGlobalBounds();

    // Calculate the position to centralize the name text horizontally and vertically
    float namePosX = bgBounds.left + (bgBounds.width - nameBounds.width) / 2;

    // Set the position of the name text
    name.setPosition(namePosX, bgBounds.top+5);



    sf::FloatRect descriptionBounds = description.getGlobalBounds();
    // Calculate the position to centralize the description text horizontally and vertically
    float descriptionPosX = bgBounds.left + (bgBounds.width - descriptionBounds.width) / 2;
    float descriptionPosY = name.getGlobalBounds().top+name.getGlobalBounds().height + 10;

    description.setPosition(descriptionPosX, descriptionPosY);
}

void InfoBox::setBgTexture(sf::Texture& tx)
{
    bg.setTexture(tx);
}

void InfoBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(bg);
    target.draw(name);
    target.draw(description);
}

void InfoBox::setTextColorFromRarity(int rarity)
{
    switch (rarity)
    {
    case 1:
        name.setFillColor(sf::Color(9, 255, 0));
        name.setOutlineColor(sf::Color(50, 168, 82));
        break;
    case 2:
        name.setFillColor(sf::Color(0, 102, 255));
        name.setOutlineColor(sf::Color(0, 32, 81));
        break;
    case 3:
        name.setFillColor(sf::Color(255, 179, 0));
        name.setOutlineColor(sf::Color(245, 0, 122));
        break;
    case 4:
        name.setFillColor(sf::Color(44, 0, 94));
        name.setOutlineColor(sf::Color(255, 28, 28));
        break;
    
    default:
        break;
    }
}