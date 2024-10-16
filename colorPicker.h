// ================================================
// colorPicker.h
// Created by Yaowei Lei on 2021/5/24.
// ================================================

#ifndef LOGOMAKER_COLORPICKER_H
#define LOGOMAKER_COLORPICKER_H

#include "GUIComponent.h"
#include "item.h"
#include "slider.h"
#include "color.h"
#include "font.h"
#include "image.h"

class ColorPicker : public GUIComponent<Slider> {
private:
    Item item;
    sf::RectangleShape background;
    Slider red;
    Slider green;
    Slider blue;

public:
    ColorPicker();
    ColorPicker(sf::Vector2f , float, sf::Vector2f, sf::Vector2f, int);
    void setDefaultValue(int);
    void setDefaultValue(int, int, int);
    int getRedValue();
    int getGreenValue();
    int getBlueValue();
    void setTrackSize(sf::Vector2f);
    void rePosition(sf::Vector2f position, float boundary);
    void setBoxColor();
    void setPosition(sf::Vector2f);
    sf::Color getColor();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    Snapshot<Slider>& getSnapshot();
    void applySnapshot(const Snapshot<Slider>& snapshot);
};

#endif //LOGOMAKER_COLORPICKER_H
