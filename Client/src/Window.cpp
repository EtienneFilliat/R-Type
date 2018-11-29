//
// EPITECH PROJECT, 2018
// Menu
// File description:
// Menu class for SFML R-Type

#include <iostream>
#include <memory>
#include <cstring>
#include <string.h>
#include "Window.hpp"
#include "Game.hpp"


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
				inGame = ConnectToServer();
		}
	}
}

bool Menu::Window::ProcessRes(std::size_t bytesRecived, char *res)
{
	std::cout << "bytes : " << bytesRecived << std::endl;
	if (bytesRecived < 1)
		return false;
	std::cout << "STEP 1" << res[0] << std::endl;
	if (res[0] != Constants::TcpActions::OK)
		return false;
	std::cout << "STEP 2"<< std::endl;
	return true;
}

bool Menu::Window::ConnectToServer()
{
	sf::TcpSocket socket;
	std::string playerName = "PlayerName";
	sf::Socket::Status status = socket.connect("127.0.0.1", 2048);
	if (status != sf::Socket::Done)
		return false;
	std::string req = FormatTCPData(Constants::TcpActions::CONNECT, playerName);
	if (socket.send(req.c_str(), req.size()) != sf::Socket::Done)
		return false;
	char res[Constants::MaxPayloadSize];
	std::memset(res, '\0', Constants::MaxPayloadSize);
	std::size_t received;
	if (socket.receive(res, Constants::MaxPayloadSize, received) != sf::Socket::Done)
		return false;
	return ProcessRes(received, res);
}

std::string Menu::Window::FormatTCPData(Constants::TcpActions action, std::string &payload)
{
	std::string packet;
	packet += static_cast<char>(action);
	packet += static_cast<char>(payload.size());
	packet += payload;
	return packet;
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
	Game game(window);

	while (window.isOpen()) {
		if (!inGame) {
			Events();
			Display();
		} else {
			game.GameEvents();
			game.GameDisplay();
		}
	}
}
