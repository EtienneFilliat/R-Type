/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#ifndef R_TYPE_SERVER_UDPSERVER_HPP
#define R_TYPE_SERVER_UDPSERVER_HPP

#include <boost/asio.hpp>
#include "AServer.hpp"
#include "StreamBuffer/UDPServerStreamBuffer.hpp"
#include "StreamBuffer/UDPClientStreamBuffer.hpp"

class UDPServer : public AServer {
public:
	UDPServer(boost::asio::io_service &, unsigned short);
	~UDPServer() final = default;

private:
	boost::asio::ip::udp::socket _socket;
	boost::asio::ip::udp::endpoint _endpoint;
	UDPServerStreamBuffer _serverStreamBuffer;
	UDPClientStreamBuffer _clientStreamBuffer;

	void read();
	void routine(const boost::system::error_code &);
};

#endif //R_TYPE_SERVER_UDPSERVER_HPP
