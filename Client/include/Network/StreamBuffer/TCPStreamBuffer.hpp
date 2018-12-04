/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#ifndef R_TYPE_SERVER_TCPSTREAMBUFFER_HPP
#define R_TYPE_SERVER_TCPSTREAMBUFFER_HPP

#include "AStreamBuffer.hpp"

struct TCPStreamBufferData {
	int action;
	int bodySize;
	std::string body;
};

class TCPStreamBuffer : public AStreamBuffer {
public:
	TCPStreamBuffer();
	~TCPStreamBuffer() final = default;
	void write(int action, int bodySize, const std::string &body);
	struct TCPStreamBufferData read();
};

#endif //R_TYPE_SERVER_TCPSTREAMBUFFER_HPP
