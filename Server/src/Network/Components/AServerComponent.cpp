/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#include "Network/Components/AServerComponent.hpp"

AServerComponent::AServerComponent(int command)
	: _command(command)
{}

int AServerComponent::getCommand() const noexcept
{
	return (_command);
}