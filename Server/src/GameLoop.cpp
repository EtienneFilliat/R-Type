/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** game loop
*/

#include "Timer.hpp"
#include "GameLoop.hpp"

GameLoop::GameLoop(std::list<std::shared_ptr<Ecs::Entity>> &list,
	boost::asio::io_service &isoUDP,
	boost::asio::io_service &isoTCP,
	const std::string &ip)
	: _hitboxSystem(list),
	_AISystem(list),
	_actionQueue(new SafeQueue<struct UDPClientStreamBufferData>()),
	_endpoint(boost::asio::ip::address::from_string(ip), STD_CLI_UPD_PORT),
	_serverUDP(new UDPServer(isoUDP, STD_SERV_UPD_PORT, _actionQueue)),
	_serverTCP(new TCPServer(isoTCP, STD_SERV_TCP_PORT)),
	_frameSendingSystem(list, _players, *_serverUDP, _endpoint),
	_playerSystem(list, _actionQueue),
	_weaponSystem(list)
{
	std::unique_ptr<IServerComponent> connect =
		std::make_unique<ConnectComponent>(ConnectComponent(_players));

	_serverTCP->addComponent(connect);
}

void GameLoop::run()
{
	Timer gameClock;

	while (true) {
		gameClock.start();
		if (!_actionQueue->empty())
			_playerSystem.run();
		_AISystem.run();
		_hitboxSystem.run();
		_frameSendingSystem.run();
		_weaponSystem.run();
		gameClock.end();
		gameClock.waitFrame();
	}
}