// ================================================
// color.cpp
// Created by Yaowei Lei on 2021/5/24.
// ================================================

#include "color.h"

std::map<Color::privateColor, sf::Color> Color::privateColors;
std::map<Color::color, sf::Color*> Color::colors;
std::map<Color::color, bool> Color::loaded;
std::map<Color::privateColor, bool> Color::loadedPrivate;

void Color::loadPrivateColor(Color::privateColor color) {
    if(!loadedPrivate[color]){
        sf::Color temp;
        if(color == privateColor::DEFAULT) {
            temp = sf::Color::White;
        }
        if(color == privateColor::WHITE) {
            temp.r = temp.g = temp.b = 230;
        }
        if(color == privateColor::SUN) {
            temp.r = temp.g = temp.b = 180;
        }
        if(color == privateColor::BLUE) {
            temp.r = 0;
            temp.g = 137;
            temp.b = 167;
        }
        if(color == privateColor::ORANGE) {
            temp.r = 196;
            temp.g = 98;
            temp.b = 67;
        }
        if(color == privateColor::RED) {
            temp.r = 219;
            temp.g = 77;
            temp.b = 109;
        }
        if(color == privateColor::GREEN) {
            temp.r = 0;
            temp.g = 137;
            temp.b = 108;
        }
        if(color == privateColor::GREEN) {
            temp.r = 0;
            temp.g = 137;
            temp.b = 108;
        }
        if(color == privateColor::PINK) {
            temp.r = 185;
            temp.g = 156;
            temp.b = 145;
        }
        if(color == privateColor::GRAY) {
            temp.r = temp.g = temp.b = 70;
        }
        if(color == privateColor::DARKGRAY) {
            temp.r = temp.g = temp.b = 30;
        }
        if(color == privateColor::BLACK) {
            temp = sf::Color::Black;
        }
        privateColors[color] = temp;
        loadedPrivate[color] = true;
    }
}

sf::Color &Color::getColor(Color::color color) {
    if(!loaded[color]) {
        loadColor(color);
    }
    return *colors[color];
}

void Color::loadColor(Color::color color) {
    if(!loaded[color]) {
        sf::Color* temp = new sf::Color;
        if(color == color::CURSOR || color == color::HIGHLIGHT || color == color::BLOCKER) {
            temp = &getPrivateColor(BLUE);
        }
        if(color == color::OUTLINE) {
            temp = &getPrivateColor(GRAY);
        }
        if(color == color::BACKGROUND) {
            temp = &getPrivateColor(DARKGRAY);
        }
        if(color == color::COVER) {
            temp = &getPrivateColor(BLACK);
        }
        if(color == color::FONT || color == color::TYPING || color == color::SLIDER) {
            temp = &getPrivateColor(DEFAULT);
        }
        colors[color] = temp;
        loaded[color] = true;
    }
}

sf::Color &Color::getPrivateColor(Color::privateColor color) {
    if(!loadedPrivate[color]){
        loadPrivateColor(color);
    }
    return privateColors[color];
}

void Color::changeColor(Color::color color, Color::privateColor privateColor) {
    colors[color] = &getPrivateColor(privateColor);
}
