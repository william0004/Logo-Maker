// ================================================
// item.cpp.c
// Created by Yaowei Lei on 2021/4/26.
// ================================================

#include "item.h"


Item::Item() { }

Item::Item(sf::Color color, int size, sf::Font& font, std::string text) {
    itemText.setFillColor(color);
    itemText.setCharacterSize(size);
    itemText.setFont(font);
    itemText.setString(text);
    itemText.setOrigin(itemText.getGlobalBounds().width/2, 0);
}

void Item::setItemScale(float x, float y) {
    box.setScale(x, y);
    itemText.setScale(x, y);
}

void Item::setPosition(sf::Vector2f position) {
    box.setPosition(position);
    itemText.setPosition(position);
}

void Item::setText(std::string text) {
    itemText.setString(text);
    //itemText.setOrigin(itemText.getGlobalBounds().width/2, 0);
}

void Item::setText(sf::Color color, int size, sf::Font& font, std::string text) {
    itemText.setFillColor(color);
    itemText.setCharacterSize(size);
    itemText.setFont(font);
    itemText.setString(text);
}

void Item::setBox(float w, float h, float t, sf::Color color) {
    box.setBox(w, h, t, color);
    box.setOrigin({box.getBox().getGlobalBounds().width / 2, 0});
}

void Item::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    //box.draw(window, states);
    window.draw(itemText);
}

void Item::drawBox(sf::RenderTarget& window, sf::RenderStates states) const {
    box.draw(window, states);
}

const sf::Text &Item::getText() const {
    return itemText;
}

const TypingBox &Item::getBox() const {
    return box;
}

void Item::setBoxColor(sf::Color color, sf::Color outlineColor) {
    box.setColor(color, outlineColor);
}

void Item::setTextOrigin(sf::Vector2f position) {
    itemText.setOrigin(position);
}

void Item::setBoxOrigin(sf::Vector2f position) {
    box.setOrigin(position);
}

void Item::setTextColor(sf::Color color) {
    itemText.setFillColor(color);
}
