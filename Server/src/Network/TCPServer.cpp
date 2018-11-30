/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#include <iostream>
#include <boost/bind.hpp>
#include "Network/TCPServer.hpp"

TCPServer::TCPServer(boost::asio::io_service &ioService, unsigned short port)
	: _acceptor(ioService, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
{
	this->accept();
}

void TCPServer::accept()
{
	std::shared_ptr<TCPServerRoutine> routine = std::shared_ptr<TCPServerRoutine>(
		new TCPServerRoutine(_acceptor.get_io_service(), _components));

	_acceptor.async_accept(routine->getSocket(),
		std::bind(&TCPServer::routine, this, routine,
			std::placeholders::_1));
}

void TCPServer::routine(std::shared_ptr<TCPServerRoutine> routine,
	const boost::system::error_code &error
)
{
	if (!error)
		routine->start();
	else
		std::cout << "[TCPServer] err :: " << error << std::endl;
	this->accept();
}