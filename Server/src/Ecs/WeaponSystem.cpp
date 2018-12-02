/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** weaponSystem
*/

#include "Components/Weapon.hpp"
#include "Components/Position.hpp"
#include "Components/Acceleration.hpp"
#include "WeaponSystem.hpp"

Ecs::WeaponSystem::WeaponSystem(std::list<std::shared_ptr<Entity>> &entities)
	: ASystem(entities)
{}

void Ecs::WeaponSystem::run()
{
	for (auto &entity : _Entities) {
		if (entity.get()->hasComps<Weapon, Position, Acceleration>())
			moveMissile(entity);
	}
}

void Ecs::WeaponSystem::moveMissile(std::shared_ptr<Entity> entity)
{
	std::pair<int, int> pos = entity.get()->getComp<Position>()->getPosition();
	entity.get()->getComp<Position>()->setXPos(pos.first +
		entity.get()->getComp<Acceleration>()->getAcceleration());
}