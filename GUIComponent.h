// ================================================
// GUIComponent.h
// Created by Yaowei Lei on 2021/4/7.
// ================================================

#ifndef SFML_PROJECTS_GUICOMPONENT_H
#define SFML_PROJECTS_GUICOMPONENT_H

#include <SFML/Graphics.hpp>
#include "states.h"
#include "snapshotInterface.h"
#include "eventHandler.h"

#include "mouseEvent.h"
#include "keyboardShortcut.h"

template <class T>
class GUIComponent : public EventHandler, public States, public SnapshotInterface<T>, public sf::Drawable, public sf::Transformable {
public:
//from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;

// from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;

//from SnapshotInterface
    virtual Snapshot<T>& getSnapshot() = 0;
    virtual void applySnapshot(const Snapshot<T>& snapshot) = 0;
};

#endif //SFML_PROJECTS_GUICOMPONENT_H
