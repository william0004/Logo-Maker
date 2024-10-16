// ================================================
// textInput.h
// Created by Yaowei Lei on 2021/4/5.
// ================================================

#ifndef SFML_PROJECTS_TEXTINPUT_H
#define SFML_PROJECTS_TEXTINPUT_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "GUIComponent.h"
#include "typing.h"
#include "typingBox.h"
#include "cursor.h"
#include "label.h"
#include "history.h"
#include "color.h"

class TextInput : public GUIComponent<sf::Text> {
private:
    sf::Text text;
    Typing message;
    States state;
    Label label;
    TypingBox box;
    Cursor cursor;
    std::string ID;

public:
    TextInput(sf::Font&, const std::string& tag);
    void setText(std::string);
    const sf::Text &getText() const;
    void setPosition(sf::Vector2f position);
    void setLabelPosition(sf::Vector2f position);
    void setLabelText(std::string, sf::Color, int, sf::Font&);
    void setTypingBox(float w, float h, float t, sf::Color color);
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    Snapshot<sf::Text>& getSnapshot();
    void applySnapshot(const Snapshot<sf::Text>& snapshot);
};


#endif //SFML_PROJECTS_TEXTINPUT_H
