// ================================================
// theme.h
// Created by Yaowei Lei on 2021/6/7.
// ================================================

#ifndef LOGOMAKER_THEME_H
#define LOGOMAKER_THEME_H

#include <SFML/Graphics.hpp>
#include "color.h"

class Theme {
public:
    enum theme {
        DARK, LIGHT, DUSK
    };
    static void applyTheme(theme theme);

};

#endif //LOGOMAKER_THEME_H
