/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#include <iostream>
#include "Network/Components/MoveComponent.hpp"

bool MoveComponent::run(boost::asio::ip::tcp::socket &socket,
	struct TCPStreamBufferData &data
) const
{
	(void) socket;
	(void) data;

	return (false);
}

bool MoveComponent::run(boost::asio::ip::udp::socket &socket,
	boost::asio::ip::udp::endpoint endpoint, struct UDPClientStreamBufferData &data
) const
{
	(void) endpoint;
	(void) data;
	(void) socket;
	return (true);
}