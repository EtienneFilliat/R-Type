/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#include "Network/AServer.hpp"

void AServer::addComponent(std::unique_ptr<IServerComponent> &component)
{
	_components[component->getCommand()] = std::move(component);
}