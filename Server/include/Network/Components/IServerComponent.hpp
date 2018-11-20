/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#ifndef R_TYPE_SERVER_ICOMPONENTS_HPP
#define R_TYPE_SERVER_ICOMPONENTS_HPP

#include <boost/asio.hpp>

class IServerComponent {
public:
	virtual ~IServerComponent() = default;
	virtual bool run(boost::asio::ip::tcp::socket &, std::string) const = 0;
	virtual bool run(boost::asio::ip::udp::socket &, boost::asio::ip::udp::endpoint, std::string) const = 0;
	virtual const std::string &getCommand() const noexcept = 0;
};

#endif //R_TYPE_SERVER_ICOMPONENTS_HPP
