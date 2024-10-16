// ================================================
// mouseEvent.h
// Created by Yaowei Lei on 2021/4/5.
// ================================================

#ifndef SFML_PROJECTS_MOUSEEVENT_H
#define SFML_PROJECTS_MOUSEEVENT_H

#include <SFML/Graphics.hpp>
#include <iostream>

#define WIDTH 10
#define HEIGHT 50


template <class T>
class MouseEvents {
public:
    // returns true if the mouse clicks on the object
    static bool mouseClicked(const T& object, sf::RenderWindow& window);

    // returns true if the mouse clicks anywhere in the window
    static bool mouseClicked( sf::RenderWindow& window, sf::Event event);

    // returns true if the mouse has been double clicked
    static bool mouseDoubleClicked();

    //returns true if the mouse has been triple clicked
    static bool mouseTripleClicked();

    // returns if the object has been clicked and the mouse has dragged over the object
    static bool draggedOver(T& object, sf::RenderWindow& window, sf::Event event);

    // returns tru if the mouse is hovered over the object
    static bool hovered(const T& object, sf::RenderWindow& window);

private:
    // this is what I used to determine if a double click or triple click occurred
    // you don't have to use this if you don't want to
    static sf::Clock clock;
    static int clicks;
    static void countClicks(sf::Event event);
};

#include "mouseEvent.cpp"

#endif //SFML_PROJECTS_MOUSEEVENT_H
