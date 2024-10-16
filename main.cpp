// ================================================
// main.cpp.c
// Created by Yaowei Lei on 2021/4/26.
// ================================================

#include "logoMaker.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1500, 1000), "LOGO MAKER");
    window.setFramerateLimit(120);

    LogoMaker item1(Font::getFont(Font::OPENSANS));


    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
            item1.addEventHandler(window, event);
            //History<sf::Text>::addEventHandler(window, event);
        }
        item1.update();
        window.clear(sf::Color::Black);
        window.draw(item1);
        window.display();
    }
}