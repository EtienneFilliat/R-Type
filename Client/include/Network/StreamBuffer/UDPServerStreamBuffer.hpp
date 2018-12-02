/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#ifndef R_TYPE_SERVER_UDPSERVERSTREAMBUFFER_HPP
#define R_TYPE_SERVER_UDPSERVERSTREAMBUFFER_HPP

#include "AStreamBuffer.hpp"

struct UDPServerStreamBufferData {
	int index;
	int spriteX;
	int spriteY;
	int spriteWidth;
	int spriteHeight;
	int x;
	int y;
};

class UDPServerStreamBuffer : public AStreamBuffer {
	public:
	UDPServerStreamBuffer();
	~UDPServerStreamBuffer() final = default;
	void write(struct UDPServerStreamBufferData &);
	struct UDPServerStreamBufferData read(std::size_t);
};

#endif //R_TYPE_SERVER_UDPSERVERSTREAMBUFFER_HPP
