//
// EPITECH PROJECT, 2018
// R-Type
// File description:
// Image class for SFML R-Type

#include "Menu.hpp"

Menu::Image::Image(std::string _path, float posX, float posY)
	: path(_path)
{
	if (!texture.loadFromFile(path))
		std::cout << "Can't find the image: " << path << std::endl;
	sprite.setTexture(texture);
	sprite.setPosition(posX, posY);
}