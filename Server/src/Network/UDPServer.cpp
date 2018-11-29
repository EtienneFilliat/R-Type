/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#include <iostream>
#include "Network/UDPServer.hpp"

UDPServer::UDPServer(boost::asio::io_service &ioService, unsigned short port)
	: _socket(ioService, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port))
{
	this->read();
}

void UDPServer::read()
{
	_socket.async_receive_from(_clientStreamBuffer.getStreamBuffer().prepare(512), _endpoint,
		std::bind(&UDPServer::routine, this, std::placeholders::_1));
}

void UDPServer::routine(const boost::system::error_code &error)
{
	struct UDPClientStreamBufferData data;

	std::cout << "Data Received ..." << std::endl;
	//_clientStreamBuffer.getStreamBuffer().commit(512);
	if (!error) {
		data = _clientStreamBuffer.read();
		std::cout << data.event << std::endl;
		if (_components.find(data.event) != _components.end())
			(*(_components.find(data.event))->second).run(_socket, _endpoint, data);
		this->read();
	} else {
		_socket.close();
	}
}