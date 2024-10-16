// ================================================
// typing.h
// Created by Yaowei Lei on 2021/4/8.
// ================================================

#ifndef SFML_PROJECTS_TYPING_H
#define SFML_PROJECTS_TYPING_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "keyboardShortcut.h"
#include "mouseEvent.h"

class Typing {
private:
    std::string msg;

public:
    std::string getMessage();
    void setMessage(sf::RenderWindow&, sf::Event);
    void setMessage(const std::string&);
};


#endif //SFML_PROJECTS_TYPING_H
