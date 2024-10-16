// ================================================
// dropdownMenu.cpp.c
// Created by Yaowei Lei on 2021/4/26.
// ================================================

#include "dropdownMenu.h"

DropdownMenu::DropdownMenu(sf::Color color, int size, sf::Font& font, std::string id, float w, float h) : item(color,size,font, id), ID(id) {
    enableState(HIDDEN);
    History<Item>::addComponent(ID, this);
    itemList.getList().push_back(item.getText());
    item.setBox(w, h, 2, color);
    sf::RectangleShape shape = ItemList::addShape(w, h);
    itemList.getBackground().push_back(shape);
}

void DropdownMenu::setMenuScale(float x, float y) {
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

void DropdownMenu::setBox(float w, float h, float t, sf::Color color) {
    item.setBox(w, h, t, color);
}


void DropdownMenu::setItemText(std::string text) {
    item.setText(text);
}

void DropdownMenu::addItem(std::string text) {
    itemList.addItem(text, item.getText().getCharacterSize(),
                     itemList.getBackground().back().getSize().x,
                     itemList.getBackground().back().getSize().y);
}

void DropdownMenu::setPosition(sf::Vector2f position) {
    item.setPosition(position);
    itemList.setPosition(position);
}

void DropdownMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    item.draw(window, states);
    item.drawBox(window, states);
    if (!checkState(HIDDEN)) {
        itemList.draw(window, states);
    }
}

void DropdownMenu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    itemList.addEventHandler(window, event);
    if (MouseEvents<sf::RectangleShape>::mouseClicked(window, event)) {
        if (MouseEvents<sf::RectangleShape>::mouseClicked(item.getBox().getBox(), window)) {
            if (checkState(HIDDEN)) {
                disableState(HIDDEN);
            }
            else {
                enableState(HIDDEN);
            }
        }
        else {
            for (int i = 0; i < itemList.getList().size(); i++) {
                if (MouseEvents<sf::RectangleShape>::mouseClicked(itemList.getBackground()[i], window) && !checkState(HIDDEN)) {
                    History<Item>::pushHistory(getSnapshot());
                    item.setText(itemList.getList()[i].getString());
                }
            }
            enableState(HIDDEN);
        }
    }
}

void DropdownMenu::update() {
    item.setTextOrigin({item.getText().getLocalBounds().width / 2, 0});
    item.setBoxColor(sf::Color::Transparent, Color::getColor(Color::OUTLINE));
    item.setTextColor(Color::getColor(Color::FONT));
    itemList.setTextColor(Color::getColor(Color::FONT));
}

Snapshot<Item> &DropdownMenu::getSnapshot() {
    static Snapshot<Item> temp;
    temp.setComponentId(ID);
    temp.setState(state);
    temp.setData(item);
    return temp;
}

void DropdownMenu::applySnapshot(const Snapshot<Item> &snapshot) {
    item = snapshot.getData();
    state = snapshot.getState();
}

const Item &DropdownMenu::getItem() const {
    return item;
}
