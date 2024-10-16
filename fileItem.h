// ================================================
// fileItem.h
// Created by Yaowei Lei on 2021/5/10.
// ================================================

#ifndef FILETREE_FILEITEM_H
#define FILETREE_FILEITEM_H

#include "Color.h"
#include "item.h"
#include "image.h"
#include "states.h"
#include "mouseEvent.h"

class FileItem : public Item {
public:
    //Constructors
    FileItem();
    FileItem(Image::image icon, std::string text, sf::Font& font, sf::Vector2f size, sf::Vector2f position);

    //GUIComponent pure virtual functions, refer to the TextInput Project for Info
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    //I use this function to highlight the item when clicked, and unhighlight when something
    //else is clicked
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    //Returns the bounds of the item
    sf::FloatRect getGlobalBounds() const;
    //returns the size of the item
    sf::Vector2f getSize() const;
    //returns the position of the item
    sf::Vector2f getPosition() const;
    //sets the position of the item
    void setPosition(sf::Vector2f position);
    //uses an enum to change the icon to a folder or file
    void setIcon(Image::image icon);

    void setIconScale(sf::Vector2f size);

    bool getClickedState() const;

private:
    //this is the folder or file icon
    sf::Sprite icon;
    bool clicked = false;

};

#endif //FILETREE_FILEITEM_H
