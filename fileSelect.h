// ================================================
// fileSelect.h
// Created by Yaowei Lei on 2021/5/26.
// ================================================

#ifndef LOGOMAKER_FILESELECT_H
#define LOGOMAKER_FILESELECT_H

#include "item.h"
#include "font.h"
#include "fileTree.h"
#include "mouseEvent.h"

class FileSelect {
private:
    FileTree fileTree;
    Item openButton;
    Item closeButton;
    bool applyTarget = false;
    std::string selectedItem;

public:
    FileSelect();
    explicit FileSelect(sf::Font&);
    void changeTreeName(std::string);
    void push(Image::image ICON, std::string parent, std::string item);
    void createWindow(std::string);
    void getAnswer(sf::RenderWindow& window, sf::Event event);
    const std::string &getSelectedItem() const;
    bool checkApplyTarget();
    void drawButton(sf::RenderWindow& window, sf::RenderStates states);
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update();
};

#endif //LOGOMAKER_FILESELECT_H
