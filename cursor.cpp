// ================================================
// cursor.cpp.c
// Created by Yaowei Lei on 2021/4/8.
// ================================================

#include "cursor.h"

Cursor::Cursor(sf::Time blinkSpeed, sf::Color color, float x, float y) : time(blinkSpeed), blinking(true) {
    cursor.setSize({x, y});
    cursor.setFillColor(color);
}

sf::RectangleShape& Cursor::getCursor() {
    return cursor;
}

void Cursor::setPosition(sf::Vector2f position) {
    cursor.setPosition(position);
}

void Cursor::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (blinking) {
        window.draw(cursor, states);
    }
}

void Cursor::blink() {
    if (clock.getElapsedTime() >= time) {
        blinking = !blinking;
        clock.restart();
    }
}

void Cursor::setCursorColor(sf::Color color) {
    cursor.setFillColor(color);
}
