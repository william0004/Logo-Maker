// ================================================
// history.h
// Created by Yaowei Lei on 2021/4/5.
// ================================================

#ifndef SFML_PROJECTS_HISTORY_H
#define SFML_PROJECTS_HISTORY_H

#include "snapshotInterface.h"
#include "keyboardShortcut.h"
#include "GUIComponent.h"
#include <stack>

template <class T>
class History  {
private:
    static std::stack<Snapshot<T>> stack;
    static std::map<std::string, GUIComponent<T>*> components;
public:
    struct Response{
        bool found = false;
        GUIComponent<T>* component;
    };
    static void pushHistory(const Snapshot<T>& snapshot);
    static Snapshot<T>& topHistory();
    static void popHistory();
    static void addEventHandler(sf::RenderWindow& window, sf::Event event);
    static Response& getComponent(const std::string& componentID);
    static void addComponent(const std::string& componentID, GUIComponent<T>* component);
};

#include "history.cpp"

#endif //SFML_PROJECTS_HISTORY_H
