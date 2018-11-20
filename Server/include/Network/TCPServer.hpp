/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#ifndef R_TYPE_SERVER_TCPSERVER_HPP
#define R_TYPE_SERVER_TCPSERVER_HPP

#include <boost/asio.hpp>
#include "AServer.hpp"
#include "TCPServerRoutine.hpp"

class TCPServer : public AServer {
public:
	TCPServer(boost::asio::io_service &, unsigned short);
	~TCPServer() final = default;

private:
	boost::asio::ip::tcp::acceptor _acceptor;

	void accept();
	void routine(std::shared_ptr<TCPServerRoutine>,
	        const boost::system::error_code &);
};

#endif //R_TYPE_SERVER_TCPSERVER_HPP
