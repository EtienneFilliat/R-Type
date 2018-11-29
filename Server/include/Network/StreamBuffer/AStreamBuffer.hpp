/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#ifndef R_TYPE_SERVER_ASTREAMBUFFER_HPP
#define R_TYPE_SERVER_ASTREAMBUFFER_HPP

#include <boost/asio.hpp>

class AStreamBuffer {
public:
	AStreamBuffer();
	virtual ~AStreamBuffer() = default;
	void write(int i);
	void write(const std::string &str);
	boost::asio::streambuf &getStreamBuffer();
protected:
	boost::asio::streambuf _streamBuffer;
	std::ostream _oStream;
	std::istream _iStream;
};

#endif //R_TYPE_SERVER_ASTREAMBUFFER_HPP
