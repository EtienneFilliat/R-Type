/*
** EPITECH PROJECT, 2018
** r-type_server
** File description:
** Created by hexa,
*/

#ifndef R_TYPE_SERVER_LOBBY_HPP
#define R_TYPE_SERVER_LOBBY_HPP

#include <list>
#include "Player.hpp"

struct Lobby {
	std::string &name;
	std::list<struct Player> players;
};

#endif //R_TYPE_SERVER_LOBBY_HPP
