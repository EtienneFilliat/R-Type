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
	auto buff = _clientStreamBuffer.getStreamBuffer().prepare(512);
	_socket.async_receive_from(buff, _endpoint,
		std::bind(&UDPServer::routine, this, std::placeholders::_1, std::placeholders::_2));
}

void UDPServer::routine(const boost::system::error_code &error, std::size_t size)
{
	struct UDPClientStreamBufferData data;

	std::cout << "Data Received (" << size << ")" << std::endl;
	if (!error) {
		data = _clientStreamBuffer.read(size);
		if (_components.find(data.event) != _components.end())
			(*(_components.find(data.event))->second).run(_socket, _endpoint, data);
		this->read();
	} else {
		_socket.close();
	}
}