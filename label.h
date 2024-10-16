// ================================================
// label.h
// Created by Yaowei Lei on 2021/4/8.
// ================================================

#ifndef SFML_PROJECTS_LABEL_H
#define SFML_PROJECTS_LABEL_H

#include <SFML/Graphics.hpp>

class Label : public sf::Drawable {
private:
    sf::Text text;

public:
    Label();
    Label(sf::Font& font);
    void setPosition(sf::Vector2f);
    void setColor(sf::Color);
    void setText(std::string, sf::Color, int, sf::Font&);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    sf::Text& getText();
};

#endif //SFML_PROJECTS_LABEL_H
