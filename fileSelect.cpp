// ================================================
// fileSelect.cpp
// Created by Yaowei Lei on 2021/5/26.
// ================================================

#include "fileSelect.h"

FileSelect::FileSelect() { }

FileSelect::FileSelect(sf::Font& font) : fileTree(font),
                                         openButton(Color::getColor(Color::FONT), 24, font, "Apply"),
                                         closeButton(Color::getColor(Color::FONT), 24, font, "Cancel")
                                         {
    openButton.setBox(90, 35, 2, Color::getColor(Color::OUTLINE));
    closeButton.setBox(90, 35, 2, Color::getColor(Color::OUTLINE));
    openButton.setBoxColor(Color::getColor(Color::HIGHLIGHT), Color::getColor(Color::OUTLINE));
    closeButton.setBoxColor(Color::getColor(Color::HIGHLIGHT), Color::getColor(Color::OUTLINE));
    openButton.setPosition({580, 450});
    closeButton.setPosition({700, 450});
}

void FileSelect::push(Image::image ICON, std::string parent, std::string item) {
    fileTree.push(ICON, parent, item);
}

void FileSelect::createWindow(std::string windowName) {
    sf::RenderWindow newWindow(sf::VideoMode(800, 500), "Select File");
    newWindow.setTitle(windowName);
    newWindow.setFramerateLimit(120);
    newWindow.setPosition({800, 400});

    while(newWindow.isOpen()) {
        sf::Event newEvent;
        while(newWindow.pollEvent(newEvent)) {
            if(newEvent.type == sf::Event::Closed) {
                newWindow.close();
            }
            getAnswer(newWindow, newEvent);
            fileTree.addEventHandler(newWindow, newEvent);
            addEventHandler(newWindow, newEvent);
        }

        newWindow.clear(Color::getColor(Color::COVER));
        newWindow.draw(fileTree);
        draw(newWindow, sf::RenderStates::Default);
        drawButton(newWindow,sf::RenderStates::Default);
        newWindow.display();
    }
}

void FileSelect::getAnswer(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents<sf::RectangleShape>::mouseClicked(openButton.getBox().getBox(), window)) {
        applyTarget = true;
        window.close();
    }
    if(event.type == sf::Event::Closed) {
        applyTarget = false;
    }
    if(MouseEvents<sf::RectangleShape>::mouseClicked(closeButton.getBox().getBox(), window)) {
        applyTarget = false;
        window.close();
    }
    if(fileTree.selected()) {
        selectedItem = fileTree.getSelectedItemText();
    }
}

void FileSelect::drawButton(sf::RenderWindow &window, sf::RenderStates states) {
    if(MouseEvents<sf::RectangleShape>::hovered(openButton.getBox().getBox(), window)) {
        openButton.drawBox(window, states);
    }
    if(MouseEvents<sf::RectangleShape>::hovered(closeButton.getBox().getBox(), window)) {
        closeButton.drawBox(window, states);
    }
    window.draw(openButton);
    window.draw(closeButton);
}

bool FileSelect::checkApplyTarget() {
    return applyTarget;
}

void FileSelect::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

const std::string &FileSelect::getSelectedItem() const {
    return selectedItem;
}

void FileSelect::draw(sf::RenderTarget &window, sf::RenderStates states) const {

}

void FileSelect::changeTreeName(std::string name) {
    fileTree.changeTreeName(name);

}

void FileSelect::update() {
    openButton.setBoxColor(Color::getColor(Color::HIGHLIGHT), Color::getColor(Color::OUTLINE));
    closeButton.setBoxColor(Color::getColor(Color::HIGHLIGHT), Color::getColor(Color::OUTLINE));
    openButton.setTextColor(Color::getColor(Color::FONT));
    closeButton.setTextColor(Color::getColor(Color::FONT));
    fileTree.changeTreeColor(Color::getColor(Color::FONT), Color::getColor(Color::HIGHLIGHT));
}





