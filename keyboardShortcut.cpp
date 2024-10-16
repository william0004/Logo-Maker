// ================================================
// keyboardShortcut.cpp.c
// Created by Yaowei Lei on 2021/4/5.
// ================================================

#include "keyboardShortcut.h"

bool KeyboardShortcut::isUndo() {
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) &&
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RControl) &&
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
        return true;
    }
    return false;
}