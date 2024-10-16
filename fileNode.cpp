// ================================================
// fileNode.cpp
// Created by Yaowei Lei on 2021/5/10.
// ================================================

#include "fileNode.h"


void FileNode::toggleChlidren() {
    if(data.getClickedState() && !isLeaf() && !children.begin()->second->checkState(TOGGLE)) {
        for(iterator iter = begin(); iter != end(); iter++) {
            iter->second->enableState(TOGGLE);
            std::cout << iter->first << " enable" << std::endl;
        }
    }

    else if(data.getClickedState() && !isLeaf() && children.begin()->second->checkState(TOGGLE)) {
        for(iterator iter = begin(); iter != end(); iter++) {
            iter->second->disableState(TOGGLE);
            std::cout << iter->first << " disable" << std::endl;
        }
    }
}

void FileNode::reposition() const{
    if(!isLeaf()){
        std::map<std::string, FileNode*>::const_iterator iter;
        for(iter = children.begin(); iter != children.end(); iter++) {
            if(iter == children.begin()) {
                iter->second->data.setPosition(
                        {data.getPosition().x + 40,
                         data.getPosition().y + data.getGlobalBounds().height});
            }
            else {
                auto iter2 = iter;
                --iter2;
                iter->second->data.setPosition(
                        {data.getPosition().x + 40,
                         iter2->second->data.getPosition().y + iter2->second->getHeight()});
            }
            iter->second->reposition();
        }
    }

}


FileNode::FileNode() {
}

FileNode::FileNode(Image::image ICON, std::string text) {
    FileItem item;
    item.setIcon(ICON);
    item.setText(Color::getColor(Color::FONT), 26, Font::getFont(Font::OPENSANS), text);
    item.setBox(250, 34, 0, Color::getColor(Color::OUTLINE));
    item.setBoxColor(Color::getColor(Color::HIGHLIGHT), sf::Color::Transparent);
    item.setIconScale({0.04,0.04});
    item.setPosition({0,0});
    item.setBoxOrigin({item.getBox().getBox().getSize().x / 4, 0});
    setData(item);
}

FileNode::FileNode(Image::image icon, std::string text,sf::Vector2f size, sf::Vector2f position) : data(icon, text, Font::getFont(Font::OPENSANS) , size, position) {

}


void FileNode::draw(sf::RenderTarget &window, sf::RenderStates states) const{
    reposition();
    if(checkState(TOGGLE)) {
        data.draw(window,states);
        for(auto const &iter : children) {
            iter.second->FileNode::draw(window, states);
        }
    }
}

void FileNode::applySnapshot(const Snapshot<FileItem> &snapshot) {

}

void FileNode::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    data.addEventHandler(window, event);
    if(event.type == sf::Event::MouseButtonPressed) {
        toggleChlidren();
    }
}

void FileNode::update() {

}

Snapshot<FileItem> &FileNode::getSnapshot() {

}

sf::FloatRect FileNode::getGlobalBounds() {

}


float FileNode::getHeight() const {
    float temp = data.getGlobalBounds().height;
    if(isLeaf() || !children.begin()->second->checkState(TOGGLE)){
        return temp;
    }
    else {
        for(auto const &iter : children) {
            temp += iter.second->getHeight();
        }
        return temp;
    }
}


bool FileNode::isLeaf() const {
    if (children.empty()) {
        return true;
    }
    return false;
}

FileItem &FileNode::getData() {
    return data;
}

void FileNode::setData(const FileItem &data) {
    FileNode::data = data;
}

std::map<std::string, FileNode *> &FileNode::getChildren() {
    return children;
}

FileNode::iterator FileNode::begin() {
    return children.begin();
}

FileNode::iterator FileNode::end(){
    return children.end();
}

void FileNode::setDateText(std::string name) {
    data.setText(name);
}

void FileNode::changeNodeColor(sf::Color textColor, sf::Color highlight, sf::Color outline) {
    data.setTextColor(textColor);
    data.setBoxColor(highlight, outline);
}
