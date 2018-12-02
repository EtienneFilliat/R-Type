/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** frame sending system
*/

#include "FrameSendingSystem.hpp"
#include "Components/Drawable.hpp"

Ecs::FrameSendingSystem::FrameSendingSystem(
	std::list<std::shared_ptr<Entity>> &entities)
	: ASystem(entities)
{
}

void Ecs::FrameSendingSystem::run()
{

	for (auto &entity : _Entities) {
		if (entity.get()->hasComp<Drawable>())
			drawThisEntity(entity);
	}
}

void Ecs::FrameSendingSystem::drawThisEntity(std::shared_ptr<Entity> entity)
{

}
