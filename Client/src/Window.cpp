//
// EPITECH PROJECT, 2018
// Menu
// File description:
// Menu class for SFML R-Type

#include <iostream>
#include <memory>
#include <cstring>
#include <string.h>
#include <string>
#include <boost/asio.hpp>
#include "IoServiceWork.hpp"
#include "Window.hpp"
#include "Game.hpp"


Menu::Window::Window(sf::VideoMode mode, const sf::String &title)
	: window(mode, title),
	background(Image(MENU_DEFAULT_BG)),
	joingameBtn(Button(JOINGAME_IMG, JOINGAME_PX, JOINGAME_PY)),
	inGame(false),
	isIp(false),
	ipTextField(IP_IMG_PATH),
	portTextField(PORT_IMG_PATH),
	_ip(""),
	_music("Client/res/interstellar.ogg")
{
	if (!font.loadFromFile(FONT_PATH))
		std::cout << "Failed to load font" << std::endl;
	else {
		ipTextField.setFont(font);
		ipTextField.setPos(150, 670);
		ipTextField.setMaxCharacters(15);
		portTextField.setFont(font);
		portTextField.setPos(800, 670);
		portTextField.setMaxCharacters(5);
	}
	_music.isRepeatable(true);
	_music.play();
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

		if (event.type == sf::Event::TextEntered) {
			if ((event.text.unicode >= '0' && event.text.unicode <= '9')
				|| event.text.unicode == '.' || event.text.unicode == '\b')  {
				if (isIp)
					ipTextField.setText(event.text.unicode);
				else
					portTextField.setText(event.text.unicode);
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);                                                           
        	sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
			if (joingameBtn.IsPressed(mousePosF) &&
				!ipTextField.getData().isEmpty() && !portTextField.getData().isEmpty()) {
					_ip = ipTextField.getData().toAnsiString();
					inGame = true; //= ConnectToServer(ipTextField.getData().toAnsiString(), portTextField.getData().toAnsiString());
				}
			if (ipTextField.isSelected(mousePosF) && !isIp)
				isIp = true;
			if (portTextField.isSelected(mousePosF) && isIp)
				isIp = false;
		}
	}
}

bool Menu::Window::ProcessRes(std::size_t bytesRecived, char *res)
{
	if (bytesRecived < 1)
		return false;
	if (res[0] != Constants::TcpActions::OK)
		return false;
	return true;
}

bool Menu::Window::ConnectToServer(const std::string &ip, const std::string &portString)
{
	sf::TcpSocket socket;
	std::string playerName = "PlayerName";
	int port = 0;
	try {
		port = std::stoi(portString);
	} catch (std::exception &e) {
		port = 0;
	}
	sf::Socket::Status status = socket.connect(ip, port);
	if (status != sf::Socket::Done)
		return false;
	_ip = ip;
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
	packet += payload;
	packet += static_cast<char>(payload.size());
	return packet;
}

void Menu::Window::Display()
{
	window.clear();

	window.draw(background.get_sprite());
	window.draw(joingameBtn.get_sprite());
	ipTextField.draw(window);
	portTextField.draw(window);
	window.display();
}

void Menu::Window::Loop()
{
	IoServiceWork s;

	while (window.isOpen()) {
		if (!inGame) {
			Events();
			Display();
		} else {
			Game game(window, _ip, s.ioService(), "PlayerName"); //_ip
			game.run();
		}
	}
	_music.stop();
}
