// ================================================
// menuBar.h
// Created by Yaowei Lei on 2021/5/3.
// ================================================

#ifndef MENUBAR_MENUBAR_H
#define MENUBAR_MENUBAR_H

#include "menu.h"

class MenuBar : public sf::Drawable {
private:
    std::vector<Menu> menuList;

public:
    MenuBar(sf::Color, int, sf::Font&, std::string, float, float);
    void setTextColor(sf::Color);
    void addItem(std::string, std::string);
    void addMenu(sf::Color, int, sf::Font&, std::string, float, float);
    const Menu &getMenu(std::string) const;
    const sf::Text &getMenuItem(std::string, std::string) const;
    const sf::RectangleShape &getMenuItemBox(std::string, std::string) const;
    bool clickedMenuItem(std::string, std::string, sf::RenderWindow&);
    void setScale(float, float);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setPosition(sf::Vector2f position);
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};

#endif //MENUBAR_MENUBAR_H
