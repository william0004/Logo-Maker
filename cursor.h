// ================================================
// cursor.h
// Created by Yaowei Lei on 2021/4/8.
// ================================================

#ifndef SFML_PROJECTS_CURSOR_H
#define SFML_PROJECTS_CURSOR_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Cursor : public sf::Drawable {
private:
    sf::RectangleShape cursor;
    sf::Clock clock;
    const sf::Time time;
    bool blinking;

public:
    Cursor(sf::Time blinkSpeed, sf::Color color, float x, float y);
    sf::RectangleShape& getCursor();
    void setPosition(sf::Vector2f position);
    void setCursorColor(sf::Color);
    void blink();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};

#endif //PROJECT1_CURSOR_H
