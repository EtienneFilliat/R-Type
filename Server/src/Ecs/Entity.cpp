/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** Entity source code
*/

#include <memory>
#include "Entity.hpp"

Ecs::Entity::Entity(unsigned int id)
	: _id(id)
{};

Ecs::Entity::~Entity()
{}


unsigned int Ecs::Entity::getEntityId() noexcept
{
	return _id;
}
