// ================================================
// themeSelect.cpp
// Created by Yaowei Lei on 2021/6/6.
// ================================================

#include "themeSelect.h"

ThemeSelect::ThemeSelect(sf::Font& font) : FileSelect(font) {
    changeTreeName("Themes");
}

void ThemeSelect::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void ThemeSelect::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for(auto iter : preview) {
        if(iter.first == getSelectedItem()) {
            window.draw(iter.second);
        }
    }
}

void ThemeSelect::pushTheme(Image::image ICON, std::string parent, std::string item, Image::image THEME) {
    FileSelect::push(ICON, parent, item);
    sf::Sprite sprite;
    sprite.setTexture(Image::getImage(THEME));
    sprite.setScale(0.3,0.3);
    sprite.setPosition(320,40);
    preview[item] = sprite;
}
