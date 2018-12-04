/*
** EPITECH PROJECT, 2018
** R-Type
** File description: r-type frame sending system
**
*/

#ifndef FRAMESENDINGSYSTEM_HPP_
	#define FRAMESENDINGSYSTEM_HPP_
	#include "ASystem.hpp"
	#include "Network/UDPServer.hpp"
	#include "Network/DataStruct/Player.hpp"

namespace Ecs {

	class FrameSendingSystem : public ASystem {
		public:
			FrameSendingSystem(
				std::list<std::shared_ptr<Entity>> &entities,
				std::list<struct TCPPlayer> &players,
				UDPServer &server,
				boost::asio::ip::udp::endpoint	_endpoint);
			void run() final;

		private:
			void drawThisEntity(std::shared_ptr<Entity> entity);
			boost::asio::ip::udp::endpoint	_endpoint;
			UDPServer &_server;
			std::list<struct TCPPlayer> &_players;
	};

}

#endif /* !FRAMESENDINGSYSTEM_HPP_ */
