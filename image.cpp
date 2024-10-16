// ================================================
// image.cpp
// Created by Yaowei Lei on 2021/5/10.
// ================================================

#include "image.h"

std::map<Image::image, sf::Texture> Image::images;
std::map<Image::image, bool> Image::loaded;
sf::Texture Image::screenShot;
sf::Image Image::part;

sf::Texture &Image::getImage(Image::image image) {
    if(!loaded[image]){
        loadImage(image);
    }
    return images[image];
}

void Image::loadImage(Image::image image) {
    if(!loaded[image]){
        if(!images[image].loadFromFile("../image/"+ getImagePath(image))) {
            exit(14);
        }
        loaded[image] = true;
    }
}

std::string Image::getImagePath(Image::image image) {
    if(image == image::FILE) {
        return "file.png";
    }
    if(image == image::DIRECTORY) {
        return "directory.png";
    }
    if(image == image::DIRECTORIES) {
        return "directories.png";
    }
    if(image == image::RED) {
        return "red.png";
    }
    if(image == image::GREEN) {
        return "green.png";
    }
    if(image == image::BLUE) {
        return "blue.png";
    }
    if(image == image::THEME1) {
        return "theme1.png";
    }
    if(image == image::THEME2) {
        return "theme2.png";
    }
    if(image == image::THEME3) {
        return "theme3.png";
    }
    if(image == image::THEME) {
        return "theme.png";
    }
    if(image == image::THEMES) {
        return "themes.png";
    }
}

void Image::saveScreenShot(const sf::Window &window, sf::Vector2i size, sf::Vector2i position) {
    if(!screenShot.create(window.getSize().x, window.getSize().y)) {
        std::cout << "Screenshot create error" << std::endl;
    }
    screenShot.update(window);
    //if(!screenShot.copyToImage().saveToFile("../save/Screenshot.png")) {
    //    std::cout << "Screenshot save error" << std::endl;
    //}
    part.create(size.x, size.y);
    part.copy(screenShot.copyToImage(), 0, 0, {position.x, position.y, size.x, size.y});

    time_t now = time(0);
    tm* timePtr = localtime(&now);

    if(part.saveToFile("../save/logo_" + std::to_string(timePtr->tm_year) + "_" +
                std::to_string(timePtr->tm_mon) + "_" + std::to_string(timePtr->tm_mday) + "_" +
                std::to_string(timePtr->tm_hour) + "_" + std::to_string(timePtr->tm_min) + "_" +
                std::to_string(timePtr->tm_sec) + ".png")){
        std::cout << "Screenshot saved" << std::endl;
    }
}
