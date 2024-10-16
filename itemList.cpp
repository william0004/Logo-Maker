// ================================================
// itemList.cpp.c
// Created by Yaowei Lei on 2021/4/26.
// ================================================

#include "itemList.h"

ItemList::ItemList() {

}

void ItemList::setListScale(float x, float y) {
    for (int i = 0; i < list.size(); i ++) {
        background[i].setScale(x, y);
        list[i].setScale(x, y);
    }
}

sf::RectangleShape ItemList::addShape(float w, float h) {
    sf::RectangleShape shape;
    shape.setSize({w, h});
    shape.setOutlineThickness(2);
    shape.setOutlineColor(Color::getColor(Color::OUTLINE));
    shape.setFillColor(Color::getColor(Color::BACKGROUND));
    shape.setOrigin(shape.getGlobalBounds().width/2, 0);
    return shape;
}

void ItemList::addItem(std::string text, int size, float w, float h) {
    sf::Text temp;
    temp.setFont(Font::getFont(Font::OPENSANS));
    temp.setString(text);
    temp.setCharacterSize(size);
    temp.setOrigin(temp.getGlobalBounds().width/2 , 0);
    temp.setFillColor(Color::getColor(Color::FONT));
    temp.setPosition(list.back().getPosition().x ,
                     background.back().getPosition().y + h);
    list.push_back(temp);

    sf::RectangleShape shape = addShape(w, h);
    shape.setPosition(background.back().getPosition().x , background.back().getPosition().y + h);
    background.push_back(shape);
}

void ItemList::setPosition(sf::Vector2f position) {
    for (int i = 0; i < list.size(); i++) {
        if(i == 0) {
            list[i].setPosition(position);
            background[i].setPosition(position);
        }
        else {
            list[i].setPosition(position.x ,list[i-1].getPosition().y + background[i-1].getGlobalBounds().height);
            background[i].setPosition(position.x , background[i-1].getPosition().y + background[i-1].getGlobalBounds().height);
        }
    }
}

std::vector<sf::Text>& ItemList::getList() {
    return list;
}

std::vector<sf::RectangleShape>& ItemList::getBackground() {
    return background;
}

void ItemList::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    for(int i = 1; i < background.size(); i++) {
        window.draw(background[i]);
    }
    for(int i = 1; i < list.size(); i++) {
        window.draw(list[i]);
    }
}

void ItemList::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    for(int i = 1; i < background.size(); i++) {
        background[i].setOutlineColor(Color::getColor(Color::OUTLINE));
        if (MouseEvents<sf::RectangleShape>::hovered(background[i], window)) {
            background[i].setFillColor(Color::getColor(Color::HIGHLIGHT));
        }
        else {
            background[i].setFillColor(Color::getColor(Color::BACKGROUND));
        }
    }
}

const sf::Text &ItemList::getItem(std::string item) const {
    for(std::vector<sf::Text>::const_iterator iter = list.begin(); iter != list.end(); iter++) {
        if(iter->getString() == item) {
            return *iter;
        }
    }
}

const sf::RectangleShape &ItemList::getBackgroung(std::string item) const {
    for(int i = 0; i < list.size(); i++) {
        if(list[i].getString() == item) {
            return background[i];
        }
    }
}

void ItemList::setTextColor(sf::Color color) {
    for(int i = 0; i < list.size(); i++) {
        list[i].setFillColor(color);
    }
}

void ItemList::update() {

}
