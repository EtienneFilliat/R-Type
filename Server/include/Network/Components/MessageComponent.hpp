/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#ifndef R_TYPE_SERVER_MESSAGECOMPONENT_H
#define R_TYPE_SERVER_MESSAGECOMPONENT_H

#include "IServerComponent.hpp"

class MessageComponent : public IServerComponent {
public:
	MessageComponent() = default;
	~MessageComponent() final = default;
	bool run(boost::asio::ip::tcp::socket &, std::string) const final;
	bool run(boost::asio::ip::udp::socket &, boost::asio::ip::udp::endpoint, std::string) const final;
	const std::string &getCommand() const noexcept final;

private:
	const std::string _command = "MSG";
};

#endif //R_TYPE_SERVER_MESSAGECOMPONENT_H
