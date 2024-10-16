// ================================================
// logoMaker.cpp
// Created by Yaowei Lei on 2021/5/20.
// ================================================

#include "logoMaker.h"

LogoMaker::LogoMaker(sf::Font& font) : menuBar(Color::getColor(Color::FONT), 32, font, "File", 300 , 40),
                                       logoInput(font, "Logo Text:"),
                                       fontMenu(Color::getColor(Color::FONT), 32, font, "Select Font", 200, 50),
                                       logoDisplay({1500, 580}),
                                       topMask(4), bottomMask(4),
                                       fontColorPicker({140, 35}, 1, {500, 20}, {630, 140}, 245),
                                       bgColorPicker({35, 35}, 1, {500, 20}, {630, 140}, 30),
                                       openFile(Font::getFont(Font::OPENSANS)),
                                       themeSelect(Font::getFont(Font::OPENSANS))
                                       {
    menuBar.setPosition({100, 20});
    menuBar.addItem("New Project", "File");
    menuBar.addItem("Open Project", "File");
    menuBar.addItem("Save Project", "File");
    menuBar.addItem("Close Project", "File");
    menuBar.addItem("Exit", "File");

    menuBar.addMenu(Color::getColor(Color::FONT), 32, font, "Edit", 300 , 40);
    menuBar.addItem("Undo", "Edit");
    menuBar.addItem("Redo", "Edit");

    menuBar.addMenu(Color::getColor(Color::FONT), 32, font, "Render", 300 , 40);
    menuBar.addItem("Export image", "Render");

    menuBar.addMenu(Color::getColor(Color::FONT), 32, font, "View", 300 , 40);
    menuBar.addItem("Theme", "View");

    menuBar.setScale(0.6, 0.6);

    addSlider(font, "Text Opacity:", 370, 100, {30, 750}, 100);
    addSlider(font, "Shadow Opacity:", 370, 100, {30, 790}, 50);
    addSlider(font, "Text X-Axis:", 1150, 1500, {30, 830}, 100);
    addSlider(font, "Text Y-Axis:", 1150, 700, {30, 870}, 200);
    addSlider(font, "Shadow X-Axis:", 1150, 1500, {30, 910}, 100);
    addSlider(font, "Shadow Y-Axis:", 1150, 700, {30, 950}, 450);
    addSlider(font, "Font Size:", 145, 300, {760, 750}, 120);
    rePlaceSliderTrack("Font Size:", -84);
    addSlider(font, "Skew:", 145, 45, {1165, 750}, 20);
    rePlaceSliderTrack("Skew:", -128);
    addSlider(font, "Background Opacity:", 370, 100, {760, 790}, 100);
    rePlaceSliderTrack("Background Opacity:", 51);

    logoInput.setTypingBox(420, 45, 2, Color::getColor(Color::SLIDER));
    logoInput.setPosition({250, 680});
    logoInput.setLabelText("Logo Text Input: ", Color::getColor(Color::FONT), 24, font);
    logoInput.setLabelPosition({30, 690});

    fontMenu.setPosition({835,680});
    for (int i = 0; i != Font::fonts::DEFAULT; i++) {
        Font::loadFont(static_cast<Font::fonts>(i));
        fontMenu.addItem(Font::getFontPath(static_cast<Font::fonts>(i)));
    }
    fontMenu.setMenuScale(0.7, 0.7);

    logoDisplay.setPosition({0, 70});

    fontColorPicker.setPosition({1000, 680});
    fontColorPicker.rePosition({825, 680}, 1500);

    bgColorPicker.setPosition({1420, 680});
    bgColorPicker.rePosition({825, 680}, 1500);

    backgroundLabel.setString("Background Color:");
    backgroundLabel.setFillColor(Color::getColor(Color::FONT));
    backgroundLabel.setCharacterSize(24);
    backgroundLabel.setFont(Font::getFont(Font::OPENSANS));
    backgroundLabel.setPosition(1163, 688);

    openFile.push(Image::DIRECTORY, "save", "save");
    openFile.push(Image::DIRECTORY, "font", "font");
    openFile.push(Image::DIRECTORY, "data", "data");
    openFile.push(Image::FILE, "data", "logo.txt");

    themeSelect.pushTheme(Image::THEMES, "Themes", "Dark", Image::THEME1);
    themeSelect.pushTheme(Image::THEMES, "Themes", "Light", Image::THEME2);
    themeSelect.pushTheme(Image::THEMES, "Themes", "Dusk", Image::THEME3);

    topMask.setPoint(0, {0, 0});
    topMask.setPoint(1, {1500, 0});
    topMask.setPoint(2, {1500, 68});
    topMask.setPoint(3, {0, 68});

    bottomMask.setPoint(0, {0, 0});
    bottomMask.setPoint(1, {1500, 0});
    bottomMask.setPoint(2, {1500, 500});
    bottomMask.setPoint(3, {0, 500});

    topMask.setFillColor(Color::getColor(Color::COVER));
    bottomMask.setPosition(0, 652);
    bottomMask.setFillColor(Color::getColor(Color::COVER));

    setLogoDisplay();
}

