// ================================================
// image.h
// Created by Yaowei Lei on 2021/5/10.
// ================================================

#ifndef FILETREE_IMAGE_H
#define FILETREE_IMAGE_H

#include <SFML/Graphics.hpp>
#include <iostream>


class Image {
public:
    enum image {
        DIRECTORIES, DIRECTORY, FILE, RED, GREEN, BLUE, THEME, THEMES,THEME1, THEME2, THEME3
    };
    static std::map<image, sf::Texture> images;
    static std::map<image, bool> loaded;
    static sf::Texture& getImage(image image);
    static void loadImage(image image);
    static std::string getImagePath(image image);

    static void saveScreenShot(const sf::Window &window, sf::Vector2i size, sf::Vector2i position);

private:
    static sf::Texture screenShot;
    static sf::Image part;
};

#endif //FILETREE_IMAGE_H
