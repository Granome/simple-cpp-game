#pragma once

#include "UiElement.hpp"
#include <iostream>




class Booster : public UiElement
{
private:
    int rariry_=0;

    bool highlited=false;
    bool shown = false;

    std::string name_="";
    std::string description_="";

public:
    Booster(std::function<void()> ability, int rarity, std::string name, std::string description);

    std::function<void()> ability_;

    int getRarity();

    void setHighlited(bool highlited_);
    void setShown(bool shown_);

    bool isHighlited();
    bool isShown();

    std::string getName(){return name_;}
    std::string getDescription(){return description_;}

    virtual ~Booster() {}


}; 



class InfoBox : public UiElement
{
private:
    sf::Sprite bg;
    sf::Text name;
    sf::Text description;
public:
    InfoBox(sf::Vector2f postion);
    void positionTexts();
    void setBgTexture(sf::Texture& tx);
    void setTextColorFromRarity(int rarity);
    //OVERRIDING DRAW FUNCTION, probably WAS NOT COVERED IN THE COURSE!
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void setName(std::string name_){name.setString(name_);}
    void setDescription(std::string description_){description.setString(description_);}

};
