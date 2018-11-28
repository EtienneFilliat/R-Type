//
// EPITECH PROJECT, 2018
// Button
// File description:
// Button class for SFML R-Type

#include "Menu.hpp"

Menu::Button::Button(std::string _path, int posX, int posY)
	: Image(_path, posX, posY)
{
}

bool		Menu::Button::IsPressed(sf::Vector2f mousePosF)
{
	if (get_sprite().getGlobalBounds().contains(mousePosF)) {
		get_sprite().setColor(sf::Color(255, 255, 51));
		return true;
	}
	get_sprite().setColor(sf::Color(255, 255, 255));
	return false;
}

bool		Menu::Button::IsHovered(sf::Vector2f mousePosF)
{
	if (get_sprite().getGlobalBounds().contains(mousePosF)) {
		get_sprite().setColor(sf::Color(128, 128, 128));
		return true;
	}
	else {
		get_sprite().setColor(sf::Color(255, 255, 255));
		return false;
	}
}