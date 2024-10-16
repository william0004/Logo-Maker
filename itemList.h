// ================================================
// itemList.h
// Created by Yaowei Lei on 2021/4/26.
// ================================================

#ifndef DROPDOWNMENU_ITEMLIST_H
#define DROPDOWNMENU_ITEMLIST_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "mouseEvent.h"
#include "font.h"
#include "color.h"

class ItemList : public sf::Drawable {
private:
    std::vector<sf::Text> list;
    std::vector<sf::RectangleShape> background;

public:
    ItemList();
    void setListScale(float, float);
    void setTextColor(sf::Color);
    static sf::RectangleShape addShape(float, float);
    void addItem(std::string, int, float, float);
    const sf::Text& getItem(std::string) const;
    const sf::RectangleShape& getBackgroung(std::string) const;
    void setPosition(sf::Vector2f);
    std::vector<sf::Text>& getList();
    std::vector<sf::RectangleShape>& getBackground();
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void draw(sf::RenderTarget&, sf::RenderStates) const;
    void update();
};

#endif //DROPDOWNMENU_ITEMLIST_H
