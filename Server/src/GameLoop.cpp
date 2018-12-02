/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** game loop
*/

#include "GameLoop.hpp"

GameLoop::GameLoop(std::list<std::shared_ptr<Ecs::Entity>> &list, boost::asio::io_service &iso, const std::string &ip)
	: _hitboxSystem(list),
	_AISystem(list),
	_endpoint(boost::asio::ip::address::from_string(ip), STD_CLI_UPD_PORT),
	_server(new UDPServer(iso, STD_SERV_UPD_PORT)),
	_frameSendingSystem(list, *_server, _endpoint)
{}

void GameLoop::run()
{
	while (true) {
		_AISystem.run();
		_hitboxSystem.run();
		_frameSendingSystem.run();
		sleep(1);
	}
}