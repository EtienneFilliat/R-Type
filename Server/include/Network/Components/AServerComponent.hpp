/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#ifndef R_TYPE_SERVER_ASERVERCOMPONENT_HPP
#define R_TYPE_SERVER_ASERVERCOMPONENT_HPP

#include "IServerComponent.hpp"

class AServerComponent : public IServerComponent {
	public:
	explicit AServerComponent(int command);
	~AServerComponent() override = default;
	bool run(boost::asio::ip::tcp::socket &, struct TCPStreamBufferData &) const override = 0;
	bool run(boost::asio::ip::udp::socket &, boost::asio::ip::udp::endpoint, struct UDPClientStreamBufferData &) const override = 0;
	int getCommand() const noexcept override;

	protected:
	int _command;
};

#endif //R_TYPE_SERVER_ASERVERCOMPONENT_HPP
