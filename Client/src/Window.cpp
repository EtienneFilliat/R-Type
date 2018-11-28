//
// EPITECH PROJECT, 2018
// Menu
// File description:
// Menu class for SFML R-Type

#include <iostream>
#include "Window.hpp"


Menu::Window::Window(sf::VideoMode mode, const sf::String &title)
	: window(mode, title),
	background(Image(MENU_DEFAULT_BG)),
	joingameBtn(Button(JOINGAME_IMG, JOINGAME_PX, JOINGAME_PY)),
	inGame(false)
{
	background.get_sprite().scale(sf::Vector2f(static_cast<float>(mode.width) / static_cast<float>(MENU_BG_WIDTH), static_cast<float>(mode.height) / static_cast<float>(MENU_BG_HEIGHT)));
}

void Menu::Window::Events()
{
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
	
		if (event.type == sf::Event::MouseMoved)
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);                                                           
        	sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
			joingameBtn.IsHovered(mousePosF);
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);                                                           
        	sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
			if (joingameBtn.IsPressed(mousePosF))
				inGame = true;
		}
	}
}

void Menu::Window::GameEvents()
{
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void Menu::Window::GameDisplay()
{
	window.clear();
	window.display();
}

void Menu::Window::Display()
{
	window.clear();
	window.draw(background.get_sprite());
	window.draw(joingameBtn.get_sprite());
	window.display();
}

void Menu::Window::Loop()
{
	while (window.isOpen()) {
		if (!inGame) {
			Events();
			Display();
		} else {
			GameEvents();
			GameDisplay();
		}
	}
}