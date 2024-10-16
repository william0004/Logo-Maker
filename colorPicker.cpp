// ================================================
// colorPicker.cpp
// Created by Yaowei Lei on 2021/5/24.
// ================================================

#include "colorPicker.h"

ColorPicker::ColorPicker() {
    enableState(HIDDEN);
}

ColorPicker::ColorPicker(sf::Vector2f boxSize, float t, sf::Vector2f size, sf::Vector2f bgSize, int defaultValue) : red(Font::getFont(Font::OPENSANS),"R:", size.x, 255),
                                                                                              green(Font::getFont(Font::OPENSANS),"G:", size.x, 255),
                                                                                              blue(Font::getFont(Font::OPENSANS),"B:", size.x, 255) {
    enableState(HIDDEN);
    item.setBox(boxSize.x, boxSize.y, t, Color::getColor(Color::SLIDER));

    setTrackSize(size);

    setDefaultValue(defaultValue);

    red.setTexture(&Image::getImage(Image::RED));
    green.setTexture(&Image::getImage(Image::GREEN));
    blue.setTexture(&Image::getImage(Image::BLUE));

    background.setSize(bgSize);
    background.setOutlineThickness(2);
    background.setOutlineColor(Color::getColor(Color::OUTLINE));
    background.setFillColor(Color::getColor(Color::BACKGROUND));
}

void ColorPicker::rePosition(sf::Vector2f position, float boundary) {
    background.setPosition(position.x, position.y + item.getBox().getBox().getGlobalBounds().height);
    red.setPosition({position.x - 150, background.getPosition().y + 20});
    green.setPosition({position.x - 150, red.getTrack().getPosition().y + red.getTrack().getSize().y + 20});
    blue.setPosition({position.x - 150, green.getTrack().getPosition().y + green.getTrack().getSize().y + 20});

    red.rePlaceLabel({position.x + 20, red.getLabel().getPosition().y + 10});
    green.rePlaceLabel({position.x + 20, green.getLabel().getPosition().y + 10});
    blue.rePlaceLabel({position.x + 20, blue.getLabel().getPosition().y + 10});

    if(background.getSize().x + background.getPosition().x + 30 > boundary) {
        rePosition({position.x - 10, position.y}, boundary);
    }
}

void ColorPicker::setBoxColor() {
    item.setBoxColor(getColor(), Color::getColor(Color::OUTLINE));
}

void ColorPicker::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    item.drawBox(window, states);
    if(!checkState(HIDDEN)) {
        window.draw(background);
        red.draw(window, states);
        green.draw(window, states);
        blue.draw(window, states);
    }
}

void ColorPicker::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents<sf::RectangleShape>::mouseClicked(item.getBox().getBox(), window)) {
        if (checkState(HIDDEN)) {
            disableState(HIDDEN);
        }
        else {
            enableState(HIDDEN);
        }
    }
    else if (event.type == sf::Event::MouseButtonPressed && !MouseEvents<sf::RectangleShape>::mouseClicked(background, window)) {
        if (!checkState(HIDDEN)) {
            enableState(HIDDEN);
        }
    }

    if(!red.checkState(UNLOCK) && !green.checkState(UNLOCK) && !blue.checkState(UNLOCK)) {
        if(MouseEvents<sf::CircleShape>::mouseClicked(red.getBlocker(), window)) {
            red.enableState(UNLOCK);
        }
        else if(MouseEvents<sf::CircleShape>::mouseClicked(green.getBlocker(), window)) {
            green.enableState(UNLOCK);
        }
        else if(MouseEvents<sf::CircleShape>::mouseClicked(blue.getBlocker(), window)) {
            blue.enableState(UNLOCK);
        }
    }

    if(!checkState(HIDDEN)) {
        red.addEventHandler(window, event);
        green.addEventHandler(window, event);
        blue.addEventHandler(window, event);
    }
    setBoxColor();
}

void ColorPicker::update() {
    background.setFillColor(Color::getColor(Color::BACKGROUND));
    background.setOutlineColor(Color::getColor(Color::OUTLINE));
    red.update();
    green.update();
    blue.update();
}

void ColorPicker::setPosition(sf::Vector2f position) {
    item.setPosition(position);
}

Snapshot<Slider> &ColorPicker::getSnapshot() {

}

void ColorPicker::applySnapshot(const Snapshot<Slider> &snapshot) {

}

sf::Color ColorPicker::getColor() {
    sf::Color temp;
    temp.r = red.getValue();
    temp.g = green.getValue();
    temp.b = blue.getValue();
    return temp;
}

void ColorPicker::setDefaultValue(int defaultValue) {
    red.setValue(defaultValue);
    green.setValue(defaultValue);
    blue.setValue(defaultValue);
}

void ColorPicker::setTrackSize(sf::Vector2f size) {
    red.setTrackSize(size);
    green.setTrackSize(size);
    blue.setTrackSize(size);
}

void ColorPicker::setDefaultValue(int r, int g, int b) {
    red.setValue(r);
    green.setValue(g);
    blue.setValue(b);
}

int ColorPicker::getRedValue() {
    return red.getValue();
}

int ColorPicker::getGreenValue() {
    return green.getValue();
}

int ColorPicker::getBlueValue() {
    return blue.getValue();
}

