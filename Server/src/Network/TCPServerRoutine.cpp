/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#include <iostream>
#include "Network/TCPServerRoutine.hpp"

TCPServerRoutine::TCPServerRoutine(boost::asio::io_service &ioService,
	std::map<int, std::unique_ptr<IServerComponent>> &components)
	: _socket(ioService), _components(components)
{}

boost::asio::ip::tcp::socket &TCPServerRoutine::getSocket()
{
	return (_socket);
}

void TCPServerRoutine::start()
{
	std::cout << "[TCPServer] status :: client accepted" << std::endl;
	this->read();
}

void TCPServerRoutine::read()
{
	boost::asio::async_read(_socket, _streamBuffer.getStreamBuffer(),
		boost::asio::transfer_at_least(1),
		std::bind(&TCPServerRoutine::routine, shared_from_this(), std::placeholders::_1));
}

void TCPServerRoutine::routine(const boost::system::error_code &error)
{
	struct TCPStreamBufferData data;

	if (!error) {
		data = _streamBuffer.read();
		std::cout << data.action << std::endl;
		std::cout << data.body << std::endl;
		if (_components.find(data.action) != _components.end())
			(*(_components.find(data.action))->second).run(_socket, data);
		this->read();
	} else {
		_socket.close();
	}
}