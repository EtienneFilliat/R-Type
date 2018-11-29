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
	UDPServer server(ioService, 1488);
	std::list<struct UDPPlayer> players;
	std::unique_ptr<IServerComponent> move = std::make_unique<MoveComponent>(MoveComponent(players));

	server.addComponent(move);
	ioService.run();
	return 0;
}
