/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#ifndef R_TYPE_SERVER_UDPCLIENTSTREAMBUFFER_HPP
#define R_TYPE_SERVER_UDPCLIENTSTREAMBUFFER_HPP

#include "AStreamBuffer.hpp"

struct UDPClientStreamBufferData {
	std::string playerName;
	int event;
	int direction;
};

class UDPClientStreamBuffer : public AStreamBuffer {
	public:
	UDPClientStreamBuffer();
	~UDPClientStreamBuffer() final = default;
	void write(struct UDPClientStreamBufferData &);
	struct UDPClientStreamBufferData read();
};

#endif //R_TYPE_SERVER_UDPCLIENTSTREAMBUFFER_HPP
