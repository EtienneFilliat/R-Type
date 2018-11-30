//
// EPITECH PROJECT, 2018
// R-Type
// File description:
// Image class for SFML R-Type

#include <iostream>
#include "Image.hpp"

Image::Image(std::string _path, float posX, float posY)
	: path(_path)
{
	if (!texture.loadFromFile(path))
		std::cout << "Can't find the image: " << path << std::endl;
	sprite.setTexture(texture);
	sprite.setPosition(posX, posY);
}

void Image::toggleFocus(bool focus)
{
	if (focus)
		sprite.setColor(sf::Color(204, 153, 55));
	else
		sprite.setColor(sf::Color(255, 255, 255));
}