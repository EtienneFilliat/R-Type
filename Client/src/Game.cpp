/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Game
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.hpp"

Game::Game(sf::RenderWindow &window, const std::string &ip, boost::asio::io_service &iso, const std::string &name)
    : _window(window),
	_ip(ip),
    _player(new Image(PLAYER_SPRITE)),
    _monster1(new Image(MONSTER1_SPRITE)),
    _monster2(new Image(MONSTER2_SPRITE)),
	_playerName(name + '\n'),
	_endpoint(boost::asio::ip::address::from_string(ip), STD_SERV_UPD_PORT),
	_client(new UDPClient(iso, STD_CLI_UPD_PORT, this->pushToQueue))
{
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
		if (event.type == sf::Event::KeyPressed)
			CheckPlayerInput(event);
	}
	return true;
}

void Game::sendAction(int event, int dir)
{
	struct UDPClientStreamBufferData data = {_playerName, event, dir};
	std::cout << "Name :" << data.playerName 
	<< " | Event [" << data.event 
	<< "] | Dir [" << data.direction 
	<< "] | SizeOf :" << sizeof(struct UDPClientStreamBufferData) << "\n";
	_client->send(data, _endpoint);
}

void Game::CheckPlayerInput(sf::Event &event)
{
	switch (event.key.code) {
		case sf::Keyboard::Z :
			sendAction(Constants::EVENT::MOVE, Constants::DIRECTION::UP);
			break;
		case sf::Keyboard::Q :
			sendAction(Constants::EVENT::MOVE, Constants::DIRECTION::LEFT);
			break;
		case sf::Keyboard::S :
			sendAction(Constants::EVENT::MOVE, Constants::DIRECTION::DOWN);
			break;
		case sf::Keyboard::D :
			sendAction(Constants::EVENT::MOVE, Constants::DIRECTION::RIGHT);
			break;
		case sf::Keyboard::Space :
			sendAction(Constants::EVENT::SHOOT);
			break;
		default :
			break;
	}
}

void Game::pushToQueue(struct UDPServerStreamBufferData)
{
	std::cout << "pushToQueue" <<std::endl;
};

void Game::GameDisplay()
{
	_window.clear();
    _window.draw(_player->get_sprite());
	_window.display();
}

void Game::run()
{
	while (GameEvents()) 
	{
		GameDisplay();
	}
}