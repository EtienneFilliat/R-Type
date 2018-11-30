/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#include <iostream>
#include "Network/UDPClient.hpp"

UDPClient::UDPClient(boost::asio::io_service &ioService, unsigned short port, const std::function<void(struct UDPServerStreamBufferData)> &cllbk)
	: _socket(ioService, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port)),
	_pushToQueue(cllbk)
{
	this->read();
}

void UDPClient::send(struct UDPClientStreamBufferData data, boost::asio::ip::udp::endpoint endpoint)
{
	_clientStreamBuffer.write(data);
	_socket.send_to(_clientStreamBuffer.getStreamBuffer().data(), endpoint);
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

	std::cout << "Data Received (" << size << ")" << std::endl;
	if (!error) {
		data = _serverStreamBuffer.read(size);
		_pushToQueue(data);
		std::cout << data.spriteX << " - " << data.spriteY << std::endl;
		this->read();
	} else {
		_socket.close();
	}
}