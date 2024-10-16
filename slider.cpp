// ================================================
// slider.cpp
// Created by Yaowei Lei on 2021/5/20.
// ================================================

#include "slider.h"

Slider::Slider() {

}

Slider::Slider(sf::Font& font, std::string text, float length, int max) : maxValue(max) {
    label.setString(text);
    label.setCharacterSize(24);
    label.setFont(font);
    label.setFillColor(Color::getColor(Color::FONT));

    valueDisplay.setCharacterSize(20);
    valueDisplay.setFont(font);
    valueDisplay.setFillColor(Color::getColor(Color::BLOCKER));
    valueDisplay.setString(std::to_string(maxValue));

    blocker.setRadius(8);
    blocker.setFillColor(Color::getColor(Color::BLOCKER));
    blocker.setOutlineThickness(1);
    blocker.setOutlineColor(Color::getColor(Color::BACKGROUND));
    track.setSize({length, 3});
    track.setFillColor(Color::getColor(Color::SLIDER));

    label.setOrigin(0, 18);
    blocker.setOrigin(0, blocker.getRadius());
    track.setOrigin(0, track.getSize().y/2);

}

void Slider::setLabelText(std::string text) {
    label.setString(text);
}

void Slider::setTrackLength(float length) {
    track.setSize({length, track.getSize().y});
}

void Slider::setTrackSize(sf::Vector2f size) {
    track.setSize(size);
}

void Slider::setTrackColor(sf::Color color) {
    track.setFillColor(color);
}

const sf::Text &Slider::getLabel() const {
    return label;
}

const sf::CircleShape &Slider::getBlocker() const {
    return blocker;
}

const sf::RectangleShape &Slider::getTrack() const {
    return track;
}

void Slider::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(valueDisplay);
    window.draw(label);
    window.draw(track);
    window.draw(blocker);
}

void Slider::setPosition(sf::Vector2f position) {
    label.setPosition(position);
    track.setPosition(position.x + 210, position.y);
    blocker.setPosition(position.x + 210 + track.getSize().x * value / maxValue - blocker.getRadius(), position.y);
    valueDisplay.setPosition(position.x + track.getGlobalBounds().width + 230, position.y - 12);
}

int Slider::getValue() const {
    return value;
}

void Slider::setValue(int value) {
    Slider::value = value;
    valueDisplay.setString(std::to_string(value));
    blocker.setPosition(track.getSize().x * value/ maxValue + track.getPosition().x - blocker.getRadius(), blocker.getPosition().y);
}

void Slider::setValue() {
    value = maxValue * (blocker.getPosition().x + blocker.getRadius() - track.getPosition().x) / track.getSize().x;
}

int Slider::getMaxValue() const {
    return maxValue;
}

void Slider::setMaxValue(int maxValue) {
    Slider::maxValue = maxValue;
}

void Slider::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents<sf::CircleShape>::mouseClicked(blocker, window)  && checkState(UNLOCK)) {
        enableState(MOVABLE);
    }
    if(event.type == sf::Event::MouseButtonReleased) {
        disableState(MOVABLE);
        disableState(UNLOCK);
    }
    if(checkState(MOVABLE)) {
        moveBlocker(window);
        setValue();
        setValueDisplay();
    }
}

void Slider::update() {
    label.setFillColor(Color::getColor(Color::FONT));
    valueDisplay.setFillColor(Color::getColor(Color::BLOCKER));
    blocker.setFillColor(Color::getColor(Color::BLOCKER));
    blocker.setOutlineColor(Color::getColor(Color::COVER));
}

Snapshot<sf::CircleShape> &Slider::getSnapshot() {

}

void Slider::applySnapshot(const Snapshot<sf::CircleShape> &snapshot) {

}

void Slider::moveBlocker(sf::RenderWindow &window) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    if(mousePosition.x >= track.getPosition().x && mousePosition.x <= track.getPosition().x + track.getSize().x) {
        blocker.setPosition(mousePosition.x - blocker.getRadius(), blocker.getPosition().y);
    }
}

void Slider::rePlaceLabel(sf::Vector2f position) {
    label.setPosition(position);
}

void Slider::rePlaceTrack(float move) {
    track.setPosition(track.getPosition().x + move, track.getPosition().y);
    blocker.setPosition(blocker.getPosition().x + move, blocker.getPosition().y);
    valueDisplay.setPosition(valueDisplay.getPosition().x + move, valueDisplay.getPosition().y);
}

const sf::Text &Slider::getValueDisplay() const {
    return valueDisplay;
}

void Slider::setValueDisplay() {
    valueDisplay.setString(std::to_string(value));
}

void Slider::setTexture(const sf::Texture* image) {
    track.setTexture(image);
}


