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
	#include "SafeQueue.hpp"
	#include "FrameSendingSystem.hpp"
	#include "PlayerSystem.hpp"
	#include "Network/UDPServer.hpp"
	#include "Network/TCPServer.hpp"
	#include "Network/DataStruct/Player.hpp"
	#include "Network/Components/ConnectComponent.hpp"
	#include "WeaponSystem.hpp"

	#define STD_CLI_UPD_PORT	1234
	#define STD_SERV_UPD_PORT	1488
	#define STD_SERV_TCP_PORT	1919

class GameLoop {
	public:
		GameLoop(std::list<std::shared_ptr<Ecs::Entity>> &list,
			boost::asio::io_service &isoUDP,
			boost::asio::io_service &isoTCP,
			const std::string &ip);
		void run();

	private:
		Ecs::HitboxSystem	_hitboxSystem;
		Ecs::AISystem		_AISystem;
		std::shared_ptr<SafeQueue<struct UDPClientStreamBufferData>> _actionQueue;
		boost::asio::ip::udp::endpoint _endpoint;
		UDPServer	*_serverUDP;
		TCPServer	*_serverTCP;
		Ecs::FrameSendingSystem	_frameSendingSystem;
		Ecs::PlayerSystem _playerSystem;
		Ecs::WeaponSystem _weaponSystem;
		std::list<struct TCPPlayer> _players;
};

#endif /* !GAMELOOP_HPP_ */
