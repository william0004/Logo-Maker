// ================================================
// logoMaker.h
// Created by Yaowei Lei on 2021/5/20.
// ================================================

#ifndef MENUBAR_LOGOMAKER_H
#define MENUBAR_LOGOMAKER_H

#include <fstream>
#include "menuBar.h"
#include "slider.h"
#include "textInput.h"
#include "font.h"
#include "dropdownMenu.h"
#include "logoDisplay.h"
#include "colorPicker.h"
#include "fileSelect.h"
#include "themeSelect.h"
#include "cmath"


class LogoMaker : public sf::Drawable {
private:
    MenuBar menuBar;
    std::vector<Slider> sliderList;
    TextInput logoInput;
    DropdownMenu fontMenu;
    LogoDisplay logoDisplay;
    ColorPicker fontColorPicker;
    ColorPicker bgColorPicker;
    sf::Text backgroundLabel;
    FileSelect openFile;
    ThemeSelect themeSelect;

    sf::ConvexShape topMask;
    sf::ConvexShape bottomMask;

public:
    LogoMaker(sf::Font&);
    void newProject(sf::RenderWindow &window, sf::Event event);
    void reset();
    void openProject(sf::RenderWindow &window, sf::Event event);
    void saveProject(sf::RenderWindow &window, sf::Event event);
    std::string readFromTxt(std::ifstream&);
    int readFromTxt(std::ifstream&, int);
    void saveToTxt(std::ofstream&, std::string);
    void saveToTxt(std::ofstream&, int);
    void closeProject(sf::RenderWindow &window, sf::Event event);
    void exit(sf::RenderWindow &window, sf::Event event);
    void saveLogo(sf::RenderWindow &window, sf::Event event);
    void changeTheme(sf::RenderWindow &window, sf::Event event);
    void rePlaceSliderTrack(std::string, float);
    void addSlider(sf::Font&, std::string, float, int, sf::Vector2f, int);
    void setSliderValue(std::string, int);
    bool checkUnlock();
    int getSliderValue(std::string);
    void setLogoDisplay();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};


#endif //MENUBAR_LOGOMAKER_H
