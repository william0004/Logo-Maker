// ================================================
// label.cpp.c
// Created by Yaowei Lei on 2021/4/8.
// ================================================

#include "label.h"

Label::Label() {}

Label::Label(sf::Font& font) {
    text.setFont(font);
}

void Label::setText(std::string msg, sf::Color color, int size, sf::Font& font) {
    text.setFont(font);
    text.setString(msg);
    text.setFillColor(color);
    text.setCharacterSize(size);
}

sf::Text& Label::getText() {
    return text;
}

void Label::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(text);
}

void Label::setPosition(sf::Vector2f position) {
    text.setPosition(position);
}

void Label::setColor(sf::Color color) {
    text.setFillColor(color);
}