void LogoMaker::newProject(sf::RenderWindow &window, sf::Event event) {
    if(menuBar.clickedMenuItem("File", "New Project", window)) {
        reset();
    }
}

void LogoMaker::reset() {
    logoInput.setText("");
    fontMenu.setItemText("Select Font");
    fontColorPicker.setDefaultValue(245);
    bgColorPicker.setDefaultValue(20);
    setSliderValue("Text Opacity:", 100);
    setSliderValue("Shadow Opacity:", 50);
    setSliderValue("Text X-Axis:", 100);
    setSliderValue("Text Y-Axis:", 200);
    setSliderValue("Shadow X-Axis:", 100);
    setSliderValue("Shadow Y-Axis:", 450);
    setSliderValue("Font Size:", 120);
    setSliderValue("Skew:", 20);
    setSliderValue("Background Opacity:", 100);
}

void LogoMaker::openProject(sf::RenderWindow &window, sf::Event event) {
    if(menuBar.clickedMenuItem("File", "Open Project", window)) {
        std::cout << "OPEN A NEW WINDOW\n";
        openFile.createWindow("Select File");
        if(openFile.getSelectedItem() == "logo.txt" && openFile.checkApplyTarget()) {
            std::ifstream file;
            file.open("../data/logo.txt");

            logoInput.setText(readFromTxt(file));
            fontMenu.setItemText(readFromTxt(file));
            fontColorPicker.setDefaultValue(readFromTxt(file,1),readFromTxt(file,2),readFromTxt(file,3));
            bgColorPicker.setDefaultValue(readFromTxt(file,1),readFromTxt(file,2),readFromTxt(file,3));
            for(int i = 0; i < sliderList.size(); i++) {
                sliderList[i].setValue(readFromTxt(file,1));
            }
        }
    }
}



std::string LogoMaker::readFromTxt(std::ifstream &file) {
    std::string data;
    file >> data;
    return data;
}

int LogoMaker::readFromTxt(std::ifstream &file, int) {
    int data = atoi(readFromTxt(file).c_str());
    return data;

}

void LogoMaker::saveProject(sf::RenderWindow &window, sf::Event event) {
    if(menuBar.clickedMenuItem("File", "Save Project", window)) {
        std::ofstream file;
        file.open("../data/logo.txt");

        saveToTxt(file, logoInput.getText().getString());
        saveToTxt(file, fontMenu.getItem().getText().getString());
        saveToTxt(file, fontColorPicker.getRedValue());
        saveToTxt(file, fontColorPicker.getGreenValue());
        saveToTxt(file, fontColorPicker.getBlueValue());
        saveToTxt(file, bgColorPicker.getRedValue());
        saveToTxt(file, bgColorPicker.getGreenValue());
        saveToTxt(file, bgColorPicker.getBlueValue());
        for(int i = 0; i < sliderList.size(); i++) {
            saveToTxt(file, sliderList[i].getValue());
        }
        std::cout << "Data saved to data/logo.txt" << std::endl;
        file.close();
    }
}

void LogoMaker::saveToTxt(std::ofstream &file, std::string value) {
    file << value << std::endl;
}

void LogoMaker::saveToTxt(std::ofstream &file, int value) {
    file << std::to_string(value) << std::endl;
}

void LogoMaker::closeProject(sf::RenderWindow &window, sf::Event event) {
    if(menuBar.clickedMenuItem("File", "Close Project", window)) {
        reset();
    }
}

void LogoMaker::exit(sf::RenderWindow &window, sf::Event event) {
    if (menuBar.clickedMenuItem("File", "Exit", window)) {
        ::exit(100);
    }
}

void LogoMaker::saveLogo(sf::RenderWindow &window, sf::Event event) {
    if(menuBar.clickedMenuItem("Render", "Export image", window)) {
        Image::saveScreenShot(window, (sf::Vector2<int>) logoDisplay.getBackground().getSize(),
                              (sf::Vector2<int>) logoDisplay.getBackground().getPosition());
    }
}

void LogoMaker::changeTheme(sf::RenderWindow &window, sf::Event event) {
    if(menuBar.clickedMenuItem("View", "Theme", window)) {
        std::cout << "OPEN A NEW WINDOW\n";
        themeSelect.createWindow("Select Theme");
        if(themeSelect.checkApplyTarget()) {
            if(themeSelect.getSelectedItem() == "Dark") {
                Theme::applyTheme(Theme::DARK);
            }
            if(themeSelect.getSelectedItem() == "Light") {
                Theme::applyTheme(Theme::LIGHT);
            }
            if(themeSelect.getSelectedItem() == "Dusk") {
                Theme::applyTheme(Theme::DUSK);
            }
            topMask.setFillColor(Color::getColor(Color::COVER));
            bottomMask.setFillColor(Color::getColor(Color::COVER));
            backgroundLabel.setFillColor(Color::getColor(Color::FONT));
        }
    }
}

