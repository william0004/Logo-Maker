// ================================================
// logoDisplay.cpp
// Created by Yaowei Lei on 2021/5/24.
// ================================================

#include "logoDisplay.h"


LogoDisplay::LogoDisplay(sf::Vector2f size) {
    background.setFillColor(Color::getColor(Color::BACKGROUND));
    background.setSize(size);
    background.setOutlineThickness(2);
    background.setOutlineColor(Color::getColor(Color::SLIDER));

}

const sf::Text &LogoDisplay::getLogo() const {
    return logo;
}

void LogoDisplay::setLogoString(std::string text) {
    logo.setString(text);
    shadow.setString(text);
}

void LogoDisplay::setLogoSize(int size) {
    logo.setCharacterSize(size);
    shadow.setCharacterSize(size);
}

void LogoDisplay::setLogoFont(sf::Font &font) {
    logo.setFont(font);
    shadow.setFont(font);
}

void LogoDisplay::setLogoPosition(sf::Vector2f position) {
    logo.setPosition(position);
}

void LogoDisplay::setLogoColor(sf::Color color) {
    logo.setFillColor(color);
}

void LogoDisplay::setShadowColor(sf::Color color) {
    shadow.setFillColor(color);
}

void LogoDisplay::setShadowPosition(sf::Vector2f position) {
    shadow.setPosition(position);
}

void LogoDisplay::setShadowSkew(float y) {
    shadow.setScale(shadow.getScale().x, -y);
}


const sf::Text &LogoDisplay::getShadow() const {
    return shadow;
}

void LogoDisplay::setShadow(const sf::Text &shadow) {
    LogoDisplay::shadow = shadow;
}

const sf::RectangleShape &LogoDisplay::getBackground() const {
    return background;
}

void LogoDisplay::setBackgroundColor(sf::Color color) {
    background.setFillColor(color);
}

void LogoDisplay::setPosition(sf::Vector2f position) {
    background.setPosition(position);
}

void LogoDisplay::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(background);
    window.draw(shadow);
    window.draw(logo);
}

void LogoDisplay::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void LogoDisplay::update() {
    background.setOutlineColor(Color::getColor(Color::OUTLINE));
}
