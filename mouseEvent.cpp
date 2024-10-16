// ================================================
// mouseEvent.cpp.c
// Created by Yaowei Lei on 2021/4/5.
// ================================================

#ifndef SFML_PROJECTS_MOUSEEVENT_CPP
#define SFML_PROJECTS_MOUSEEVENT_CPP

#include "mouseEvent.h"

template <class T>
int MouseEvents<T>::clicks = 0;

template <class T>
sf::Clock MouseEvents<T>::clock;

template <class T>
bool MouseEvents<T>::mouseClicked(const T &object, sf::RenderWindow &window) {
    if (hovered(object, window)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            return true;
        }
    }
    return false;
}

template <class T>
bool MouseEvents<T>::mouseClicked(sf::RenderWindow &window, sf::Event event) {
    sf::Vector2u size = window.getSize();
    float width = size.x;
    float height = size.y;

    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    if (mousePosition.x > 0 && mousePosition.x < width && mousePosition.y > 0 && mousePosition.y < height) {
        if (event.type == sf::Event::MouseMoved) {
            std::cout << "{" << mousePosition.x << " , " << mousePosition.y << "}" << std::endl;
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                return true;
            }
        }
    }
    return false;
}

template <class T>
bool MouseEvents<T>::mouseDoubleClicked() {
    if (clicks == 2) {
        clicks = 0;
        return true;
    }
    return false;
}

template <class T>
bool MouseEvents<T>::mouseTripleClicked() {
    if (clicks == 3) {
        clicks = 0;
        return true;
    }
    return false;
}

template <class T>
bool MouseEvents<T>::draggedOver(T &object, sf::RenderWindow &window, sf::Event event) {
    if (hovered(object, window)) {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.type == sf::Event::MouseMoved) {
                return true;
            }
        }
        if (event.type == sf::Event::EventType::MouseButtonReleased) {
            return false;
        }
    }
    return false;
}

template <class T>
bool MouseEvents<T>::hovered(const T &object, sf::RenderWindow &window) {
    // Get the width and height of the object.
    float width = object.getGlobalBounds().width;
    float height = object.getGlobalBounds().height;
    float left = object.getGlobalBounds().left;
    float top = object.getGlobalBounds().top;

    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    if (mousePosition.x > left && mousePosition.x < width + left && mousePosition.y > top && mousePosition.y < top + height) {
        return true;
    }
    return false;
}

template <class T>
void MouseEvents<T>::countClicks(sf::Event event) {
    clicks = 0;
    if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        sf::Time t1 = clock.restart();
        if (event.type == sf::Event::MouseButtonReleased) {
            if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
                if (event.type == sf::Event::MouseButtonReleased) {
                    t1 = clock.getElapsedTime();
                    if (t1.asSeconds() < 0.8) {
                        clicks = 2;
                    }
                    sf::Time t2 = clock.restart();
                    if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                        if (event.type == sf::Event::MouseButtonReleased) {
                            t2 = clock.getElapsedTime();
                            if (t2.asSeconds() < 0.4) {
                                clicks = 3;
                            }
                        }
                    }
                }
            }
        }
    }
}

#endif //SFML_PROJECTS_MOUSEEVENT_CPP