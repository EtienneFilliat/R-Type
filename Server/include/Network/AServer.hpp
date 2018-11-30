/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#ifndef R_TYPE_SERVER_ASERVER_HPP
#define R_TYPE_SERVER_ASERVER_HPP

#include "Components/IServerComponent.hpp"

class AServer {
public:
	virtual ~AServer() = default;
	void addComponent(std::unique_ptr<IServerComponent> &);

protected:
	std::map<int, std::unique_ptr<IServerComponent>> _components;
};

#endif //R_TYPE_SERVER_ASERVER_HPP
