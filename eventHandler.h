// ================================================
// eventHandler.h
// Created by Yaowei Lei on 2021/4/5.
// ================================================

#ifndef SFML_PROJECTS_EVENTHANDLER_H
#define SFML_PROJECTS_EVENTHANDLER_H

#include <SFML/Graphics.hpp>

class EventHandler {
public:
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;
};


#endif //SFML_PROJECTS_EVENTHANDLER_H
