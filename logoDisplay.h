// ================================================
// logoDisplay.h
// Created by Yaowei Lei on 2021/5/24.
// ================================================

#ifndef LOGOMAKER_LOGODISPLAY_H
#define LOGOMAKER_LOGODISPLAY_H

#include <SFML/Graphics.hpp>
#include "font.h"
#include "color.h"

class LogoDisplay : sf::Drawable {
private:
    sf::Text logo;
    sf::Text shadow;
    sf::RectangleShape background;

public:
    LogoDisplay(sf::Vector2f);
    const sf::Text &getLogo() const;
    void setLogoString(std::string);
    void setLogoSize(int);
    void setLogoFont(sf::Font&);
    void setLogoPosition(sf::Vector2f);
    void setLogoColor(sf::Color);
    void setShadowColor(sf::Color);
    void setShadowPosition(sf::Vector2f);
    void setShadowSkew(float);

    const sf::Text &getShadow() const;
    void setShadow(const sf::Text &shadow);
    const sf::RectangleShape &getBackground() const;
    void setBackgroundColor(sf::Color);
    void setPosition(sf::Vector2f position);
    void draw(sf::RenderTarget&, sf::RenderStates) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};

#endif //LOGOMAKER_LOGODISPLAY_H
