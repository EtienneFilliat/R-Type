//
// EPITECH PROJECT, 2018
// Menu
// File description:
// Menu class for SFML R-Type

#include "Menu.hpp"

void		Menu::Window::Events()
{
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
	
		if (event.type == sf::Event::MouseMoved)
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);                                                           
        	sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
			newgameBtn.IsHovered(mousePosF);
			joingameBtn.IsHovered(mousePosF);
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);                                                           
        	sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
			if (newgameBtn.IsPressed(mousePosF)) {
				StartGame();
			}
			else if (joingameBtn.IsPressed(mousePosF)) {
				while (JoinGameEvents())
					JoinGameDisplay();
			};
		}
	}
}

bool Menu::Window::JoinGameEvents()
{
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
	}
	return true;
}

void Menu::Window::JoinGameDisplay()
{
	window.clear();
	window.draw(joingameBtn.get_sprite());
	window.display();
}

void Menu::Window::StartGame()
{
	std::cout << "while loop with Display() and Events() where we begin UDP socket connect and just listening to what we should be displaying" << std::endl;
}

void		Menu::Window::Display()
{
	window.clear();
	window.draw(background.get_sprite());
	window.draw(newgameBtn.get_sprite());
	window.draw(joingameBtn.get_sprite());
	window.display();
}

Menu::Window::Window(sf::VideoMode mode, const sf::String &title)
	: window(mode, title),
	background(Image(MENU_DEFAULT_BG)),
	newgameBtn(Button(NEWGAME_IMG, NEWGAME_PX, NEWGAME_PY)),
	joingameBtn(Button(JOINGAME_IMG, JOINGAME_PX, JOINGAME_PY))
{
	background.get_sprite().scale(sf::Vector2f(static_cast<float>(mode.width) / static_cast<float>(MENU_BG_WIDTH), static_cast<float>(mode.height) / static_cast<float>(MENU_BG_HEIGHT)));
}

void		Menu::Window::Loop()
{
	while (window.isOpen()) {
		Events();
		Display();
	}
}