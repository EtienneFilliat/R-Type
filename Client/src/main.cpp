/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Client main
*/

#include "Window.hpp"

int main()
{
	Menu::Window window(sf::VideoMode(MENU_DEFAULT_WIDTH, MENU_DEFAULT_HEIGHT), sf::String(MENU_TITLE));
	window.Loop();
	return 0;
}
