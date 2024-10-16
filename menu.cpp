// ================================================
// menu.cpp.c
// Created by Yaowei Lei on 2021/5/3.
// ================================================

#include "menu.h"

Menu::Menu(sf::Color color, int size, sf::Font& font, std::string id, float w, float h) : item(color,size,font, id), ID(id) {
    enableState(HIDDEN);
    History<Item>::addComponent(ID, this);
    itemList.getList().push_back(item.getText());
    item.setBox(150, h, 0, color);
    item.setBoxColor(Color::getColor(Color::HIGHLIGHT), sf::Color::Transparent);
    sf::RectangleShape shape = ItemList::addShape(w, h);
    itemList.getBackground().push_back(shape);
}

void Menu::setScale(float x, float y) {
    item.setItemScale(x, y);
    itemList.setListScale(x, y);
    itemList.setPosition(item.getText().getPosition());
    for(int i = 1; i < itemList.getList().size(); i++) {
        itemList.getBackground()[i].setPosition(item.getText().getPosition().x,
                                                itemList.getBackground()[i-1].getGlobalBounds().height + itemList.getBackground()[i-1].getPosition().y + 2);
        itemList.getList()[i].setPosition(item.getText().getPosition().x,
                                          itemList.getBackground()[i-1].getGlobalBounds().height + itemList.getBackground()[i-1].getPosition().y + 2);
    }
}

void Menu::setBox(float w, float h, float t, sf::Color color) {
    item.setBox(w, h, t, color);
}

void Menu::addItem(std::string text) {
    itemList.addItem(text, item.getText().getCharacterSize(),
                     itemList.getBackground().back().getSize().x,
                     itemList.getBackground().back().getSize().y);
}

void Menu::setPosition(sf::Vector2f position) {
    item.setPosition(position);
    itemList.setPosition(position);
}

const Item& Menu::getItem() const{
    return item;
}

std::string& Menu::getID() {
    return ID;
}

void Menu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (!checkState(HIDDEN)) {
        item.drawBox(window, states);
        window.draw(itemList);
    }
    window.draw(item);
}

void Menu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    itemList.addEventHandler(window, event);
    if (MouseEvents<sf::Text>::mouseClicked(window, event)) {
        if (MouseEvents<sf::Text>::mouseClicked(item.getText(), window)) {
            if (checkState(HIDDEN)) {
                disableState(HIDDEN);
            }
            else {
                enableState(HIDDEN);
            }
        }
        else {
            enableState(HIDDEN);
        }
    }
}

void Menu::update() {
    item.setBoxColor(Color::getColor(Color::HIGHLIGHT), sf::Color::Transparent);
    item.setTextColor(Color::getColor(Color::FONT));
    itemList.setTextColor(Color::getColor(Color::FONT));
}

Snapshot<Item> &Menu::getSnapshot() {

}

void Menu::applySnapshot(const Snapshot<Item> &snapshot) {

}

const sf::Text &Menu::getListItem(std::string item) const {
    return itemList.getItem(item);
}

const sf::RectangleShape &Menu::getListBox(std::string item) const {
    return itemList.getBackgroung(item);
}

void Menu::setTextColor(sf::Color color) {
    item.setTextColor(color);
    itemList.setTextColor(color);
}
