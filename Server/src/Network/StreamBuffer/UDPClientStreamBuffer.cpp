/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#include <iostream>
#include "Network/StreamBuffer/UDPClientStreamBuffer.hpp"

UDPClientStreamBuffer::UDPClientStreamBuffer()
	: AStreamBuffer()
{}

void UDPClientStreamBuffer::write(struct UDPClientStreamBufferData &data)
{
	AStreamBuffer::write(data.playerName);
	AStreamBuffer::write(data.event);
	AStreamBuffer::write(data.direction);
}

struct UDPClientStreamBufferData UDPClientStreamBuffer::read(std::size_t size)
{
	struct UDPClientStreamBufferData data = {"", -1, -1};

	_streamBuffer.commit(size);
	std::getline(_iStream, data.playerName);
	_iStream.read(reinterpret_cast<char *>(&data.event), sizeof(int));
	_iStream.read(reinterpret_cast<char *>(&data.direction), sizeof(int));
	return (data);
}