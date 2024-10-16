// ================================================
// history.cpp.c
// Created by Yaowei Lei on 2021/4/5.
// ================================================

#ifndef SFML_PROJECTS_HISTORY_CPP
#define SFML_PROJECTS_HISTORY_CPP

#include "history.h"

template <class T>
std::stack<Snapshot<T>> History<T>::stack;

template <class T>
std::map<std::string, GUIComponent<T>*> History<T>::components;

template <class T>
void History<T>::pushHistory(const Snapshot<T> &snapshot) {
    stack.push(snapshot);
    std::cout << "Snapshot saved;" << std::endl;
}

template <class T>
Snapshot<T>& History<T>::topHistory() {
    return stack.top();
}

template <class T>
void History<T>::popHistory() {
    stack.pop();
}

template <class T>
void History<T>::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (event.type == sf::Event::EventType::KeyPressed) {
        if (KeyboardShortcut::isUndo()) {
            if (!stack.empty()) {
                if (getComponent(topHistory().getComponentId()).found) {
                    getComponent(topHistory().getComponentId()).component->applySnapshot(topHistory());
                }
                popHistory();
            }
        }
    }
}

template <class T>
typename History<T>::Response& History<T>::getComponent(const std::string& componentID) {
    static Response temp;
    if (components.count(componentID) > 0) {
        temp.found = true;
        temp.component = components[componentID];
    }
    return temp;
}

template <class T>
void History<T>::addComponent(const std::string& componentID, GUIComponent<T> *component) {
    components[componentID] = component;
}

#endif //SFML_PROJECTS_HISTORY_CPP