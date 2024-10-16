// ================================================
// slider.h
// Created by Yaowei Lei on 2021/5/20.
// ================================================

#ifndef MENUBAR_SLIDER_H
#define MENUBAR_SLIDER_H

#include "GUIComponent.h"
#include "cstring"
#include "color.h"

class Slider : public GUIComponent<sf::CircleShape> {
private:
    sf::Text label;
    sf::Text valueDisplay;
    sf::CircleShape blocker;
    sf::RectangleShape track;
    int value = 0;
    int maxValue = 0;

public:
    Slider();
    Slider(sf::Font&, std::string, float, int);
    void moveBlocker(sf::RenderWindow&);
    void rePlaceLabel(sf::Vector2f);
    void rePlaceTrack(float);
    void setLabelText(std::string);
    void setTrackLength(float);
    void setTrackColor(sf::Color);
    void setTexture(const sf::Texture*);
    void setTrackSize(sf::Vector2f);
    void setPosition(sf::Vector2f);
    void setValue(int);
    void setValue();
    void setValueDisplay();
    void setMaxValue(int maxValue);
    int getValue() const;
    int getMaxValue() const;
    const sf::Text &getValueDisplay() const;
    const sf::Text &getLabel() const;
    const sf::CircleShape &getBlocker() const;
    const sf::RectangleShape &getTrack() const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void draw(sf::RenderTarget&, sf::RenderStates) const;
    void update();
    Snapshot<sf::CircleShape>& getSnapshot();
    void applySnapshot(const Snapshot<sf::CircleShape>& snapshot);

};

#endif //MENUBAR_SLIDER_H
