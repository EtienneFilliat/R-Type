/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#include "Network/Components/ConnectComponent.hpp"

bool ConnectComponent::run(boost::asio::ip::tcp::socket &socket,
	struct TCPStreamBufferData &data
) const
{
	bool ret = true;
	TCPStreamBuffer streamBuffer;

	for (auto &player : _playersConnected)
		ret = !(player.name == data.body);
	if (ret) {
		_playersConnected.push_back({data.body, socket});
		streamBuffer.write(OK, 0, "");
	} else {
		streamBuffer.write(KO, 0, "");
	}
	boost::asio::write(socket, streamBuffer.getStreamBuffer());
	return (ret);
}

bool ConnectComponent::run(boost::asio::ip::udp::socket &socket,
	boost::asio::ip::udp::endpoint endpoint, struct UDPClientStreamBufferData &data
) const
{
	(void) socket;
	(void) endpoint;
	(void) data;

	return (false);
}