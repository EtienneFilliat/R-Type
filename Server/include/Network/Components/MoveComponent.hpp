/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#ifndef R_TYPE_SERVER_MOVECOMPONENT_HPP
#define R_TYPE_SERVER_MOVECOMPONENT_HPP

#include <list>
#include "Events.hpp"
#include "AServerComponent.hpp"
#include "Network/DataStruct/Player.hpp"

class MoveComponent : public AServerComponent {
	public:
	explicit MoveComponent(std::list<struct UDPPlayer> &players) : AServerComponent(MOVE), _players(players) {}
	~MoveComponent() final = default;
	bool run(boost::asio::ip::tcp::socket &, struct TCPStreamBufferData &) const final;
	bool run(boost::asio::ip::udp::socket &, boost::asio::ip::udp::endpoint, struct UDPClientStreamBufferData &) const final;
	private:
	std::list<struct UDPPlayer> &_players;
};


#endif //R_TYPE_SERVER_MOVECOMPONENT_HPP
