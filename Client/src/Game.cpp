/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Game
*/

#include <iostream>
#include <chrono>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Timer.hpp"

Game::Game(sf::RenderWindow &window, const std::string &ip, boost::asio::io_service &iso, const std::string &name)
    : _window(window),
	_ip(ip),
    _player(new Image(PLAYER_SPRITE)),
    _monster1(new Image(MONSTER1_SPRITE)),
    _monster2(new Image(MONSTER2_SPRITE)),
	// _missile(new Image(MISSILE_SPRITE))
	_playerName(name + '\n'),
	_QClass(new SafeQueue<struct UDPServerStreamBufferData>()),
	_endpoint(boost::asio::ip::address::from_string(ip), STD_SERV_UPD_PORT),
	_client(new UDPClient(iso, STD_CLI_UPD_PORT, _QClass))
{
	_paralax.addbck("Client/res/parallax-space-backgound.png");
	_paralax.addbck("Client/res/parallax-space-far-planets.png");
	_paralax.addbck("Client/res/parallax-space-stars.png");
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

void Game::sendAction()
{
	if (!_actions.empty()) {
		_client->send(_actions.back(), _endpoint);
		std::queue<struct UDPClientStreamBufferData> empty;
		std::swap(_actions, empty);
	}
}

void Game::CheckPlayerInput(sf::Event &event)
{
	switch (event.key.code) {
		case sf::Keyboard::Z :
			_actions.push({_playerName, Constants::EVENT::MOVE, Constants::DIRECTION::UP});
			break;
		case sf::Keyboard::Q :
			_actions.push({_playerName, Constants::EVENT::MOVE, Constants::DIRECTION::LEFT});
			break;
		case sf::Keyboard::S :
			_actions.push({_playerName, Constants::EVENT::MOVE, Constants::DIRECTION::DOWN});
			break;
		case sf::Keyboard::D :
			_actions.push({_playerName, Constants::EVENT::MOVE, Constants::DIRECTION::RIGHT});
			break;
		case sf::Keyboard::Space :
			_actions.push({_playerName, Constants::EVENT::SHOOT, 0});
			break;
		default :
			break;
	}
}

void Game::processFrame()
{
	while (!_QClass->empty()) {
		auto item = _QClass->pop();
		switch (item.index) {
			case Constants::TYPE::PLAYER :
				_player->setPos(item.x, item.y);
				_window.draw(_player->get_sprite());
				break;
			case Constants::TYPE::MONSTER_1 :
				_monster1->setPos(item.x, item.y);
				_window.draw(_monster1->get_sprite());
				break;
			case Constants::TYPE::MONSTER_2 :
				_monster2->setPos(item.x, item.y);
				_window.draw(_monster2->get_sprite());
				break;
			default :
				break;
		}
	}
}

void Game::GameDisplay()
{
	if (!_QClass->empty())
		_window.clear();
	_paralax.moveBackground(_window);
    processFrame();
	_window.display();
}

void Game::run()
{

	Timer gameClock;
	_window.clear();
	while (GameEvents()) 
	{
		gameClock.start();
		GameDisplay();
		sendAction();
		gameClock.end();
		gameClock.waitFrame();
	}
}