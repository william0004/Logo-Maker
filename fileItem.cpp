// ================================================
// fileItem.cpp
// Created by Yaowei Lei on 2021/5/10.
// ================================================

#include "fileItem.h"

FileItem::FileItem() { }

FileItem::FileItem(Image::image ICON, std::string text, sf::Font& font, sf::Vector2f size, sf::Vector2f position) {
    setIcon(ICON);
    setText(Color::getColor(Color::FONT), 26, font, text);
    setBox(250, 34, 0, Color::getColor(Color::OUTLINE));
    setBoxColor(Color::getColor(Color::HIGHLIGHT), sf::Color::Transparent);
    icon.setScale(size);
    FileItem::setPosition(position);
    setBoxOrigin({getBox().getBox().getSize().x / 4, 0});
}

void FileItem::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if(clicked) {
        drawBox(window, states);
    }
    Item::draw(window, states);
    window.draw(icon);
}

void FileItem::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents<sf::RectangleShape>::mouseClicked(getBox().getBox(), window)) {
        clicked = true;
    }
    if (event.type == sf::Event::MouseButtonPressed && !MouseEvents<sf::RectangleShape>::mouseClicked(getBox().getBox(), window)) {
        clicked = false;
    }
}

sf::FloatRect FileItem::getGlobalBounds() const {
    sf::FloatRect temp(getPosition(), getSize());
    return temp;
}

sf::Vector2f FileItem::getSize() const {
    sf::Vector2f size(getBox().getBox().getGlobalBounds().width, getBox().getBox().getGlobalBounds().height);
    return size;
}

sf::Vector2f FileItem::getPosition() const {
    return icon.getPosition();
}

void FileItem::setPosition(sf::Vector2f position) {
    icon.setPosition(position);
    Item::setPosition({position.x + icon.getGlobalBounds().width + 20, position.y - 5});
}

void FileItem::setIcon(Image::image ICON) {
    icon.setTexture(Image::getImage(ICON));
}

bool FileItem::getClickedState() const {
    return clicked;
}

void FileItem::setIconScale(sf::Vector2f size) {
    icon.setScale(size);
}


