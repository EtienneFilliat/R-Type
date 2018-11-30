/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Game
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.hpp"

Game::Game(sf::RenderWindow &window, const std::string &ip, boost::asio::io_service &iso)
    : _window(window),
	_ip(ip),
    _palyer(new Image(PLAYER_SPRITE)),
    _monster1(new Image(MONSTER1_SPRITE)),
    _monster2(new Image(MONSTER2_SPRITE))
{
	boost::asio::ip::udp::endpoint endpoint(boost::asio::ip::address::from_string(_ip), STD_SERV_UPD_PORT);
	_client = new UDPClient(iso, STD_CLI_UPD_PORT, this->pushToQueue);
}

Game::~Game()
{}

bool Game::GameEvents()
{
	sf::Event event;
	while (_window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			_window.close();
			return false;
		}
	}
	return true;
}

void Game::GameDisplay()
{
	_window.clear();
    _window.draw(_palyer->get_sprite());
	_window.display();
}

void Game::run()
{
	while (GameEvents()) 
	{
		GameDisplay();
	}
}