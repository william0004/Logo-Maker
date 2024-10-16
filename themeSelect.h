// ================================================
// themeSelect.h
// Created by Yaowei Lei on 2021/6/6.
// ================================================

#ifndef LOGOMAKER_THEMESELECT_H
#define LOGOMAKER_THEMESELECT_H

#include "fileSelect.h"
#include "theme.h"

class ThemeSelect : public FileSelect {
private:
    std::map<std::string, sf::Sprite> preview;

public:
    ThemeSelect(sf::Font& font);
    void pushTheme(Image::image ICON, std::string parent, std::string item, Image::image THEME);
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

};

#endif //LOGOMAKER_THEMESELECT_H
