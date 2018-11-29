/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#ifndef R_TYPE_SERVER_CONNECTCOMPONENT_HPP
#define R_TYPE_SERVER_CONNECTCOMPONENT_HPP

#include <list>
#include "Actions.hpp"
#include "AServerComponent.hpp"
#include "Network/DataStruct/Player.hpp"

class ConnectComponent : public AServerComponent {
	public:
	explicit ConnectComponent(std::list<struct TCPPlayer> &playersConnected) : AServerComponent(CONNECT), _playersConnected(playersConnected) {}
	~ConnectComponent() final = default;
	bool run(boost::asio::ip::tcp::socket &, struct TCPStreamBufferData &) const final;
	bool run(boost::asio::ip::udp::socket &, boost::asio::ip::udp::endpoint, struct UDPClientStreamBufferData &) const final;
	private:
	std::list<struct TCPPlayer> &_playersConnected;
};

#endif //R_TYPE_SERVER_CONNECTCOMPONENT_HPP
