// ================================================
// dropdownMenu.h
// Created by Yaowei Lei on 2021/4/26.
// ================================================

#ifndef DROPDOWNMENU_DROPDOWNMENU_H
#define DROPDOWNMENU_DROPDOWNMENU_H

#include "GUIComponent.h"
#include "item.h"
#include "itemList.h"
#include "history.h"

class DropdownMenu : public GUIComponent<Item> {
private:
    Item item;
    ItemList itemList;
    States state;
    std::string ID;

public:
    DropdownMenu(sf::Color, int, sf::Font&, std::string, float, float);
    void setMenuScale(float, float);
    void setBox(float, float, float, sf::Color);
    void setItemText(std::string);
    void addItem(std::string);
    void setPosition(sf::Vector2f position);
    const Item &getItem() const;
//from the sf::Drawable class
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
// from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
//from SnapshotInterface
    Snapshot<Item>& getSnapshot();
    void applySnapshot(const Snapshot<Item>& snapshot);
};


#endif //DROPDOWNMENU_DROPDOWNMENU_H
