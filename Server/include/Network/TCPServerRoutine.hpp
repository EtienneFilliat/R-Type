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
#include "Components/IServerComponent.hpp"

class TCPServerRoutine : public std::enable_shared_from_this<TCPServerRoutine> {
public:
	TCPServerRoutine(boost::asio::io_service&, std::map<const std::string, std::unique_ptr<IServerComponent>> &);
	~TCPServerRoutine() = default;
	boost::asio::ip::tcp::socket &getSocket();
	void start();

private:
	boost::asio::ip::tcp::socket _socket;
	std::map<const std::string, std::unique_ptr<IServerComponent>> &_components;
	std::array<char, 1024> _buffer;

	void read();
	void routine(std::string, const boost::system::error_code &);

};

#endif //R_TYPE_SERVER_TCPSERVERROUTINE_HPP
