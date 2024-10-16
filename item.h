// ================================================
// item.h
// Created by Yaowei Lei on 2021/4/26.
// ================================================

#ifndef DROPDOWNMENU_ITEM_H
#define DROPDOWNMENU_ITEM_H

#include "typingBox.h"
#include <iostream>

class Item : public sf::Drawable {
private:
    TypingBox box;
    sf::Text itemText;

public:
    Item();
    Item(sf::Color, int, sf::Font&, std::string);
    void setItemScale(float, float);
    void setPosition(sf::Vector2f);
    void setText(std::string);
    void setTextColor(sf::Color);
    void setText(sf::Color color, int size, sf::Font& font, std::string text);
    void setTextOrigin(sf::Vector2f);
    void setBoxOrigin(sf::Vector2f);
    void setBox(float, float, float, sf::Color);
    void setBoxColor(sf::Color, sf::Color);
    const TypingBox &getBox() const;
    const sf::Text &getText() const;
    void draw(sf::RenderTarget&, sf::RenderStates) const;
    void drawBox(sf::RenderTarget&, sf::RenderStates) const;
};

#endif //DROPDOWNMENU_ITEM_H
