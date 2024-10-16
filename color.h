// ================================================
// color.h
// Created by Yaowei Lei on 2021/5/24.
// ================================================

#ifndef LOGOMAKER_COLOR_H
#define LOGOMAKER_COLOR_H

#include <SFML/Graphics.hpp>

class Color {
public:
    enum color {
         CURSOR, OUTLINE, BACKGROUND, HIGHLIGHT, COVER, FONT, TYPING, SLIDER, BLOCKER
    };
    enum privateColor {
        SUN, GREEN, RED, ORANGE, WHITE, BLUE, GRAY, BLACK, PINK, DARKGRAY, DEFAULT
    };
    static sf::Color& getPrivateColor(privateColor color);
    static sf::Color& getColor(color color);
    static void changeColor(color color, privateColor privateColor);

private:

    static std::map<color, sf::Color*> colors;
    static std::map<privateColor, sf::Color> privateColors;
    static std::map<color, bool> loaded;
    static std::map<privateColor, bool> loadedPrivate;
    static void loadColor(color color);
    static void loadPrivateColor(privateColor color);


};

#endif //LOGOMAKER_COLOR_H
