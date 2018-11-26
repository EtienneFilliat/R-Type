/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#include "Network/AStreamBuffer.hpp"

AStreamBuffer::AStreamBuffer()
	: _oStream(&_streamBuffer), _iStream(&_streamBuffer)
{}

void AStreamBuffer::write(int i)
{
	_oStream.write(reinterpret_cast<char *>(&i), sizeof(int));
}

void AStreamBuffer::write(const std::string &str)
{
	_oStream.write(str.c_str(), str.size());
}

boost::asio::streambuf &AStreamBuffer::getStreamBuffer()
{
	return (_streamBuffer);
}