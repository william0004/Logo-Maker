// ================================================
// theme.cpp
// Created by Yaowei Lei on 2021/6/7.
// ================================================

#include "theme.h"

void Theme::applyTheme(Theme::theme theme) {
    if(theme == DARK) {
        //topCover, buttonCover, menuBar, font, slider, sliderBlocker, outline, highlight, background
        Color::changeColor(Color::COVER, Color::BLACK);
        Color::changeColor(Color::FONT, Color::DEFAULT);
        Color::changeColor(Color::SLIDER, Color::DEFAULT);
        Color::changeColor(Color::BLOCKER, Color::BLUE);
        Color::changeColor(Color::OUTLINE, Color::GRAY);
        Color::changeColor(Color::HIGHLIGHT, Color::BLUE);
        Color::changeColor(Color::BACKGROUND, Color::DARKGRAY);
        Color::changeColor(Color::CURSOR, Color::BLUE);
        Color::changeColor(Color::TYPING, Color::DEFAULT);
    }
    if(theme == LIGHT) {
        Color::changeColor(Color::COVER, Color::WHITE);
        Color::changeColor(Color::FONT, Color::DARKGRAY);
        Color::changeColor(Color::SLIDER, Color::GRAY);
        Color::changeColor(Color::BLOCKER, Color::GREEN);
        Color::changeColor(Color::OUTLINE, Color::GRAY);
        Color::changeColor(Color::HIGHLIGHT, Color::GREEN);
        Color::changeColor(Color::BACKGROUND, Color::SUN);
        Color::changeColor(Color::CURSOR, Color::GREEN);
        Color::changeColor(Color::TYPING, Color::WHITE);
    }
    if(theme == DUSK) {
        Color::changeColor(Color::COVER, Color::DARKGRAY);
        Color::changeColor(Color::FONT, Color::PINK);
        Color::changeColor(Color::SLIDER, Color::ORANGE);
        Color::changeColor(Color::BLOCKER, Color::PINK);
        Color::changeColor(Color::OUTLINE, Color::ORANGE);
        Color::changeColor(Color::HIGHLIGHT, Color::ORANGE);
        Color::changeColor(Color::BACKGROUND, Color::DARKGRAY);
        Color::changeColor(Color::CURSOR, Color::ORANGE);
        Color::changeColor(Color::TYPING, Color::RED);
    }
}
