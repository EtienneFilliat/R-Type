/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Server main
*/

#include <boost/asio.hpp>
#include "Network/TCPServer.hpp"
#include "Network/UDPServer.hpp"
#include "Network/Components/MessageComponent.hpp"

int main(int ac, char **av)
{
	boost::asio::io_service ioService;
	TCPServer server(ioService, 1488);
	std::unique_ptr<IServerComponent> msg = std::make_unique<MessageComponent>(MessageComponent());

	server.addComponent(msg);
	ioService.run();
	return 0;
}
