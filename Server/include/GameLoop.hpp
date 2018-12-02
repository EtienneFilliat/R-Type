/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** r-type game loop
*/

#ifndef GAMELOOP_HPP_
	#define GAMELOOP_HPP_
	#include "HitboxSystem.hpp"
	#include "AISystem.hpp"
	#include "FrameSendingSystem.hpp"
	#include "Network/UDPServer.hpp"

	#define STD_CLI_UPD_PORT	1234
	#define STD_SERV_UPD_PORT	1488

class GameLoop {
	public:
		GameLoop(std::list<std::shared_ptr<Ecs::Entity>> &list, boost::asio::io_service &iso, const std::string &ip);
		void run();

	private:
		Ecs::HitboxSystem	_hitboxSystem;
		Ecs::AISystem		_AISystem;
		boost::asio::ip::udp::endpoint _endpoint;
		UDPServer	*_server;
		Ecs::FrameSendingSystem	_frameSendingSystem;
};

#endif /* !GAMELOOP_HPP_ */
