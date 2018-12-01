/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** frame sending system
*/

#include "FrameSendingSystem.hpp"

Ecs::FrameSendingSystem::FrameSendingSystem(
	std::list<std::shared_ptr<Entity>> &entities)
	: ASystem(entities)
{}

void Ecs::FrameSendingSystem::run()
{
	for (auto &entity : _Entities) {
	}
}

