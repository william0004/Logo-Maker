// ================================================
// typingBox.cpp.c
// Created by Yaowei Lei on 2021/4/8.
// ================================================

#include "typingBox.h"


TypingBox::TypingBox() {
    textBox.setFillColor(sf::Color::Transparent);
}

const sf::RectangleShape& TypingBox::getBox() const{
    return textBox;
}

void TypingBox::setBox(float w, float h, float t, sf::Color color) {
    textBox.setSize({w, h});
    textBox.setOutlineColor(color);
    textBox.setOutlineThickness(t);
}

void TypingBox::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(textBox);
}

sf::Vector2f TypingBox::getPoint(std::size_t index) const {
    /*
    switch (index){
      case 0:
          ...
         break;
      case 1:
          ...
         break;
      case 2:
          ...
         break;
      case 3:
          ...
         break;
      default:
    }
     */
}

std::size_t TypingBox::getPointCount() const {
    return 4;
}

void TypingBox::setPosition(sf::Vector2f position) {
    textBox.setPosition(position);
}

void TypingBox::setColor(sf::Color color, sf::Color outlineColor) {
    textBox.setFillColor(color);
    textBox.setOutlineColor(outlineColor);
}

void TypingBox::setScale(float x, float y) {
    textBox.setScale(x, y);
}

void TypingBox::setOrigin(sf::Vector2f position) {
    textBox.setOrigin(position);
}
