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
#include "Network/StreamBuffer/TCPStreamBuffer.hpp"


Menu::Window::Window(sf::VideoMode mode, const sf::String &title)
	: window(mode, title),
	background(Image(MENU_DEFAULT_BG)),
	joingameBtn(Button(JOINGAME_IMG, JOINGAME_PX, JOINGAME_PY)),
	inGame(false),
	isIp(false),
	ipTextField(IP_IMG_PATH),
	portTextField(PORT_IMG_PATH),
	_ip("")
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
				!ipTextField.getData().isEmpty() && !portTextField.getData().isEmpty())
				inGame = ConnectToServer(ipTextField.getData().toAnsiString(), portTextField.getData().toAnsiString());
			if (ipTextField.isSelected(mousePosF) && !isIp)
				isIp = true;
			if (portTextField.isSelected(mousePosF) && isIp)
				isIp = false;
		}
	}
}

bool Menu::Window::ProcessRes(std::size_t bytesRecived, char *res)
{
	std::cout << "procces" << std::endl;
	if (bytesRecived < 1)
		return false;
	if (res[0] != Constants::TcpActions::OK)
		return false;
	std::cout << "true" << std::endl;
	return true;
}

bool Menu::Window::ConnectToServer(const std::string &ip, const std::string &portString)
{

	std::string playerName = "PlayerName\n";
	boost::asio::io_service ios;
	boost::asio::ip::tcp::socket socket(ios);
	TCPStreamBuffer streambuffer;
	int port = 0;
	try {
		port = std::stoi(portString);
	} catch (std::exception &e) {
		return false;
	}
	boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(ip), port);

	socket.connect(endpoint);
	streambuffer.write(Constants::TcpActions::CONNECT, playerName.size(), playerName);
	boost::asio::write(socket, streambuffer.getStreamBuffer());
	boost::asio::read(socket, streambuffer.getStreamBuffer(), boost::asio::transfer_at_least(1));
	TCPStreamBufferData data = streambuffer.read();
	socket.close();
	if (data.action != Constants::TcpActions::OK)
		return false;
	return false;
}

std::string Menu::Window::FormatTCPData(Constants::TcpActions action, std::string &payload)
{
	std::string packet;
	int size = payload.size();
	packet += reinterpret_cast<char *>(&action);
	packet += reinterpret_cast<char *>(&size);
	packet += payload;
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
	//boost::asio::io_service ios;
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
}
