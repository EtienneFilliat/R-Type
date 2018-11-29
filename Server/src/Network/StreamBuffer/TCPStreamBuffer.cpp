/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#include "Server/include/Network/StreamBuffer/TCPStreamBuffer.hpp"

TCPStreamBuffer::TCPStreamBuffer()
	: AStreamBuffer()
{}

void TCPStreamBuffer::write(int action, int bodySize, const std::string &body)
{
	AStreamBuffer::write(action);
	AStreamBuffer::write(bodySize);
	AStreamBuffer::write(body);
}

struct TCPStreamBufferData TCPStreamBuffer::read()
{
	struct TCPStreamBufferData data = {-1, -1, ""};

	_iStream.read(reinterpret_cast<char *>(&data.action), sizeof(int));
	_iStream.read(reinterpret_cast<char *>(&data.bodySize), sizeof(int));
	std::getline(_iStream, data.body);
	_oStream.flush();
	_iStream.clear();
	return (data);
}