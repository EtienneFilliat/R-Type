/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#ifndef R_TYPE_SERVER_TCPSERVERROUTINE_HPP
#define R_TYPE_SERVER_TCPSERVERROUTINE_HPP

#include <memory>
#include <boost/asio.hpp>
#include "Network/StreamBuffer/TCPStreamBuffer.hpp"
#include "Components/IServerComponent.hpp"

class TCPServerRoutine : public std::enable_shared_from_this<TCPServerRoutine> {
public:
	TCPServerRoutine(boost::asio::io_service&, std::map<int, std::unique_ptr<IServerComponent>> &);
	~TCPServerRoutine() = default;
	boost::asio::ip::tcp::socket &getSocket();
	void start();

private:
	boost::asio::ip::tcp::socket _socket;
	std::map<int, std::unique_ptr<IServerComponent>> &_components;
	TCPStreamBuffer _streamBuffer;

	void read();
	void routine(const boost::system::error_code &);

};

#endif //R_TYPE_SERVER_TCPSERVERROUTINE_HPP
