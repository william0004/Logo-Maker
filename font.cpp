// ================================================
// font.cpp
// Created by Yaowei Lei on 2021/5/19.
// ================================================

#include "font.h"

std::map<Font::fonts, sf::Font> Font::fontList;
std::map<Font::fonts, bool> Font::loaded;

sf::Font &Font::getFont(Font::fonts font) {
    if(!loaded[font]) {
        loadFont(font);
    }
    return fontList[font];
}

sf::Font &Font::getFont(std::string font) {
    if(font == "CHILLER") {
        return getFont(CHILLER);
    }
    if(font == "DEVEBIC") {
        return getFont(DEVEBIC);
    }
    if(font == "JOKERMAN") {
        return getFont(JOKERMAN);
    }
    if(font == "ROLLERBO") {
        return getFont(ROLLERBO);
    }
    if(font == "OPENSANS") {
        return getFont(OPENSANS);
    }
    if(font == "SCRIPTBL") {
        return getFont(SCRIPTBL);
    }
    return getFont(OPENSANS);
}

void Font::loadFont(Font::fonts font) {
    if(!loaded[font]){
        if(!fontList[font].loadFromFile("../font/" + getFontPath(font) + ".ttf")) {
            exit(15);
        }
        loaded[font] = true;
    }
}

std::string Font::getFontPath(Font::fonts font) {
    if(font == fonts::CHILLER) {
        return "CHILLER";
    }
    if(font == fonts::DEVEBIC) {
        return "DEVEBIC";
    }
    if(font == fonts::JOKERMAN) {
        return "JOKERMAN";
    }
    if(font == fonts::OPENSANS) {
        return "OPENSANS";
    }
    if(font == fonts::ROLLERBO) {
        return "ROLLERBO";
    }
    if(font == fonts::SCRIPTBL) {
        return "SCRIPTBL";
    }
    if(font == fonts::DEFAULT) {
        return "OPENSANS";
    }
}

const std::map<Font::fonts, sf::Font> &Font::getFontList() {
    return fontList;
}
