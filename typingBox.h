// ================================================
// typingBox.h
// Created by Yaowei Lei on 2021/4/8.
// ================================================

#ifndef SFML_PROJECTS_TYPINGBOX_H
#define SFML_PROJECTS_TYPINGBOX_H

#include <SFML/Graphics.hpp>

class TypingBox : public sf::Shape {
private:
    sf::RectangleShape textBox;

public:
    TypingBox();
    const sf::RectangleShape& getBox() const;
    void setBox(float, float, float, sf::Color);
    void setScale(float, float);
    void setOrigin(sf::Vector2f);
    void setColor(sf::Color, sf::Color);
    sf::Vector2f getPoint(std::size_t index) const;
    std::size_t getPointCount() const;
    void setPosition(sf::Vector2f position);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};

#endif //SFML_PROJECTS_TYPINGBOX_H
