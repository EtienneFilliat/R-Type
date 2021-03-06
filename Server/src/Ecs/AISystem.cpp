/*
** EPITECH PROJECT, 2018
** R-Type
** File description:
** AISystem for R-Type
*/

#include <cmath>
#include "AISystem.hpp"
#include "EntityManager.hpp"
#include "Components/HitBox.hpp"
#include "Components/Damages.hpp"
#include "Components/Health.hpp"
#include "Components/AI.hpp"
#include "Components/Position.hpp"
#include "Components/Weapon.hpp"
#include "Components/Acceleration.hpp"

Ecs::AISystem::AISystem(std::list<std::shared_ptr<Entity>> &entities)
	: ASystem(entities)
{}

void Ecs::AISystem::run()
{
	int AInumber = countAIs();
	while (AInumber < Constants::MonsterNumber) {
		_Entities.push_back(EntityManager::createMonster(_Entities.size()));
		AInumber++;
	}
	for (auto &entity : _Entities) {
		if (entity.get()->hasComps<AI, Position, Acceleration>()) {
			moveAI(entity);
		}
	}
}

int Ecs::AISystem::countAIs()
{
	int count = 0;
	for (auto &entity : _Entities) {
		if (entity.get()->hasComp<AI>())
			count++;
	}
	return count++;
}

void Ecs::AISystem::moveAI(std::shared_ptr<Entity> entity)
{
	if (entity.get()->getComp<AI>()->getAIPattern() == 1)
		AIPattern1(entity);
	else
		AIPattern2(entity);
}

void Ecs::AISystem::AIPattern1(std::shared_ptr<Entity> entity)
{
	std::pair<int, int> pos = entity.get()->getComp<Position>()->getPosition();
	entity.get()->getComp<Position>()->setXPos(
		pos.first - entity.get()->getComp<Acceleration>()->getAcceleration());
}

void Ecs::AISystem::AIPattern2(std::shared_ptr<Entity> entity)
{
	std::pair<int, int> pos = entity.get()->getComp<Position>()->getPosition();
	entity.get()->getComp<Position>()->setXPos(
		pos.first - entity.get()->getComp<Acceleration>()->getAcceleration());
	entity.get()->getComp<Position>()->setYPos(
		Constants::DefaultMonsterPosY + (std::sin(pos.first / 30) * 50));
}