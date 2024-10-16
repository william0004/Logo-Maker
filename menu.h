// ================================================
// menu.h
// Created by Yaowei Lei on 2021/5/3.
// ================================================

#ifndef MENUBAR_MENU_H
#define MENUBAR_MENU_H

#include "GUIComponent.h"
#include "item.h"
#include "itemList.h"
#include "history.h"

class Menu : public GUIComponent<Item> {
private:
    Item item;
    ItemList itemList;
    States state;
    std::string ID;

public:
    Menu(sf::Color, int, sf::Font&, std::string, float, float);
    void setTextColor(sf::Color);
    void setScale(float, float);
    void setBox(float, float, float, sf::Color);
    void addItem(std::string);
    void setPosition(sf::Vector2f position);
    const sf::Text& getListItem(std::string) const;
    const sf::RectangleShape& getListBox(std::string) const;
    const Item& getItem() const;
    std::string& getID();
//from the sf::Drawable class
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
// from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
//from SnapshotInterface
    Snapshot<Item>& getSnapshot();
    void applySnapshot(const Snapshot<Item>& snapshot);
};


#endif //MENUBAR_MENU_H