void LogoMaker::addSlider(sf::Font &font, std::string text, float length, int max, sf::Vector2f position, int DefaultValue) {
    Slider temp(font, text, length, max);
    temp.setValue(DefaultValue);
    temp.setPosition(position);
    sliderList.push_back(temp);
}

void LogoMaker::rePlaceSliderTrack(std::string label, float move) {
    for(int i = 0; i < sliderList.size(); i++) {
        if(sliderList[i].getLabel().getString() == label) {
            sliderList[i].rePlaceTrack(move);
        }
    }
}

bool LogoMaker::checkUnlock() {
    for (int i = 0; i < sliderList.size(); i++) {
        if (sliderList[i].checkState(UNLOCK)) {
            return true;
        }
    }
    return false;
}

void LogoMaker::setSliderValue(std::string slider, int defaultValue) {
    for(int i = 0; i < sliderList.size(); i++) {
        if(sliderList[i].getLabel().getString() == slider) {
            sliderList[i].setValue(defaultValue);
        }
    }
}


int LogoMaker::getSliderValue(std::string slider) {
    for(auto iter : sliderList) {
        if(iter.getLabel().getString() == slider) {
            return iter.getValue();
        }
    }
}


void LogoMaker::setLogoDisplay() {
    logoDisplay.setLogoString(logoInput.getText().getString());
    logoDisplay.setLogoSize(getSliderValue("Font Size:"));
    logoDisplay.setLogoFont(Font::getFont(fontMenu.getItem().getText().getString()));
    logoDisplay.setLogoColor(Color::getColor(Color::FONT));
    logoDisplay.setShadowColor(Color::getColor(Color::FONT));
    logoDisplay.setLogoPosition({static_cast<float>(getSliderValue("Text X-Axis:")), static_cast<float>(getSliderValue("Text Y-Axis:"))});
    logoDisplay.setShadowPosition({static_cast<float>(getSliderValue("Shadow X-Axis:")), static_cast<float>(getSliderValue("Shadow Y-Axis:"))});
    logoDisplay.setShadowSkew(sin(getSliderValue("Skew:") * acos(-1) / 180));

    logoDisplay.setLogoColor(fontColorPicker.getColor());
    logoDisplay.setBackgroundColor(bgColorPicker.getColor());

    sf::Color textColor = logoDisplay.getLogo().getFillColor();
    textColor.a = getSliderValue("Text Opacity:") * 255/100;
    logoDisplay.setLogoColor(textColor);
    sf::Color shadowColor = logoDisplay.getLogo().getFillColor();
    shadowColor.a = getSliderValue("Shadow Opacity:") * 255/100;
    logoDisplay.setShadowColor(shadowColor);
    sf::Color backgroundColor = logoDisplay.getBackground().getFillColor();
    backgroundColor.a = getSliderValue("Background Opacity:") * 255/100;
    logoDisplay.setBackgroundColor(backgroundColor);
}


void LogoMaker::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    logoDisplay.draw(window, states);
    window.draw(topMask);
    window.draw(bottomMask);
    logoInput.draw(window, states);
    menuBar.draw(window, states);
    for (int i = 0; i < sliderList.size(); i++) {
        sliderList[i].draw(window, states);
    }
    window.draw(backgroundLabel);
    fontMenu.draw(window, states);
    fontColorPicker.draw(window, states);
    bgColorPicker.draw(window, states);
}

void LogoMaker::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    newProject(window, event);
    openProject(window, event);
    saveProject(window, event);
    closeProject(window, event);
    exit(window, event);
    saveLogo(window, event);
    changeTheme(window, event);
    logoInput.addEventHandler(window, event);
    setLogoDisplay();
    menuBar.addEventHandler(window, event);
    for (int i = 0; i < sliderList.size(); i++) {
        if(MouseEvents<sf::CircleShape>::mouseClicked(sliderList[i].getBlocker(), window) &&
        !checkUnlock() && fontMenu.checkState(HIDDEN) && fontColorPicker.checkState(HIDDEN) && bgColorPicker.checkState(HIDDEN)) {
                sliderList[i].enableState(UNLOCK);
        }
        sliderList[i].addEventHandler(window, event);
    }
    fontMenu.addEventHandler(window, event);
    fontColorPicker.addEventHandler(window, event);
    bgColorPicker.addEventHandler(window, event);
}

void LogoMaker::update() {
    logoInput.update();
    menuBar.update();
    fontMenu.update();
    logoDisplay.update();
    fontColorPicker.update();
    bgColorPicker.update();
    for(int i = 0; i < sliderList.size(); i++) {
        sliderList[i].update();
        sliderList[i].setTrackColor(Color::getColor(Color::SLIDER));
    }
    openFile.update();
    themeSelect.update();
}





