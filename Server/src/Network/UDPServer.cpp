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
	_socket.async_receive_from(boost::asio::buffer(_buffer), _endpoint,
		std::bind(&UDPServer::routine, this, _buffer.data(), std::placeholders::_1));
	_buffer.fill(0);
}

void UDPServer::routine(std::string data,
	const boost::system::error_code &error)
{
	if (!error) {
		std::string cmd = data.substr(0, data.find('='));
		if (_components.find(cmd) != _components.end())
			(*(_components.find(cmd))->second).run(_socket,
				_endpoint, data);
		this->read();
	} else {
		_socket.close();
	}
}