// ================================================
// menuBar.cpp.c
// Created by Yaowei Lei on 2021/5/3.
// ================================================

#include "menuBar.h"

MenuBar::MenuBar(sf::Color color, int size, sf::Font& font, std::string id, float w, float h) {
    Menu temp(color, size, font, id, w, h);
    menuList.push_back(temp);
}

void MenuBar::addMenu(sf::Color color, int size, sf::Font& font, std::string id, float w, float h) {
    Menu temp(color, size, font, id, w, h);
    temp.setPosition({menuList.back().getItem().getText().getPosition().x + menuList.back().getItem().getBox().getBox().getGlobalBounds().width,
                      menuList.back().getItem().getText().getPosition().y});
    menuList.push_back(temp);
}


void MenuBar::setScale(float x, float y) {
    auto iter = menuList.begin();
    for(; iter != menuList.end(); iter++) {
        iter->setScale(x, y);
    }
    for (int i = 1; i < menuList.size(); i++) {
        menuList[i].setPosition({menuList[i-1].getItem().getText().getPosition().x + menuList[i-1].getItem().getBox().getBox().getGlobalBounds().width,
                                 menuList[i-1].getItem().getText().getPosition().y});
    }
}


void MenuBar::addItem(std::string item, std::string id) {
    auto iter = menuList.begin();
    for(; iter != menuList.end(); iter++) {
        if (iter->getID() == id) {
            iter->addItem(item);
        }
    }
}

void MenuBar::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for (int i = 0; i < menuList.size(); i++) {
        window.draw(menuList[i]);
    }
}

void MenuBar::setPosition(sf::Vector2f position) {
    menuList.front().setPosition(position);
}

void MenuBar::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    for (int i = 0; i < menuList.size(); i++) {
        menuList[i].addEventHandler(window, event);
    }
}

void MenuBar::update() {
    for (int i = 0; i < menuList.size(); i++) {
        menuList[i].update();
    }
}

const Menu &MenuBar::getMenu(std::string menu) const {
    for(std::vector<Menu>::const_iterator iter = menuList.begin(); iter != menuList.end(); iter++) {
        if(iter->getItem().getText().getString() == menu) {
            return *iter;
        }
    }
}

const sf::Text &MenuBar::getMenuItem(std::string menu, std::string item) const {
    return getMenu(menu).getListItem(item);
}

const sf::RectangleShape &MenuBar::getMenuItemBox(std::string menu, std::string item) const {
    return getMenu(menu).getListBox(item);
}

bool MenuBar::clickedMenuItem(std::string menu, std::string item, sf::RenderWindow &window) {
    if(!getMenu(menu).checkState(HIDDEN) && MouseEvents<sf::RectangleShape>::mouseClicked(getMenuItemBox(menu, item), window)) {
        return true;
    }
    return false;
}

void MenuBar::setTextColor(sf::Color color) {
    for (int i = 0; i < menuList.size(); i++) {
        menuList[i].setTextColor(color);
    }
}



