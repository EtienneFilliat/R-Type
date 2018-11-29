/*
** EPITECH PROJECT, 2-118
** r-type_server
** File description:
** Created by hexa,
*/

#include "Network/StreamBuffer/UDPServerStreamBuffer.hpp"

UDPServerStreamBuffer::UDPServerStreamBuffer()
	: AStreamBuffer()
{}

void UDPServerStreamBuffer::write(struct UDPServerStreamBufferData &data)
{
	AStreamBuffer::write(data.index);
	AStreamBuffer::write(data.spriteX);
	AStreamBuffer::write(data.spriteY);
	AStreamBuffer::write(data.spriteWidth);
	AStreamBuffer::write(data.spriteHeight);
	AStreamBuffer::write(data.x);
	AStreamBuffer::write(data.y);

}

struct UDPServerStreamBufferData UDPServerStreamBuffer::read(std::size_t size)
{
	struct UDPServerStreamBufferData data = {-1, -1, -1, -1, -1, -1, -1};

	_streamBuffer.commit(size);
	_iStream.read(reinterpret_cast<char *>(&data.index), sizeof(int));
	_iStream.read(reinterpret_cast<char *>(&data.spriteX), sizeof(int));
	_iStream.read(reinterpret_cast<char *>(&data.spriteY), sizeof(int));
	_iStream.read(reinterpret_cast<char *>(&data.spriteWidth), sizeof(int));
	_iStream.read(reinterpret_cast<char *>(&data.spriteHeight), sizeof(int));
	_iStream.read(reinterpret_cast<char *>(&data.x), sizeof(int));
	_iStream.read(reinterpret_cast<char *>(&data.y), sizeof(int));
	return (data);
}