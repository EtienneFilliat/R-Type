/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Client main
*/

#include "Menu.hpp"

int main()
{
	Menu::Window menu(sf::VideoMode(MENU_DEFAULT_WIDTH, MENU_DEFAULT_HEIGHT), sf::String(MENU_TITLE));
	menu.Loop();
	return 0;
}
