// ================================================
// fileTree.cpp
// Created by Yaowei Lei on 2021/5/10.
// ================================================

#include "fileTree.h"

bool FileTree::push(FileNode *&root, Image::image ICON, std::string parent, std::string item) {
    for(FileNode::iterator iter = root->begin(); iter != root->end(); iter++) {
        if(iter->first == parent) {
            FileNode* newItem = new FileNode(ICON, item);
            iter->second->getChildren()[item] = newItem;
            return true;
        }
        if(push(iter->second, ICON, parent, item)) {
            return true;
        }
    }
    return false;
}

void FileTree::traverse(FileNode *&root, sf::RenderWindow &window, sf::Event event) {
    for(FileNode::iterator iter = root->begin(); iter != root->end(); iter++) {
        iter->second->addEventHandler(window, event);
        traverse(iter->second, window, event);
    }
}

FileTree::FileTree() {

}

bool FileTree::selected(FileNode *&root) {
    if(root->getData().getClickedState()) {
        fileName = root->getData().getText().getString();
        return true;
    }
    if(!root->isLeaf()) {
        for(FileNode::iterator iter = root->begin(); iter != root->end(); iter++) {
            if(selected(iter->second)) {
                return true;
            }
        }
    }
    return false;
}

bool FileTree::selected() {
    return selected(root);
}


FileTree::FileTree(sf::Font &font) {
    FileNode* newItem = new FileNode(Image::DIRECTORIES, "Directories", {0.04,0.04}, initPosition);
    root = newItem;
    root->enableState(TOGGLE);
}


void FileTree::push(Image::image ICON, std::string parent, std::string item) {
    if(!push(root, ICON, parent, item)) {
        FileNode* newItem = new FileNode(ICON, item);
        FileTree::root->getChildren()[item] = newItem;
    }
}

void FileTree::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(*root);
}

void FileTree::applySnapshot(const Snapshot<FileItem> &snapshot) {

}

void FileTree::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    root->addEventHandler(window, event);
    traverse(root, window, event);
}

void FileTree::update() {

}

Snapshot<FileItem> &FileTree::getSnapshot() {

}

sf::FloatRect FileTree::getGlobalBounds() {

}

const std::string &FileTree::getSelectedItemText() const {
    return fileName;
}

void FileTree::changeTreeName(std::string name) {
    if(root != nullptr) {
        root->setDateText(name);
    }
}

void FileTree::changeTreeColor(FileNode *&root, sf::Color textColor, sf::Color highlight) {
    root->changeNodeColor(textColor, highlight, sf::Color::Transparent);
    if(!root->isLeaf()) {
        for(FileNode::iterator iter = root->begin(); iter != root->end(); iter++) {
            changeTreeColor(iter->second, textColor, highlight);
        }
    }
}

void FileTree::changeTreeColor(sf::Color textColor, sf::Color highlight) {
    changeTreeColor(root, textColor, highlight);
}

