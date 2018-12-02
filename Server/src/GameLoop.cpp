/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** game loop
*/

#include "GameLoop.hpp"

GameLoop::GameLoop(std::list<std::shared_ptr<Ecs::Entity>> list)
	: _hitboxSystem(list),
	_frameSendingSystem(list),
	_AISystem(list)
{}

