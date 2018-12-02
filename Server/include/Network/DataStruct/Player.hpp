/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#ifndef R_TYPE_SERVER_PLAYER_HPP
#define R_TYPE_SERVER_PLAYER_HPP

#include <string>
#include <boost/asio.hpp>

struct TCPPlayer {
	std::string &name;
	boost::asio::ip::tcp::socket &socket;
};

struct UDPPlayer {
	std::string &name;
	boost::asio::ip::udp::socket &socket;
};

#endif //R_TYPE_SERVER_PLAYER_HPP
