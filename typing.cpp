// ================================================
// typing.cpp.c
// Created by Yaowei Lei on 2021/4/8.
// ================================================

#include "typing.h"


std::string Typing::getMessage() {
    return msg;
}

void Typing::setMessage(sf::RenderWindow& window, sf::Event event) {
    if (event.type == sf::Event::EventType::TextEntered) {
        if (event.text.unicode == 8) {
            if (msg.length() > 0) {
                msg.pop_back();
            }
        }
        else {
            msg += static_cast<char>(event.text.unicode);
        }
        std::cout << "String: " << msg << std::endl;
    }
}

void Typing::setMessage(const std::string& m) {
    msg = m;
}