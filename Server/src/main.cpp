/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Server main
*/

#include <iostream>
#include <boost/asio.hpp>
#include "Network/TCPServer.hpp"
#include "Network/UDPServer.hpp"
#include "Network/StreamBuffer/TCPStreamBuffer.hpp"
#include "Network/Components/MoveComponent.hpp"

int main(int ac, char **av)
{
	boost::asio::io_service ioService;
	boost::asio::ip::udp::endpoint endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234);
	UDPServer server(ioService, 1488);
	std::list<struct UDPPlayer> players;
	std::unique_ptr<IServerComponent> move = std::make_unique<MoveComponent>(MoveComponent(players));

	server.addComponent(move);
	// server.send({1, 1, 1, 1, 1, 1, 1}, endpoint);
	// server.send({1, 1, 1, 1, 1, 1, 1}, endpoint);
	ioService.run();
	return 0;
}
