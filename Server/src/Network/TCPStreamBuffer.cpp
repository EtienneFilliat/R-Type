/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#include "Network/TCPStreamBuffer.hpp"

TCPStreamBuffer::TCPStreamBuffer()
	: AStreamBuffer()
{}

struct TCPStreamBufferData TCPStreamBuffer::read()
{
	struct TCPStreamBufferData data = {0, 0, ""};

	_iStream.read(reinterpret_cast<char *>(&data.action), sizeof(int));
	_iStream.read(reinterpret_cast<char *>(&data.bodySize), sizeof(int));
	std::getline(_iStream, data.body);
	_oStream.flush();
	_iStream.clear();
	return (data);
}