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
#include "SafeQueue.hpp"
#include "StreamBuffer/UDPServerStreamBuffer.hpp"
#include "StreamBuffer/UDPClientStreamBuffer.hpp"

class UDPServer : public AServer {
public:
	UDPServer(boost::asio::io_service &, unsigned short, std::shared_ptr<SafeQueue<struct UDPClientStreamBufferData>>);
	~UDPServer() final = default;
	void send(struct UDPServerStreamBufferData, boost::asio::ip::udp::endpoint);

private:
	boost::asio::ip::udp::socket _socket;
	boost::asio::ip::udp::endpoint _endpoint;
	UDPServerStreamBuffer _serverStreamBuffer;
	UDPClientStreamBuffer _clientStreamBuffer;
	std::shared_ptr<SafeQueue<struct UDPClientStreamBufferData>> _actionQueue;

	void read();
	void routine(const boost::system::error_code &, std::size_t);
};

#endif //R_TYPE_SERVER_UDPSERVER_HPP
