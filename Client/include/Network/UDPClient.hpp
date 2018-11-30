/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#ifndef R_TYPE_SERVER_UDPClient_HPP
#define R_TYPE_SERVER_UDPClient_HPP

#include <boost/asio.hpp>
#include <functional>
#include "StreamBuffer/UDPServerStreamBuffer.hpp"
#include "StreamBuffer/UDPClientStreamBuffer.hpp"

class UDPClient {
public:
	UDPClient(boost::asio::io_service &, unsigned short, const std::function<void(struct UDPServerStreamBufferData)> &);
	~UDPClient() = default;
	void send(struct UDPClientStreamBufferData, boost::asio::ip::udp::endpoint);

private:
	boost::asio::ip::udp::socket _socket;
	boost::asio::ip::udp::endpoint _endpoint;
	UDPServerStreamBuffer _serverStreamBuffer;
	UDPClientStreamBuffer _clientStreamBuffer;
	std::function<void(struct UDPServerStreamBufferData)> _pushToQueue;

	void read();
	void routine(const boost::system::error_code &, std::size_t);
};

#endif //R_TYPE_SERVER_UDPClient_HPP
