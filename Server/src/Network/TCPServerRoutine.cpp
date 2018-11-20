/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#include <iostream>
#include "Network/TCPServerRoutine.hpp"

TCPServerRoutine::TCPServerRoutine(boost::asio::io_service &ioService,
	std::map<const std::string, std::unique_ptr<IServerComponent>> &components)
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
	boost::asio::async_read(_socket, boost::asio::buffer(_buffer),
		boost::asio::transfer_at_least(1),
		std::bind(&TCPServerRoutine::routine, shared_from_this(),
			_buffer.data(), std::placeholders::_1));
	_buffer.fill(0);
}

void TCPServerRoutine::routine(std::string data,
	const boost::system::error_code &error)
{
	if (!error) {
		std::string cmd = data.substr(0, data.find('='));
		if (_components.find(cmd) != _components.end())
			(*(_components.find(cmd))->second).run(_socket, data);
		this->read();
	} else {
		_socket.close();
	}
}