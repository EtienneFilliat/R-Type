/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#include <boost/asio.hpp>
#include "Network/Components/MessageComponent.hpp"

bool MessageComponent::run(boost::asio::ip::tcp::socket &socket, std::string data) const
{
	(void) data;

	boost::asio::write(socket, boost::asio::buffer("DATA RECEIVED\n"));
	return (true);
}

bool MessageComponent::run(boost::asio::ip::udp::socket &socket,
	boost::asio::ip::udp::endpoint endpoint, std::string data
) const
{
	(void) data;

	socket.send_to(boost::asio::buffer("DATA RECEIVED\n"), endpoint);
	return (true);
}

const std::string &MessageComponent::getCommand() const noexcept
{
	return (_command);
}