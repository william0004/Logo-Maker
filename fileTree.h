// ================================================
// fileTree.h
// Created by Yaowei Lei on 2021/5/10.
// ================================================

#ifndef FILETREE_FILETREE_H
#define FILETREE_FILETREE_H

#include "GUIComponent.h"
#include "fileNode.h"

class FileTree : public GUIComponent<FileItem> {
private:
    std::string fileName;

    //the root node of the tree
    FileNode* root = nullptr;

    //finds the parent and add the item to the parent.
    // If the parent isn't found, a new parent is created
    bool push(FileNode*& root, Image::image ICON, std::string parent, std::string item);

    //traverses the tree ad adds the evenhandlers for each of the nodes
    void traverse(FileNode* &root, sf::RenderWindow& window, sf::Event event);

    void changeTreeColor(FileNode* &root, sf::Color textColor, sf::Color highlight);

    bool selected(FileNode* &root);

    sf::Vector2f initPosition = {30, 20};

public:
    //constructors
    FileTree();
    explicit FileTree(sf::Font& font);

    void changeTreeColor(sf::Color textColor, sf::Color highlight);

    void changeTreeName(std::string name);

    const std::string& getSelectedItemText() const;

    bool selected();

    //this is the public version of push
    void push(Image::image ICON, std::string parent, std::string item);

    //draws the root node of the tree
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //does nothing now
    virtual void applySnapshot(const Snapshot<FileItem>& snapshot);

    //calls the traverse function to add the event handlers to each node
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);

    //does nothing now
    virtual void update();
    //does nothing now
    virtual Snapshot<FileItem>& getSnapshot();
    //does nothing now
    virtual sf::FloatRect getGlobalBounds();
};

#endif //FILETREE_FILETREE_H
