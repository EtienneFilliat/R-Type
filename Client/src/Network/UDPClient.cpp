/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#include <iostream>
#include "Network/UDPClient.hpp"

UDPClient::UDPClient(boost::asio::io_service &ioService, unsigned short port, std::shared_ptr<SafeQueue<struct UDPServerStreamBufferData>> QClass)
	: _socket(ioService, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port)),
	_QClass(QClass)
{
	this->read();
}

void UDPClient::send(struct UDPClientStreamBufferData data, boost::asio::ip::udp::endpoint endpoint)
{
	_clientStreamBuffer.write(data);
	_socket.send_to(_clientStreamBuffer.getStreamBuffer().data(), endpoint);
	_clientStreamBuffer.getStreamBuffer().consume(1024);
}

void UDPClient::read()
{
	auto buff = _serverStreamBuffer.getStreamBuffer().prepare(512);
	_socket.async_receive_from(buff, _endpoint,
		std::bind(&UDPClient::routine, this, std::placeholders::_1, std::placeholders::_2));
}

void UDPClient::routine(const boost::system::error_code &error, std::size_t size)
{
	struct UDPServerStreamBufferData data;

	if (!error) {
		data = _serverStreamBuffer.read(size);
		_QClass.get()->push(data);
		this->read();
	} else {
		_socket.close();
	}
}