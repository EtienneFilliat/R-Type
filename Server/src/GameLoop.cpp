/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** game loop
*/

#include <chrono>
#include "GameLoop.hpp"

GameLoop::GameLoop(std::list<std::shared_ptr<Ecs::Entity>> &list, boost::asio::io_service &iso, const std::string &ip)
	: _hitboxSystem(list),
	_AISystem(list),
	_actionQueue(new SafeQueue<struct UDPClientStreamBufferData>()),
	_endpoint(boost::asio::ip::address::from_string(ip), STD_CLI_UPD_PORT),
	_server(new UDPServer(iso, STD_SERV_UPD_PORT, _actionQueue)),
	_frameSendingSystem(list, *_server, _endpoint),
	_playerSystem(list, _actionQueue)
{}

void GameLoop::run()
{
	while (true) {
		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now());
		if (!_actionQueue->empty())
			_playerSystem.run();
		_AISystem.run();
		_hitboxSystem.run();
		_frameSendingSystem.run();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now());
		std::chrono::microseconds time_span(end - start);
    	if (time_span.count() < 41667)
			usleep(41667 - time_span.count());
	}
}