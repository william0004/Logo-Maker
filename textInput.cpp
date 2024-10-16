// ================================================
// textInput.cpp.c
// Created by Yaowei Lei on 2021/4/5.
// ================================================

#include "textInput.h"

TextInput::TextInput(sf::Font& font, const std::string& tag) : ID(tag), cursor(sf::milliseconds(500), Color::getColor(Color::CURSOR), 4, 35) {
    text.setFont(font);
    text.setFillColor(Color::getColor(Color::TYPING));
    text.setCharacterSize(32);
    label.setText(tag, Color::getColor(Color::FONT), 32, font);
    History<sf::Text>::addComponent(ID, this);
}

void TextInput::setPosition(sf::Vector2f position) {
    text.setPosition(position);
    label.setPosition({text.getPosition().x - 270, text.getPosition().y});
    box.setPosition({text.getPosition().x - 5, text.getPosition().y});
    cursor.setPosition({text.getPosition().x, text.getPosition().y + 6});
}

void TextInput::addEventHandler(sf::RenderWindow& window, sf::Event event) {
    if (event.type == sf::Event::EventType::TextEntered && !KeyboardShortcut::isUndo() && checkState(ENABLED)) {
        message.setMessage(window, event);
        History<sf::Text>::pushHistory(getSnapshot());
        text.setString(message.getMessage());
    }
    else if (event.type == sf::Event::EventType::KeyPressed && KeyboardShortcut::isUndo()) {
        message.setMessage(text.getString());
    }
    if (event.type == sf::Event::EventType::MouseButtonPressed && MouseEvents<sf::RectangleShape>::mouseClicked(box.getBox(), window)) {
        enableState(ENABLED);
    }
    if (MouseEvents<sf::RectangleShape>::mouseClicked(window, event) && !MouseEvents<sf::RectangleShape>::mouseClicked(box.getBox(), window)) {
        disableState(ENABLED);
    }
}

void TextInput::update() {
    cursor.getCursor().setPosition(text.getGlobalBounds().width + text.getPosition().x + 5, text.getPosition().y + 6);
    cursor.blink();
    cursor.setCursorColor(Color::getColor(Color::CURSOR));
    text.setFillColor(Color::getColor(Color::TYPING));
    box.setColor(sf::Color::Black, Color::getColor(Color::SLIDER));
    label.setColor(Color::getColor(Color::FONT));
}


void TextInput::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    label.draw(window, states);
    box.draw(window, states);
    if (checkState(ENABLED)) {
        cursor.draw(window, states);
    }
    window.draw(text);
}

Snapshot<sf::Text>& TextInput::getSnapshot() {
    static Snapshot<sf::Text> temp;
    temp.setComponentId(ID);
    temp.setState(state);
    temp.setData(text);
    return temp;
}

void TextInput::applySnapshot(const Snapshot<sf::Text> &snapshot) {
    text = snapshot.getData();
    state = snapshot.getState();
}

void TextInput::setTypingBox(float w, float h, float t, sf::Color color) {
    box.setBox(w, h, t, color);
}

void TextInput::setLabelText(std::string text, sf::Color color, int size, sf::Font &font) {
    label.setText(text, color, size, font);
}

void TextInput::setLabelPosition(sf::Vector2f position) {
    label.setPosition(position);
}

const sf::Text &TextInput::getText() const {
    return text;
}

void TextInput::setText(std::string msg) {
    message.setMessage(msg);
    text.setString(msg);
}

