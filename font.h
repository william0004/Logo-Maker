// ================================================
// font.h
// Created by Yaowei Lei on 2021/5/19.
// ================================================

#ifndef LOGOMAKER_FONT_H
#define LOGOMAKER_FONT_H

#include <SFML/Graphics.hpp>

class Font{
public:
    enum fonts {
        CHILLER, DEVEBIC, JOKERMAN, OPENSANS, ROLLERBO, SCRIPTBL, DEFAULT
    };
    static void loadFont(fonts font);
    static sf::Font& getFont(fonts font);
    static sf::Font& getFont(std::string);
    static std::string getFontPath(fonts font);
    static const std::map<Font::fonts, sf::Font> &getFontList();

private:
    static std::map<Font::fonts, sf::Font> fontList;
    static std::map<fonts, bool> loaded;
};

#endif //LOGOMAKER_FONT_H
